void MyDelay (unsigned long mSecondsApx);

void setup () {
  unsigned char *portDDRB;
  portDDRB = (unsigned char *) 0x24;
  *portDDRB |= 0x20;
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
}

void loop () {
  unsigned char *portB;
  portB = (unsigned char *) 0x25;

  /*
  // Blinking Light (9 bytes used)
  *portB |= 0x20;
  MyDelay(1000);
  *portB &= 0xDF;
  MyDelay(1000);
  */

  /*
  // Blinking Lights (9 bytes used)
  *portB |= 0x20;
  delay(100);
  *portB &= 0xDF;
  delay(1000);

  *portB |= 0x20;
  delay(100);
  *portB &= 0xDF;
  delay(100);
  *portB |= 0x20;
  delay(100);
  *portB &= 0xDF;
  delay(1000);

  *portB |= 0x20;
  delay(100);
  *portB &= 0xDF;
  delay(100);
  *portB |= 0x20;
  delay(100);
  *portB &= 0xDF;
  delay(100);
  *portB |= 0x20;
  delay(100);
  *portB &= 0xDF;
  delay(1000);
  */

  
  digitalWrite(13, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(13, LOW);
  Serial.println("LED OFF");
  delay(1000);
  // Output is LED ON, LED OFF, LED ON, LED OFF... in new lines
  
  
}

void MyDelay (unsigned long mSecondsApx) {
  volatile unsigned long i;
  unsigned long endTime = 1000 * mSecondsApx;

  for (i = 0; i < endTime; i++);
}

