/** Programa baseado no codigo disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

// Ajustando o PWM por HARDWARE na Raspberry Pi

#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {                            // este programa deve ser rodado com 'sudo'
   int dc, ciclos, c1, c2;
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // Ajustando a frequencia do PWM em 10kHz com 128 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 262.2 = 19200000 / (divisor * 256) => divisor = 286
   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(256);                    // passos do duty cycle (max=4096)
   pwmSetClock(286);                     // fornece uma frequencia de 10kHz (max=4096)
   printf("Iniciando...\n");
   for(ciclos = 0; ciclos < 2; ciclos++){  // variando o duty cycle
      //for(dc = 0; dc < 128; dc++){
      //   pwmWrite(pino_PWM0, dc);
      //   usleep(10000);
      //}

     for(c1 = 0; c1 < 3; c1++){
     	pwmWrite(pino_PWM0,128);
     	usleep(150000);
     	pwmWrite(pino_PWM0,0);
     	usleep(150000);
	}

     usleep(500000);

     for(c2 = 0; c2 < 2;c2++){
        pwmWrite(pino_PWM0,128);
	usleep(150000);
	pwmWrite(pino_PWM0,0);
	usleep(150000);
	}

     usleep(2000000);

   }
   printf("Fim.\n");
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}
