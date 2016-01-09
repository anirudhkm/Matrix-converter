#include<p18f4550.h>
#include<delays.h>
#pragma config FOSC = HS
void main(void)
{
TRISA=0b00111111;//Rectifier
TRISB=0b00000000;//Matrix
TRISC=0b00000000;//Matrix last pin
TRISD=0b00111111;//Inverter
TRISE=0x00;
while(1)
{
LATBbits.LATB1=(PORTAbits.RA0*PORTDbits.RD0)+(PORTAbits.RA1*PORTDbits.RD1);
LATBbits.LATB2=(PORTAbits.RA0*PORTDbits.RD2)+(PORTAbits.RA1*PORTDbits.RD3);
LATBbits.LATB3=(PORTAbits.RA0*PORTDbits.RD4)+(PORTAbits.RA1*PORTDbits.RD5);
LATBbits.LATB4=(PORTAbits.RA2*PORTDbits.RD0)+(PORTAbits.RA3*PORTDbits.RD1);
LATBbits.LATB5=(PORTAbits.RA2*PORTDbits.RD2)+(PORTAbits.RA3*PORTDbits.RD3);
LATBbits.LATB6=(PORTAbits.RA2*PORTDbits.RD4)+(PORTAbits.RA3*PORTDbits.RD5);
LATBbits.LATB7=(PORTAbits.RA4*PORTDbits.RD0)+(PORTAbits.RA5*PORTDbits.RD1);
LATCbits.LATC0=(PORTAbits.RA4*PORTDbits.RD2)+(PORTAbits.RA5*PORTDbits.RD3);
LATCbits.LATC1=(PORTAbits.RA4*PORTDbits.RD4)+(PORTAbits.RA5*PORTDbits.RD5);
}
}
