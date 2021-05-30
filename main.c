#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
/*==========================================================================*/

void InitialUART0_Timer3(UINT32 u32Baudrate) //use timer3 as Baudrate generator
{
 P06_Quasi_Mode;    //Setting UART pin as Quasi mode for transmit
 P07_Input_Mode;   //Setting UART pin as input mode for recieve    
 SCON = 0x50;      //UART0 Mode1,REN=1,TI=1
 set_SMOD;        //UART0 Double Rate Enable
 T3CON &= 0xF8;  //T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1)
 set_BRCK;      //UART0 baud rate clock source = Timer3
#ifdef FOSC_160000
RH3= HIBYTE(65536 - (1000000/u32Baudrate)-1);      /*16 MHz */
RL3= LOBYTE(65536 - (1000000/u32Baudrate)-1);     /*16 MHz */
#endif
#ifdef FOSC_166000
  RH3= HIBYTE(65536 - (1037500/u32Baudrate));      /*16.6 MHz */
  RL3 = LOBYTE(65536 - (1037500/u32Baudrate));     /*16.6 MHz */
#endif
 set_TR3;      //Trigger Timer3
 set_TI;     //For printf function must setting TI = 1
}




void main (void)
{
             //char oper;
	
	Timer0_Delay1ms(300);
	Timer0_Delay1ms(300);
	Timer0_Delay1ms(300);
	
             InitialUART0_Timer3(9600);
     ///* 
	TI = 1;       // prinft function is used.
             printf("Hello CircuitDigest\r\n");           
             while(1)
             {            
                         printf("\r\nPress 1 or Press 2 or Press 3 or Press 4");
                         Timer0_Delay1ms(300);
             }
						 //*/
}
