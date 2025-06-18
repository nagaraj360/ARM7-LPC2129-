#include <LPC21xx.H>
#include"header.h"
void lcd_data(unsigned char data)
{
IOCLR1=0XFE<<16;
IOSET1=((data&0xF0)<<16);
IOSET1=1<<17;						 
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;

IOCLR1=0XFE<<16;
IOSET1=(data & 0x0F)<<20;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
}

void lcd_cmd(unsigned char cmd)
{
IOCLR1=0XFE<<16;
IOSET1=(cmd &0xF0)<<16;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;

IOCLR1=0XFE<<16;
IOSET1=(cmd & 0x0F)<<20;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
}

void lcd_init()
{
IODIR1=0XFE<<16;
PINSEL2=0X0;
IOCLR1=1<<19;
lcd_cmd(0x80);
lcd_cmd(0x02);
lcd_cmd(0x03);
lcd_cmd(0x28);

lcd_cmd(0x0e);
lcd_cmd(0x01);
}

void lcd_string(char *ptr)
{
while(*ptr)
{
lcd_data(*ptr);
ptr++;
}

}

void lcd_cgram(void){
int i;
unsigned char a[8]={0x00,0xA,0XA,0X0,0X0,0X11,0X0E,0X0};
lcd_cmd(0X48);
for(i=0;i<8;i++){
lcd_data(a[i]);
}
}
