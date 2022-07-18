;take a 4-bit bcd number and convert it into grey code
.include "/home/srinivaas/assembly/piosetup/m328Pdef/m328Pdef.inc"

start:
	ldi r16,0b00000101
	out TCCR0B,r16
	ldi r16,0b11000011; input bcd pins as 5(msb),4,3,2(lsb)
	out DDRD,r16
	ldi r16,0b11111111
	out PORTD,r16; for internal pull up
	ldi r21,0b00001111
	out DDRB,r21; output grey code pins as 11(msb),10,9,8(lsb) 
	in r16,PIND;  taking inputs from the port and storing in r16
	clr r17
	clr r18
	clr r19
	clr r20
	bst r16,2
	bld r17,0; lsb into r17
	bst r16,3
	bld r18,0
	bst r16,4
	bld r19,0
	bst r16,5
	bld r20,0; msb in r20
	eor r17,r18; lsb exor second bit and store it r17 ->g0
	eor r18,r19; exor of second and third bit and result in r18 ->g1
	eor r19,r20; exor of third and fourth bit and result in r19 ->g2
	lsl r18; left shift so that bit in pos1 moves to pos2
	add r18,r17; obtained pos1 and pos2 (g1 g0)
	lsl r19
	lsl r19; left shift twice to make bit in pos1 shift to pos3
	add r19,r18; bits in order (g2 g1 g0)
	lsl r20
	lsl r20
	lsl r20; pos1 to pos4
	add r20,r19; bits in order (g3 g2 g1 g0)
	out PORTB,r20
	ldi r23,0b01000000
	rcall PAUSE
	rjmp start
	

PAUSE:
lp2:
	in r21,TIFR0
	ldi r22,0b00000010
	AND r21,r22
	breq PAUSE
	out TIFR0,r22
	dec r23
	brne lp2
	ret
