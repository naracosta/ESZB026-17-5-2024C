#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GPIO_NUMBER_Y "16"
#define GPIO_NUMBER_R "20"
#define GPIO_NUMBER_G "21"

#define GPIO4_PATH_Y "/sys/class/gpio/gpio16/"
#define GPIO4_PATH_R "/sys/class/gpio/gpio20/"
#define GPIO4_PATH_G "/sys/class/gpio/gpio21/"

#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(char filename[], char value[]){
   FILE* fp;                           // cria um ponteiro fp
   fp = fopen(filename, "w+");         // abre o arquivo para escrita
   fprintf(fp, "%s", value);           // grava o valor no arquivo
   fclose(fp);                         // fecha o arquivo
}

int main(int argc, char* argv[]){
  
  writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER_Y);
  writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER_R);
  writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER_G);

  writeGPIO(GPIO4_PATH_Y "direction", "out");
  writeGPIO(GPIO4_PATH_R "direction", "out");
  writeGPIO(GPIO4_PATH_G "direction", "out");

  int i=0;
  while (i < 5){
    writeGPIO(GPIO4_PATH_R "value", "1");
    usleep(200000); 
    writeGPIO(GPIO4_PATH_R "value", "0");

    writeGPIO(GPIO4_PATH_G "value", "1");
    usleep(100000); 
    writeGPIO(GPIO4_PATH_G "value", "0");
    
    writeGPIO(GPIO4_PATH_Y "value", "1");
    usleep(100000); 
    writeGPIO(GPIO4_PATH_Y "value", "0");
    
    i++;
  }  

  writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER_Y);
  writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER_R);
  writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER_G);
  
}