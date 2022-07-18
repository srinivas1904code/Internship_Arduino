//implementing excess 3 code in avr-gcc
#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>
int main(void){
  bool a,b,c,d,w,y,x,z;
  DDRD =0b00000000;
  PORTD =0b00111100;
  DDRB =0b00001111;
  while(1){
	a = (PIND &(1<< PIND2)) == (1<< PIND2);
	b = (PIND &(1<< PIND3)) == (1<< PIND3);
	c = (PIND &(1<< PIND4)) == (1<< PIND4);
	d = (PIND &(1<< PIND5)) == (1<< PIND5);
	w = (a) || (b && c)|| (b && d);
	x = ((!b)&&c) || ((!b)&&d) || (b && (!c) &&(!d));
	y = (c && d) || ((!c) && (!d));
	z = (!d);
	PORTB = (w << 0);
	PORTB = (x << 1);
	PORTB = (y << 2);
	PORTB = (z << 3);
	}
  return 0;
}
