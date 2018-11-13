/*
// Program A
void NewDelay (unsigned long mSecondsApx); // Edit

void setup() {
  unsigned char *portDDRB;
  portDDRB = (unsigned char *) 0x24;
  *portDDRB |= 0x20;
}

void loop () {
  unsigned char *portB;
  portB = (unsigned char *) 0x25;
  
  *portB |= 0x20;
  NewDelay(100);
  *portB &= 0xDF; // Edit
  NewDelay(100);
}


void NewDelay (unsigned long mSecondsApx) {
  volatile unsigned long i; // Edit
  unsigned long endTime = 2000 * mSecondsApx; // Edit
  for (i = 0; i < endTime; i++);
}
*/



/*
// Program B.
void NewDelay (unsigned long mSecondsApx);

void setup() {
  unsigned char *portDDRB;
  portDDRB = (unsigned char *) 0x24;
  *portDDRB |= 0x20;
}

void loop () {
  unsigned char *portB;
  portB = (unsigned char *) 0x25;
  *portB |= 0x20;
  NewDelay (100);
  *portB &= 0xDF;
  NewDelay (100);
}

void NewDelay (unsigned long mSecondsApx) {
  volatile unsigned long i;
  unsigned long j; // Edit
  unsigned long k;
  unsigned long endTime = 100 * mSecondsApx;
  for (i = 0; i < endTime; i++) {
    j = 10;
    do {
      j = j - i;
      k = i / j;
    } 
    while (k > 0);
  }
}
*/




// Program C.
void NewDelay (unsigned long mSecondsApx);

void setup() {
  unsigned char *portDDRB;
  portDDRB = (unsigned char *) 0x24;
  *portDDRB |= 0x20;
}

void loop () {
  unsigned char *portB;
  portB = (unsigned char *) 0x25;
  *portB |= 0x20;
  NewDelay (100);
  *portB &= 0xDF;
  NewDelay (100);
}

void NewDelay (unsigned long mSecondsApx) {
  volatile unsigned long i;
  unsigned char j = 0;
  unsigned long endTime = 1000 * mSecondsApx; // Edit
  i= 0;
  while (j == 0) { // Edit
    i++;
    if (i >= endTime) { // Edit
      j = 1;
    }
  }
}

