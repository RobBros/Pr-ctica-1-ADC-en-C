/*
 * File:   adc_c.c
 * Author: ACER
 *
 * Created on 22 de octubre de 2020, 08:45 PM
 */
#pragma config FOSC = XT 
#pragma config WDTE = OFF 
#pragma config PWRTE = ON 
#pragma config BOREN = OFF 
#pragma config LVP = OFF 
#pragma config CPD = OFF 
#pragma config WRT = OFF 
#pragma config CP = OFF 
#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) {
    TRISB=0;
    TRISD&=~((1<<1)|(1<<0));
    ADCON0=0b01011000;
    ADCON1=0b10000100;
    
while(1){
ADCON0bits.ADON=1;
__delay_us(30);
ADCON0bits.GO=1;
while(ADCON0bits.GO==1);
ADCON0bits.ADON=0;
PORTB=ADRESH;
PORTB=ADRESL;
__delay_ms(100);
           }
return;
               }
