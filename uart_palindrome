
/* ________________main code________________ */
#include <LPC21xx.H>
#include "header.h"
main()
{
	u8 a[13];
	u32 i,j,l;
	uart0_init(9600);
	while(1)
	{
		uart0_tx_string("\r\n enter the string");
		uart0_rx_string(a,12);
		uart0_tx_string("\r\n");
		uart0_tx_string(a);
		for(l=0;a[l];l++);
		for(i=0,j=l-1;i<l;i++,j--)
		{
			if(a[i]!=a[j])
			{
				uart0_tx_string("\r\n not palindrome");
				break;
			}
		}	
		if(a[i]==a[j])
		uart0_tx_string("\r\n palindrome");
	}
}
