extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);
//// lcd_driver
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(char *ptr);
extern void lcd_cgram(void);


///     TYPEDEF
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;
typedef unsigned char u8;
///// uart0_driver
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern void uatr0_tx_string(char *ptr);
extern unsigned char uart0_rx(void);
extern void uart0_rx_string(char *,int size);


extern void uart0_binary(int num);
extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float f);

//// adc
extern void adc_init(void);
extern unsigned int adc_read(unsigned char ch_num);


// interrupt
extern void uart0_Handler(void)__irq;
extern void config_Vic_for_uart0(void);
extern void en_uart0_interrupt(void);



