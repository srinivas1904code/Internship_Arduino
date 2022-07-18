; implementing excess3 code using ALP

.include "/home/saikiran/ArduinoAss/m328Pdef.inc"
ldi r16,0b11110000
out DDRB,r16
ldi r16,0b11111111
out PortB,r16
ldi r16,0b00111100
out DDRD,r16
Start:
in r25,PINB 

call assm
and r19,r18	; c=cb
and r18,r20;	b=bd
or r19,r18; c=bc+bd
or r17,r19; a=a+bc+bd
com r20 ; 	d=d'
mov r21,r17	;w=a+bc+bd
mov r24,r20	;z=d'

call assm
com r18	;b=b'
com r19	;c'
com r20	;d'
and r19,r20	;c=c'd'
;or r19,r20	; c=c+d
;com r19	;c=c'd'
eor r18,r19	;b=b'xor (c'd')
mov r22,r18	; x= b

call assm
eor r19,r20 ; c= c xor d
com r19		; c=c0d
mov r23,r19	; y=c

bst r21,0
bld r26,2
bst r22,0
bld r26,3
bst r23,0
bld r26,4
bst r24,0
bld r26,5

out PortD,r26
rjmp Start


assm:
bst r25,0
bld r17,0
bst r25,1
bld r18,0
bst r25,2
bld r19,0
bst r25,3
bld r20,0
ret
