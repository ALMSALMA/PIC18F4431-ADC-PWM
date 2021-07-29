#include "mcc_generated_files/mcc.h"
#include "lcd.h"
#include "stdio.h"

uint16_t convertedValue = 0;
float  volt ;
char VOLTAGE[20];

void main(void)
{
    SYSTEM_Initialize();
    LCD_Initialize();
    LCDPutCmd(LCD_CURSOR_OFF);
 
    while (1)
    {
        convertedValue = 0;     
      ADC_StartConversion(channel_AN0);
      while(!ADC_IsConversionDone());
        convertedValue = ADC_GetConversionResult(); 
       
       volt = (convertedValue * 5.0)/1023; // convert ADC count into voltage
       LCDPutStr("Voltage = "); 
       sprintf(VOLTAGE, " %.3g", volt ); 
       LCDPutStr(VOLTAGE);
       LCDGoto(0,0); 
       
       PWM2_LoadDutyValue(convertedValue);      
     }
}
