//printing numbers on a seven segment display from 0 to 9 in a loop
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
  DDRD |=0xFC;
  DDRB |=(1 << DDB0);
  const int p[10]={0,1,2,3,4,5,6,7,8,9};
  int i;
  while(1){
	for(i = 0 ;i<10;i++){
		sevenseg(p[i]);
		_delay_ms(300);
	}
	}
  return 0;
}
void sevenseg(int m){
  switch(m){
	case 0:
		PORTB =( 1 << 0);
		PORTD = 0b00000000;
		break;
	case 1:
		PORTB =( 1 << 0);
		PORTD = 0b11100100;
		break;
	case 2:
		PORTB =(  0 << 0);
		PORTD = 0b10010000;
		break;
	case 3:
		PORTB =( 0 << 0);
		PORTD = 0b11000000;
		break;
	case 4:
		PORTB =( 0 << 0);
		PORTD = 0b01100100;
		break;
	case 5:
		PORTB =( 0 << 0);
		PORTD = 0b01001000;
		break;
	case 6:
		PORTB =( 0 << 0);
		PORTD = 0b00001000;
		break;
	case 7:
		PORTB =(1 << 0);
		PORTD = 0b11100000;
		break;
	case 8:
		PORTB=( 0 << 0);
		PORTD = 0b00000000;
		break;
	case 9:
		PORTB=(0 << 0);
		PORTD = 0b10000000;
		break;
	default:
		PORTB= (0<<0);
		PORTD = 0b00011000;
		break;
	}
}


