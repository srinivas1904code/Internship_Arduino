;111 sequence detection using fintie state machine
.include "/home/srinivaas/assembly/piosetup/m328Pdef/m328Pdef.inc"
ldi r16,0b00000101
out TCCR0B, r16 ; setting prescalar so clock becomes 16khz
cbi DDRD,2; declaring pin2 as input
;sbi DDRD,5; declaring pin5 as output
ldi r16, 0b00111111
out DDRB,r16 ; declaring pin 8(for output) and pin 12,11,10,9 for output of state,13 for input reference
clr r16; represents q1
clr r17; represents q2
clr r30
start:
	rcall dup ;duplicating q1,q2 in r18,r19
	sbi PORTB,5; glowing pin 13 indicates time for giving input
	rcall delay
	in r29, PIND;taking a single input bit
	lsr r29
	lsr r29; making input bit as lsb
	cbi PORTB,5;turning off pin 13 indicates input time is over
	rcall delay
	com r18; q1'
	com r19; q2'
	and r18,r19; r18 = q1'.q2'
	and r18,r29; r18 = q1'.q2'.x
	mov r21,r18; d1 = r21 = q1'.q2'.x
	rcall dup
	add r18,r19;q1+q2 in r18
	and r18,r29; r18 = (q1+q2).x
	mov r22,r18 ; move r18 to r22 = d2
	rcall dup
	and r19,r29; r19 = q2.x
	mov r23,r19; r23 = r19 = y i.e., output register
	;sbrc r23,0; skips next instruction if y=0
	;rcall one; calls if y =1
	;sbrs r23,0
	;rcall zero; calls if y=0
	rcall sevenseg
	rcall delay; produces delay to turn on a led
	mov r16,r21; updating values of q1,q2 with d1,d2
	mov r17,r22
	rjmp start
	
dup:
	mov r18,r16
	mov r19,r17
	ret
	
delay:
	ldi r25,0b01000000
pause:
lp2:
	in r26,TIFR0
	ldi r27,0b00000010
	and r26,r27
	breq pause
	out TIFR0,r27
	dec r25
	brne lp2
	ret

zero:
	cbi PORTB,2
	ret

one:
	sbi PORTB,2
	ret
sevenseg:
	clr r24
	com r23; dot activates only for zero so complimenting y
	bst r23,0
	bld r24,0; assign output !y to pin8
	bst r22,0
	bld r24,1; assign d2 to pin9
	bst r21,0
	bld r24,2; assign d1 to pin10
	out PORTB,r24
	ret
