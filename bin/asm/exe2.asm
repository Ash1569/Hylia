
----------------------
LOADI   #4,  r9
LOADI   #1,  r10
LOADI   #6,  r2
LOADI   #69, r1

ADD     r1,  r1,  r1
SUB     r2,  r10, r2
JMPG    r2,  r9,  @11


----------------------
03 09 00 04
03 0A 00 01
03 02 00 06
03 01 00 45

01 01 01 01
02 02 0A 02
07 09 02 0B

-----------

04 00 09 03
01 00 0A 03
06 00 02 03
45 00 01 03

01 01 01 01
02 0A 02 02
0B 02 09 07

-----------
