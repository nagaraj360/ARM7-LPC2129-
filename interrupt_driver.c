#include <LPC21xx.H>
#include"header.h"
extern u32 flag,i,num;
extern s8 arr[13];
void uart0_handler(void)__irq
{
num=U0IIR&0X0E;
if(num==0x04)
{
arr[i++]=U0RBR;
}
if(arr[i-1]=='\r')
{
arr[i-1]='\0';
flag=1;
i=0;
}
if(num==0x02)
{
}
VICVectAddr=0;
}
void config_Vic_for_uart0(void)
{
VICIntSelect=0;
VICVectAddr0=(u32)uart0_handler;
VICVectCntl0=6|(1<<5);
VICIntEnable|=1<<6;
}
void en_uart0_interrupt(void){
U0IER=3;
}
