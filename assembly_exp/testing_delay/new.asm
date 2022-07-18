.include "/home/srinivaas/assembly/piosetup/m328Pdef/m328Pdef.inc"

ldi r16,0b00000101
out TCCR0B, r16
ldi r16,0b00000011
out DDRB,r16
	sbi DDRB,5
	sbi PORTB,5
	rcall delay
	cbi PORTB,5
	rcall delay1
	rcall delay


delay:
	ldi r28,0b01000000
pause:
lp2:
	in r29,TIFR0
	ldi r30,0b00000010
	and r29,r30
	breq pause
	out TIFR0,r30
	dec r28
	brne lp2
	ret
	
	
delay1:
	ldi r25,0b01000000
pause1:
lp3:
	in r26,TIFR0
	ldi r27,0b00000010
	and r26,r27
	breq pause1
	;ldi r27,0b00000000; for testing
	;in r26,TIFR0
	;out PORTB,r26; state after pause 
	;rcall delay
; rewriting
	;out TIFR0,r27; moving 00
	;in r26,TIFR0 
	;out PORTB,r26; state after reset
	;rcall delay
	dec r25
	brne lp3
	ret
