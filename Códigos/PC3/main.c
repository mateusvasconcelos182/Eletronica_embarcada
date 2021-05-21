#include <msp430.h> 
#include <intrinsics.h>
#include <stdint.h>
#include "lcd.h"

#define quente  BIT0
#define frio    BIT2
#define aumenta BIT1
#define diminui BIT5
#define sensor  BIT0
/**
 * main.c
 */
int main(void)
{
    lcdBegin();
    uint32_t temperatura, setpoint;
    P2OUT &= ~frio;
    P2OUT &= ~quente;
    P2DIR = quente | frio;
	WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | WDTSSEL;	// watchdog para interromper entre medicoes
	IE1 |= WDTIE;
	ADC10CTL0 = SREF_1 | ADC10SHT_3 | ADC10SR | ADC10IE;
	ADC10CTL1 = INCH_10 | SHS_0 | ADC10DIV_3 | ADC10SSEL_0 | CONSEQ_0;
	ADC10AE0 = sensor;

	while(1){
	    __low_power_mode_3();
	    if((P2IN & aumenta) == 0){
	        setpoint++;
	    }
	    if((P2IN & diminui) == 0){
	        setpoint--;
	    }
	    lcdSetCursor(1,0);
	    lcdPrint("Temperatura:");
	    lcdSetCursos(2,0);
	    lcdPrint("SetPoint:");
	    ADC10CTL0 |= (REFON |ADC10ON |ENC |ADC10SC);
	    __low_power_mode_3();
	    ADC10CTL0 &= ~(REFON |ADC10ON |ENC);
	    temperatura = ADC10MEM;
	    temperatura *= 500;
	    temperatura += 512;
	    temperatura /= 1024;
	    if (temperatura > setpoint+2){
	        P2OUT |= frio;
	        P2OUT &= ~quente;
	    }
	    else if (temperatura < setpoint-2){
	        P2OUT |= quente;
	        P2OUT &= ~frio;
	    }
	    else{
	        P2OUT &= ~frio;
	        P2OUT &= ~quente;
	    }
	}
}

//----------------------------------------------------------------------
//Rotina de interrupcao do watchdog timer
#pragma vector = WDT_VECTOR
__interrupt void WDT_ISR ( void )
{
__low_power_mode_off_on_exit();
}
//Rotina de interrupcao do ADC10
#pragma vector = ADC10_VECTOR
__interrupt void ADC10_ISR ( void )
{
__low_power_mode_off_on_exit();
}
