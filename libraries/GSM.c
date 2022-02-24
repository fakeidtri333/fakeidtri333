viod at()
{
sendstring_uart("AT");
LCDGotoXY(0,0);
LCDdisplay("AT");
_delay_ms(100);
sendchar_uart(0x0D);
_delay_ms(300);
}


void atread()
{
sendstring_uart("AT+CMGR=1");
LCDGotoXY(0,0);
LCDdisplay("AT+CMGR=1");
_delay_ms(100);
sendchar_uart(0x0D);
_delay_ms(300);
}


void atdelete()
{
sendstring_uart("AT+CMGD=1");
LCDGotoXY(0,0);
LCDdisplay("AT+CMGD=1");
_delay_ms(100);
sendchar_uart(0x0D);
_delay_ms(300);
}


void echo()
{
sendstring_uart("ATE0");
LCDGotoXY(0,0);
LCDdisplay("ATE0");
_delay_ms(100);
sendchar_uart(0x0D);
_delay_ms(300);
}