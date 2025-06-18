/*__________UART_DRIVER.C____________*/

#include <LPC21xx.H>
#include"header.h"
void uart0_init(unsigned int baud)
{
int a[]={15,60,30,15,15};
unsigned int pclk,result=0;
pclk=a[VPBDIV]*1000000;
result=pclk/(16*baud);
PINSEL0|=0X5;
U0LCR=0X83;
U0DLL=result&0xFE;
U0DLM=(result>>8)&0xFE;
U0LCR=0X03;
															   
}
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}

void uart0_tx_string(char *ptr)
{
while(*ptr)
{
U0THR=*ptr;
while(THRE==0);
ptr++;
}
}

#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}
void uart0_rx_string(char *p,int size)
{
int i;
for(i=0;i<size;i++)
{
while(RDR==0);
p[i]=U0RBR;
if(p[i]=='\r')
break;
}
p[i]=0;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
void uart0_binary(int num)
{
int pos,temp;
for(pos=7;pos>=0;pos--)
{
temp=(((num>>pos)&1)+48);
uart0_tx(temp);
}
}


void uart0_tx_integer(int num){
int a[10],i;

if(num==0){
uart0_tx('0');
}
i=0;

if(num<0){
a[i]=(num%10)+48;
i++;
num=num/10;
}

while(num>0){
a[i]=num%10+48;
num=num/10;
i++;
}
for(i=i-1;i>=0;i--)
uart0_tx(a[i]);
}

void uart0_tx_float(float f)
{
unsigned int i;
i=f;
uart0_tx_integer(i);
uart0_tx('.');
i=(f-i)*100;
uart0_tx_integer(i);
}
