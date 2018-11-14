// Mayank Vanjani
// Lab 2: Embedded
// 10/19/18

/* // Setting Up Analog Signal on Serial Plotter
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float aval;
  long x;
  x = millis();
  aval = abs(3 * sin(2 * 3.141592654 * x / 1000));
  delay(1);
  Serial.println(aval);
}
*/

/*
// Setting up the PWM Signal
void setup() {
  // PWM Output of frequency 1kHz and duty cycle porportional to aval
  // Fast PWM Mode and output on Aruino pin 5 (PD5)
  Serial.begin(9600);
  DDRD = (1 << 5);  
  OCR0A = 250;
  // OCR0B = ;
  TCCR0A = 0x23; // 0010 0011 => Channel A = 00 (disconnected)     Channel B = 10 (clear on comp match)
                 // 00 for extra useless bits                      WGM01,02 = 11 (Fast PWM with top 111)
  TCCR0B = 0x03; // 0000 0111 => FOC0A,0B = 00 (Force output compare = 0)   00 for extra useless bits
                 // WGM02 = 0 (from 011 Fast PWM upto 0xFF)                CSO0,1,2 = 011 (clock / 64)
}

void loop() {
  float aval;
  long x;
  x = millis();
  aval = abs(3 * sin(2 * 3.141592654 * x / 1000));
  OCR0B = (250 * aval / 3);       // since duty cycle depends on aval
  
}
*/


void setup() {
  Serial.begin(9600);
  // Timer from before
  DDRD = (1 << 5);    // 0010 0000     For PD5 = 1 (output)
  OCR0A = 250;
  // OCR0B = 125;
  TCCR0A = 0x23;
  TCCR0B = 0x03;

  // ADC
  DDRC = 0;           // 0000 0000      For PC0 = 0 (input) of A0 pin
  ADMUX = (1 << 6);   // 0100 0000      For REFS0 = 1; REFS0,1 = 01 uses AVcc and MUX3,2,1,0 = 0000 using ADC0
  ADCSRA = 0xC6;      // 1100 0110      ADEN = 1; ADSC = 1; ADATE = 0; ADIF,ADIE = 00; ADPS = 110 (64 prescale)
  ADCSRB = 0x00;      // 0000 0000      Free Running Mode
  DIDR0 = 0x01;       // 0000 0001      To Turn ADC A0 to output 
  
}

void loop() {
  ADCSRA |= 0x40;
  while (ADSC == 1) {
    delay(1);
  }
  
  float aval;
  long x;
  x = millis();
  aval = abs(3 * sin(2 * 3.141592654 * x / 1000));
  OCR0B = 250 * aval / 3;
  delay(1);
  //Serial.print( abs(aval) );

  //ADLAR = 0:
  unsigned short *ADCData; 
  unsigned short ADCVal;
  ADCData = (unsigned short *) 0x78;    // Address
  ADCVal = ( *ADCData & 0x03FF ); // 0000 0011 1111 1111

  // float fADCVal = (float) ((float(ADCVal) / 1023) * 3);
  float fADCVal;
  fADCVal = ((float)ADCVal)/1023 * 3;
  //Serial.println(ADCVal);


  //Serial.print( "aval: ");
  //Serial.print(abs(aval)); //Original rectified sinusoid
  Serial.print(" ");
  //Serial.print( "fADCVal: ");
  Serial.println(fADCVal); //Analog voltage measured from ADC
  // delay(500);
  //analogRead(A0);
  
}

