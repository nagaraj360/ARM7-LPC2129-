/*______PASSWORD_AUTHENTICATION_USING_UART0________*/
#include <LPC21xx.H>
#include"header.h"
main()
{
char a[12],b[12]="raju";
int i;
uart0_init(9600);
while(1)
{
uart0_tx_string("enter the password\r\n");
uart0_rx_string(a,11);
for(i=0;b[i];i++)
uart0_tx('*');
for(i=0;b[i];i++)
{
if(b[i]!=a[i])
uart0_tx_string("\r\nwrong password");
break;
}
if(a[i]==b[i])
{
uart0_tx_string("\n\r correct password");
}
uart0_tx_string("\r\n");
}
}
