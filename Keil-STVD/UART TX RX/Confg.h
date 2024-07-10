typedef unsigned char uchar;

#define CLK_CKDIVR  *(uchar *) (0x0050C6)
#define CLK_PCKENR1 *(uchar *) (0x0050C7)
#define UART1_BRR1  *(uchar *) (0x005232)
#define UART1_BRR2  *(uchar *) (0x005233)
#define UART1_CR1   *(uchar *) (0x005234)
#define UART1_CR2   *(uchar *) (0x005235)
#define UART1_CR3   *(uchar *) (0x005236)
#define UART1_SR    *(uchar *) (0x005230)
#define UART1_DR    *(uchar *) (0x005231)

void _UART_RESET (void);
void _UART_SET (void);
void _UART_TX (uchar data);
uchar UART_RX_uch (void);