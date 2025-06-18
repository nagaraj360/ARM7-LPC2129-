#include <LPC21xx.H>
#include"header.h"
main()
{
int i;
uart0_init(9600);
while(1){
for(i=0;i<26;i++)
{
uart0_tx('A'+i);
delay_ms(100);
}
}
}
