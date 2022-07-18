.include "/home/saikiran/ArduinoAss/m328Pdef.inc"

ldi r16,0b00111100
out DDRD,r16
ldi r25,0x00
Start:

call assm	;giving default values
com r17		;complement w=w'
mov r21,r17	;A=w'
call assm	;giving default values

com r20	;complement  z =z'
and r20,r17; and w and z' z=wz' 
com r17	;complement w=w'
and r17,r18	;and w' and x w=w'x
com r18 	;complementing x =x'
and r20,r18	;and z and x' z=wx'z'
or r20,r17	; or wx'z', w'x
mov r22,r20

call assm
com r17
and r17,r19
com r18
and r18,r19
or r17,r18
mov r23,r17
call assm
and r17,r18
com r19
and r17,r19
or r23,r17

call assm
and r18,r17
and r18,r19
com r17
and r20,r17
or r20,r18
mov r24,r20


bst r21,0
bld r26,2
bst r22,0
bld r26,3
bst r23,0
bld r26,4
bst r24,0
bld r26,5

out PortD,r26
inc r25
cpi r25,0x0A
brsh incloop

ldi r27,0xFF
ldi r28,0xFF
ldi r29,0xFF

loop:
dec r27
brne loop
dec r28
brne loop
dec r29
brne loop


rjmp Start

incloop:
ldi r25,0x00
ret

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
