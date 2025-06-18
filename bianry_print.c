#include <LPC21xx.H>
#include"header.h"
main()
{
unsigned char temp;
int num=0;
uart0_init(9600);
uart_tx_string("\r\nenter the number\r\n");
while(1){
temp=uart0_rx();
if(temp!='\r')
num=num*10+(temp-48);
else
{
uart0_tx_string("\r\n Binary: ");
uart0_binary(num);
uart0_tx_string("\r\n enetr the num \r\n ");
num=0;
}
}
}
