//based on the input switching the led in avr-gcc
#include<avr/io.h>
#include<avr/delay.h>

int main(void)
{
  DDRB =0x01;
  PORTB=0X02;
  while(1){
	if(PINB & 0x02){
		PORTB |=0x01;
	}
	else{
		PORTB &=0xFE;
	}
  }
  return 0;
}
