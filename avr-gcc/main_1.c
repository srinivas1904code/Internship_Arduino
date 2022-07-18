// switching on the led
#include<avr/io.h>
int main(void){
  DDRD |= 0xFC;
  DDRB |=(1<<DDB0);
  while(1){
	PORTB =(1<<PB0);
	PORTD = 0b01001000;
  }
  return 0;
}
