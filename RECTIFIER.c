//RA0--> s1, RA2--> s3, RA4--> s5,
//RA1--> s2, RA3--> s4, RA5--> s6
#include <18F4331.h>
#device adc=8
#FUSES HS                       //High speed Osc (> 4mhz)
#use delay(clock=20000000)
#byte porta=0xF80
#byte portb=0xF81
#byte portc=0xF82
#byte portd=0xF83
#byte porte=0xF84
#byte trisa=0xF92
#byte trisb=0xF93
#byte trisc=0xF94
#byte trisd=0xF95
#byte trise=0xF96
int i;
volatile int start=1;
const int b[200]={36,35,34,33,32,32,31,30,29,28,27,26,25,24,23,22,20,19,18,17,16,14,13, 18,16,15,14,13,11,10,9,7,6,5,3,2,1,0,0,0,1,2,3,5,6,7,9,10,11,13,14,15,16,18,19,20,25,24,23,22,21,20,18,17,16,15,14,12,11,10,8,7,6,4,3,2,0,0,0,0,1,3,4,5,7,8,9,11,12,13,14,16,17,18,19,20,22,23,24,25,26,27,28,29,30,31,32,32,33,34,35};
const int c[200] ={0,0,3,4,5,7,8,9,11,12,13,15,16,17,18,20,21,22,23,24,25,27,28,29,30,31,32,32,33,34,35,36,37,37,37,36,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,20,19,18,17,16,14,13,12,10,9,8,6,5,4,0,0,0,0,3,5,6,7,9,10,11,13,14,15,16,18,19,20,21,22,24,25,,22,21,20,19,18,16,15,14,13,11,10,9,7,6,5,3,0,0,0,0,4,5,6,8,9,10,12,13,14,16,17,18,19,20,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,36,37,37,37,36,35,34,33,32,32,31,30,29,28,27,25,24,23,22,21,20,18,17,16,15,13,12,11,9,8,7,5,4,3,0};
const int a[200] ={4,4,4,3,3,3,3,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,4,4,4,4,4,3,3,3,3,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4,4,3,3,3,2,2,2,2,2,2,2,1,1,1,1,1,1,1, 3,3,3,3,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4,4,3,3,3,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,4,4};
void main()
{
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
set_tris_a(0x00);
set_tris_b(0xFF);
set_tris_c(0xFF);
ext_int_edge(0,1);
while(1)
{
if(start==1)
{
disable_interrupts(INT_EXT);
SVM:
i=0;
while(i<=33 && i>=0)
{
output_a(0b001100);
delay_us(a[i]);
output_a(0b011000);
delay_us(b[i]);
output_a(0b001001);
delay_us(c[i]);
output_a(0b001100);
delay_us(d[i]);
output_a(0b001001);
delay_us(c[i]);
output_a(0b011000);
delay_us(b[i]);
output_a(0b001100);
delay_us(a[i]);
i++;
}
while(i<=60 && i>33)
{
output_a(0b000011);
delay_us(a[i]);
output_a(0b001001);
delay_us(b[i]);
output_a(0b100001);
delay_us(c[i]);
output_a(0b000011);
delay_us(d[i]);
output_a(0b100001);
delay_us(c[i]);
output_a(0b001001);
delay_us(b[i]);
output_a(0b000011);
delay_us(a[i]);
i++;
}
while(i<=100 && i>60)
{
output_a(0b110000);
delay_us(a[i]);
output_a(0b100001);
delay_us(b[i]);
output_a(0b100100);
delay_us(c[i]);
output_a(0b110000);
delay_us(d[i]);
output_a(0b100100);
delay_us(c[i]);
output_a(0b100001);
delay_us(b[i]);
output_a(0b110000);
delay_us(a[i]);
i++;
}
while(i<=133 && i>100)
{
output_a(0b001100);
delay_us(a[i]);
output_a(0b100100);
delay_us(d[i]);
output_a(0b000110);
delay_us(c[i]);
output_a(0b100100);
delay_us(b[i]);
output_a(0b001100);
delay_us(a[i]);
i++;
}
while(i<=166 &&   i>=133)
{
output_a(0b000011);
delay_us(a[i]);
output_a(0b000110);
delay_us(b[i]);
output_a(0b010010);
delay_us(c[i]);
output_a(0b000011);
delay_us(d[i]);
output_a(0b010010);
delay_us(c[i]);
output_a(0b000110);
delay_us(b[i]);

output_a(0b000011);
delay_us(a[i]);
i++;
}
while(i<200 && i>166)
{
output_a(0b110000);
delay_us(a[i]);
output_a(0b010010);
delay_us(d[i]);
output_a(0b011000);
delay_us(c[i]);
output_a(0b010010);
delay_us(b[i]);
output_a(0b110000);
delay_us(a[i]);
i++;
}
goto SVM;
}
}
}
