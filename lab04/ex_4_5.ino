const int analogInPin = A0;                  // o potenciômetro esta ligado ao pino A0

void setup(){
   // Configura a serial: baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
}

void loop(){
   int valor = analogRead(analogInPin);      // le valor no pino A0 usando conversor ADC de 10-bit
   valor = valor * (100.0f/1023.0f);
   Serial.write(valor);
   //Serial.println(valor);
   delay(100);
}
