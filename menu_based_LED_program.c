//  menu based LED program
#include <LPC21xx.H>
#include"header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)
main()
{
unsigned char cmd1;
IODIR0 |= LED1|LED2;
IOSET0=LED1|LED2;
uart0_init(9600);
uart0_tx_string("\r\n Menu");
uart0_tx_string("\r\n a.LED1 ON");
uart0_tx_string("\r\n b.LED1 OFF");
uart0_tx_string("\r\n c.LED2 ON");
uart0_tx_string("\r\n d.LED2 OFF");
uart0_tx_string("\r\n E.LED1&LED2 ON");
uart0_tx_string("\r\n f.LED1&LED2 OFF");
uart0_tx_string("\r\n option.....");
while(1){
cmd1=uart0_rx();
uart0_tx(cmd1);
switch(cmd1)
	{
		case 'a': IOCLR0=LED1;break;
		case 'b': IOSET0=LED1;break;
		case 'c': IOCLR0=LED2;break;
		case 'd': IOSET0=LED2;break;
		case 'e': IOCLR0=LED1|LED2;break;
		case 'f': IOSET0=LED1|LED2;break;
}
}
}
