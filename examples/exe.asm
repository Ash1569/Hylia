LOADI #4, r9
LOADI #1, r10
LOADI #6, r2
LOADI #69, r1

ADD r1, r1, r1
SUB r2, r10, r2
JMPG r2, r9, @11



; TODO: Create a 'assembler' that converts the assembly code into the raw byte code encoded as Big Endian


LOADI #4, r9
LOADI #1, r10
LOADI #6, r2
LOADI #69, r1

ADD r1, r1, r1
SUB r2, r10, r2
JMPG r2, r9, @11



04 00 09 03
01 00 0A 03
06 00 02 03
45 00 01 03

01 01 01 01
02 0A 02 02
0B 02 09 07










; Checksum SHA-256 0994C6CA20F58B446442A6566EC86CAAFEC5C984687E867E46C6B9F7E1BB5300

LOADI #4, r9
LOADI #1, r10
LOADI #6, r2
LOADI #69, r1

ADD r1, r1, r1	; r1 = r1 + r1
SUB r2, r10, r2	; r2 = 6 - 1
JMPG #5 #0 @4	; r2 > 0

ADD r1, r1, r1	; r1 = 138 + 138
SUB r2, r10, r2	; r2 = 5 - 1
JMPG #4 #0 @4	; r2 > 0

ADD r1, r1, r1	; r1 = 276 + 276
SUB r2, r10, r2	; r2 = 4 - 1
JMPG #3 #0 @4	; r2 > 0

ADD r1, r1, r1	; r1 = 552 + 552
SUB r2, r10, r2	; r2 = 3 - 1
JMPG #2 #0 @4	; r2 >0

ADD r1, r1, r1	; r1 = 1104 + 1104
SUB r2, r10, r2	; r2 = 2 - 1
JMPG #1 #0 @4	; r2 > 0

ADD r1, r1, r1	; r1 = 2208 + 2208
SUB r2, r10, r2	; r2 = 1 - 1
JMPG #0 #0 @4	; r2 > 0

HALT

				; r1 = 4416
				; r2 = 0