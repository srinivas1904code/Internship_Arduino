//implenting clk using avr-gcc
#include<avr/io.h>
#include<util/delay.h>
int main (void)
{
  DDRB=(( 1 << DDB5));
  while(1){
	PORTB=(0<<PB5);
	 _delay_ms(500);
	PORTB=(1<<PB5);
	 _delay_ms(500);
  }
  return 0;
}
