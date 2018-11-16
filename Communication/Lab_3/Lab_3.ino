void setup() {
  // put your setup code here, to run once:

  UCSR0A = 0x00; //0000 0000  because dont need any functionality, U2X0 = 0 for use later
  UCSR0B = 0x98; //1001 1000  Receiver enable, Transmitter enable, Rx interrupt enabled (RXCIE0), UCSZ02 = 0 from 011 8-bits
  UCSR0C = 0x06; //0000 0110  00:Asynchronous; 00:Disable Parity; 0:1 stop bit; 11:8-bit; 0:asynchronous
  UBRR0 = 16; //              U2X0 = 0 so for baud rate of 57,600 UBBR0 = 16

  /*
  DDRD = 0x00;   //0000 0000
  PCICR = 0x04;  //0000 0100  Enables PCIE2 for pins [23:16]
  PCMSK2 = 0x04; //0000 0100  Enables PCINT18
  */
  
  DDRB = ( 1 << 5 ); //0010 0000 to make PB5 as output in DDB5

}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(PCINT2_vect) {
  unsigned char switch_val = ( PIND >> 2 ) & 0x01;
  if ( switch_val == 1 ) {
    UDR0 = 0x31;
  }
  else {
    UDR0 = 0x30;
  }
  
}

ISR(USART_RX_vect) {
  unsigned char udr_val = UDR0;
  if ( udr_val == 0x31 ) {
    PORTB |= (0x20);
  }
  else if ( udr_val == 0x30 )  {
    PORTB &= ~(0x20);
  }
  UDR0 = udr_val;
  
}

