/*
 * Abin Abraham
 * HC 06 Bluetooth
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#include "D:/Embedded Systems/Tivaware C series/inc/hw_ints.h"
#include "D:/Embedded Systems/Tivaware C series/inc/hw_types.h"
#include "D:/Embedded Systems/Tivaware C series/inc/hw_memmap.h"

#include "D:/Embedded Systems/Tivaware C series/driverlib/sysctl.h"
#include "D:/Embedded Systems/Tivaware C series/driverlib/gpio.h"
#include "D:/Embedded Systems/Tivaware C series/driverlib/pin_map.h"
#include "D:/Embedded Systems/Tivaware C series/driverlib/uart.h"

void bluetoothSendMessage(char *array);

/* HC06 BLUETOOTH
 * TX-->PC6
 * RX-->PC7*/

int main(void)
{
    unsigned char data;
    int LED;

    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    //HC06 BLUETOOTH Pinleri
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    GPIOPinConfigure(GPIO_PC6_U3RX);
    GPIOPinConfigure(GPIO_PC7_U3TX);
    GPIOPinTypeUART(GPIO_PORTC_BASE,GPIO_PIN_6|GPIO_PIN_7);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
    UARTConfigSetExpClk(UART3_BASE,SysCtlClockGet(),9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE));
    UARTEnable(UART3_BASE);



    while(1){
        while(!UARTCharsAvail(UART3_BASE));
        data=UARTCharGetNonBlocking(UART3_BASE);
        LED=0;
        bluetoothSendMessage("\n Press 1 for sandy\n Press 2 for loamy\n Press 3 for type 3\n Press 4 for type 4");
        if(data=='1'){
            LED = 2;
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
            GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, LED);
            bluetoothSendMessage("\n 1 is pressed, sandy soil\n");
            SysCtlDelay(10000000);}
        else if(data=='2'){
            LED = 4;
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
            GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_2);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, LED);
            bluetoothSendMessage("\n 2 is pressed soil type 2 is selected \n");
            SysCtlDelay(10000000);}
        else if(data=='3'){
            LED = 8;
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
            GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_3);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, LED);
            bluetoothSendMessage("\n soil type 3 is selected \n");
            SysCtlDelay(10000000);}
        else if(data=='4'){
            LED = 14;
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
            GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, LED);
            bluetoothSendMessage("\n soil type 4 is selected \n");
            SysCtlDelay(10000000);}
        else{
            LED = 0;
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
            GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, LED);
            bluetoothSendMessage("\nTiva send = NO\n");
            SysCtlDelay(10000000);}
       }
    UARTDisable(UART1_BASE);
}


void bluetoothSendMessage(char *array){
    while(*array){
        UARTCharPut(UART3_BASE,*array);
        array++;}}























































//#include <stdint.h>
//#include <stdbool.h>
//
//#include "tm4c123gh6pm.h"
//
//
////#include "D:\Embedded Systems\Tivaware C series\inc\tm4c123gh6pm.h"
////#include "tm4c123gh6pm.h"
//#include "D:/Embedded Systems/Tivaware C series/inc/hw_memmap.h"
//#include "D:/Embedded Systems/Tivaware C series/inc/hw_types.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/gpio.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/pin_map.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/sysctl.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/uart.h"
//#include "D:/Embedded Systems/Tivaware C series/inc/hw_ints.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/interrupt.h"
//
//#include <stdio.h>
//#include <stdint.h>
//#include <stdbool.h>
//#include "D:/Embedded Systems/Tivaware C series/inc/hw_memmap.h"
//#include "D:/Embedded Systems/Tivaware C series/inc/hw_types.h"
//#include "D:/Embedded Systems/Tivaware C series/inc/hw_gpio.h"
//
//#include "D:/Embedded Systems/Tivaware C series/driverlib/sysctl.c"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/sysctl.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/gpio.c"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/gpio.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/debug.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/pwm.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/pin_map.h"
//#include "D:/Embedded Systems/Tivaware C series/driverlib/rom.h"
////* Example code to transmit data with SPI1 module of TM4C123 */
///* Transmits character A and B with a delay of one second */
//#include "tm4c123gh6pm.h"
//
///* function prototype of SPI and Delay */
//void SPI1_init(void);
//void SPI1_Write(unsigned char data);
//void Delay_ms(int time_ms);
//
///* Main routine of code */
//int main(void)
//{
//    unsigned char val1 = 'A';
//      unsigned char val2 = 'B';
//
//    SPI1_init();
//    while(1)
//        {
//    SPI1_Write(val1); /* write a character */
//    Delay_ms(1000);
//        SPI1_Write(val2); /* write a character */
//    Delay_ms(1000);
//    }
//}
//
//void SPI1_Write(unsigned char data)
//{
//    GPIOF->DATA &= ~(1<<2);       /* Make PF2 Selection line (SS) low */
//    while((SSI1->SR & 2) == 0); /* wait untill Tx FIFO is not full */
//    SSI1->DR = data;            /* transmit byte over SSI1Tx line */
//    while(SSI1->SR & 0x10);     /* wait until transmit complete */
//    GPIOF->DATA |= 0x04;        /* keep selection line (PF2) high in idle condition */
//}
//
//void SPI1_init(void)
//{
//    /* Enable clock to SPI1, GPIOD and GPIOF */
//
//    SYSCTL->RCGCSSI |= (1<<1);   /*set clock enabling bit for SPI1 */
//    SYSCTL->RCGCGPIO |= (1<<3); /* enable clock to GPIOD for SPI1 */
//    SYSCTL->RCGCGPIO |= (1<<5); /* enable clock to GPIOF for slave select */
//
//    /*Initialize PD3 and PD0 for SPI1 alternate function*/
//
//    GPIOD->AMSEL &= ~0x09;      /* disable analog functionality RD0 and RD3 */
//    GPIOD->DEN |= 0x09;         /* Set RD0 and RD3 as digital pin */
//    GPIOD->AFSEL |= 0x09;       /* enable alternate function of RD0 and RD3*/
//    GPIOD->PCTL &= ~0x0000F00F; /* assign RD0 and RD3 pins to SPI1 */
//    GPIOD->PCTL |= 0x00002002;  /* assign RD0 and RD3 pins to SPI1  */
//
//    /* Initialize PF2 as a digital output as a slave select pin */
//
//    GPIOF->DEN |= (1<<2);         /* set PF2 pin digital */
//    GPIOF->DIR |= (1<<2);         /* set PF2 pin output */
//    GPIOF->DATA |= (1<<2);        /* keep SS idle high */
//
//    /* Select SPI1 as a Master, POL = 0, PHA = 0, clock = 4 MHz, 8 bit data */
//
//    SSI1->CR1 = 0;          /* disable SPI1 and configure it as a Master */
//    SSI1->CC = 0;           /* Enable System clock Option */
//    SSI1->CPSR = 4;         /* Select prescaler value of 4 .i.e 16MHz/4 = 4MHz */
//    SSI1->CR0 = 0x00007;     /* 4MHz SPI1 clock, SPI mode, 8 bit data */
//    SSI1->CR1 |= 2;         /* enable SPI1 */
//}
//
///* This function generates delay in ms */
///* calculations are based on 16MHz system clock frequency */
//
//void Delay_ms(int time_ms)
//{
//    int i, j;
//    for(i = 0 ; i < time_ms; i++)
//        for(j = 0; j < 3180; j++)
//            {}  /* excute NOP for 1ms */
//}
//
//void SystemInit(void)
//{
//    /* use this only if you are using old versions of Keil uvision */
//    SCB->CPACR |= 0x00f00000;
//}
