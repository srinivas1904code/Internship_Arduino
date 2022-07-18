;implement the kmap given in assembly
.include "/home/srinivaas/assembly/piosetup/m328Pdef/m328Pdef.inc"

ldi r16,0b00000001
out DDRB,r16; declaring pin 8 as output
ldi r16,0b11000011
out DDRD,r16; declaring pin 5(msb),4,3,2(lsb) as input pins
ldi r16,0b11111111
out PORTD,r16; for internal pull-ups

start:
	in r16,PIND; taking input from pins 5,4,3,2 and storing 
	rcall assa
	rcall assb
	and r20,r19
	mov r21,r20; r21 = A.B
	rcall assa
	rcall assc
	rcall assd
	and r20,r18; r20 = A.C
	and r20,r17; r20 = A.C.D
	mov r22,r20; r22 = A.C.D
	rcall assa
	rcall assb
	rcall assd
	com r20;r20 = A'
	com r19;r19 = B'
	and r20,r19; r20 = A'B'
	and r20,r17; r20 = A'B'D
	mov r23,r20; r23 = r20
	rcall assb
	rcall assc
	rcall assd
	com r18; C'
	com r17; D'
	and r18,r17
	and r18,r19; r18 = BC'D'
	add r23,r18
	add r23,r22
	add r23,r21
	out PORTB,r23
	rjmp start
	
assa:
	bst r16,5
	bld r20,0
	ret
assb:
	bst r16,4
	bld r19,0
	ret
assc:
	bst r16,3
	bld r18,0
	ret
assd:
	bst r16,2
	bld r17,0
	ret
