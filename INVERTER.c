#include<p18f4331.h>
#include<delays.h>
#pragma config OSC=HS
volatile int start=1,i=0x00;
#pragma romdata 
#duty cycle 1 table
rom int dutycycle1H[200]={3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
dutycycle1L[200]={160,168,176,184,188,196,200,204,208,212,216,220,224,224, 172,180,188,192,200,204,208,212,216,220,220,224,224,228,228,228,228,228,224,224,220,220,216,212,208,204,200,192,188,180,172,168,164,172,180,184,192,196,200,208,212,216,220,220,224,224,228,228,228,228,228,228,224,224,220,216,212,208,204,200,196,188,184,176,168,160,168,176,184,188,196,200,204,208,212,216,180,172,164,168,172,180,188,192,200,204,208,212,216,220,220,224,224,228, 180,184,192,196,200,208,212,216,220,220,224,224,228,228,228,228,228,228,224,224,220,216,212,208,204,200,196,188,184,176,168},
#duty cycle 2 table
dutycycle2H[200]={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1, 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,},
dutycycle2L[200]={68,92,116,140,164,188,216,240,12,36,64,88,116,144,168,196,224,252,24,48,76,104,128,156,184,208,236,4,32,56,80,104,128,152,144,120,96,7288,64,40,12,244,216,192,164,140,112,84,60,32,4,232,204,180,152,124,100,72,44,20,248,224,196,172,148,124,100,76,84,108,132,156,180,204,232,0,28,52,80,108,132,160,188,216,244,12,40,68,96,120,148,176,200,228,252,24,48,72,96,120,144,152,128,104,80,56,32,4,236,208,184,156,128,104,76,48,24,252,224,196,168,144,116,88,64,36,12,240,216,188,164,140,116,92},
#pragma romdata
void main(void)
 {  
 	//OSCCON=0x77;//Fosc=8MHz
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	INTCONbits.INT0IE=1;
	INTCON2bits.INTEDG0=1;
	PIE3bits.PTIE=1;
	//PDC0H=1;	//PDC1H=0;	//PDC2H=0; 
	TRISB=0x00;
	PTPERH=0x00;
	PTPERL=0xFA;
	PTCON1=0x00;//reset PTEN in PTCON1 before changing PTMOD in PTCON0
	PTCON0=0b00000010;//continuous up down mode
	PTCON1=0b11000000;
	PWMCON0=0b01010000;
	PWMCON1=0x01;
	DTCON=0b00010100;
while(1)
{
if(start==1)
{
INTCONbits.INT0IE=0;//disable ZCD interrupt
PTMRH=PTPERH;
PTMRL=PTPERL;
SVM:
while(i<=33)
{
PDC0H=dutycycle1H[i];
PDC0L=dutycycle1L[i];//1
PDC1H=dutycycle2H[i];
PDC1L=dutycycle2L[i];//2
PDC2H=dutycycle3H[i];
PDC2L=dutycycle3L[i];//3
}
while(i<=100)
{
PDC0H=dutycycle3H[i];
PDC0L=dutycycle3L[i];//3
PDC1H=dutycycle1H[i];
PDC1L=dutycycle1L[i];//1
PDC2H=dutycycle2H[i];
PDC2L=dutycycle2L[i];//2
}
while(i<=133)
{
PDC0H=dutycycle3H[i];
PDC0L=dutycycle3L[i];//3
PDC1H=dutycycle2H[i];
PDC1L=dutycycle2L[i];//2
PDC2H=dutycycle1H[i];
PDC2L=dutycycle1L[i];//1
}
while(i<=166)
{
PDC0H=dutycycle2H[i];
PDC0L=dutycycle2L[i];//2
PDC1H=dutycycle3H[i];
PDC1L=dutycycle3L[i];//3
PDC2H=dutycycle1H[i];
PDC2L=dutycycle1L[i];//1
}
while(i<200)
{
PDC0H=dutycycle1H[i];
PDC0L=dutycycle1L[i];//1
PDC1H=dutycycle3H[i];
PDC1L=dutycycle3L[i];//3
PDC2H=dutycycle2H[i];
PDC2L=dutycycle2L[i];//2
}
goto SVM;
}
}
}
