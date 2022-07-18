//implementing final state machine for 011 sequence in avr-gcc 
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
  DDRD |= 0b00000000;
  PORTD |= 0b00000100;
  DDRB |=0b00000011;
  int q1=0,q2=0;
  int x,d1,d2,y;
  while(1){
	PORTB =(1<<0);
	_delay_ms(1000);
	PORTB =(0<<0);
	_delay_ms(1000);
	x=(PIND &(1 << PIND2)) == (1 << PIND2);
	d1=(!q1)&&(!q2)&&(x);
	d2=(q1)&&(x);
	y=(q2 &&(x));
	PORTB =(y << 1);
	_delay_ms(1000);
	q1=d1;
	q2=d2;
  }
  return 0;
}                     

