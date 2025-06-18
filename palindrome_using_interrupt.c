#include <LPC21xx.H>
#include "header.h"
u32 flag,i,num,temp;
char arr[13];
main()
{
u32 i,j,l;
uart0_init(9600);
en_uart0_interrupt();
config_Vic_for_uart0();
	uart0_tx_string("\r\nenter the string:");
while(1)
{
if(flag==1)
{
flag=0;
	uart0_tx_string(arr);
	for(l=0;arr[l];l++);
	for(i=0,j=l-1;i<l;i++,j--)
	{
	if(arr[i]!=arr[j])
		break;
	}
	if(arr[i]==arr[j])
		uart0_tx_string("\r\npalindrome");
	else
		uart0_tx_string("\r\nnot palindrome");
	uart0_tx_string("\r\n");
}
}
}
