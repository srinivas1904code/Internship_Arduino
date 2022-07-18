;take a 4bit bcd number as input and display it in sevensegment display using 7447
.include "/home/srinivaas/assembly/piosetup/m328Pdef/m328Pdef.inc"
ldi r16,0b00111100; declaring pin 6,7 as input pin,and 2,3,4,5 as output pin
out DDRD,r16
ldi r16,0b00000000; declared pin 8,9 as input pin
out DDRB,r16
loop:
	in r16,PINB
	lsl r16
	lsl r16
	in r17,PIND
	rol r17
	rol r17
	rol r17
	ldi r22,0b00000011
	and r17,r22
	add r16,r17
	lsl r16
	lsl r16
	out PORTD,r16
	ldi r20,0b10000000
	rjmp loop

	
PAUSE:
lp2:
	in r18,TIFR0
	ldi r19,0b00000010
	AND r18,r19
	breq PAUSE
	out TIFR0,r19
	dec r20
	brne lp2
	ret 
