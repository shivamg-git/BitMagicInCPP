Example array [1, 33, 54, 4, 7, 8, 8901, 33, 1, 4, 54, 8, 8901] and answer will be 7 if we use XOR operation by using its property of m ^ m = 0 && m ^ 0 = m.

Manually lets XOR one by one and also take XOR of 7 at last so that before that we should have something like 0000 then only this property 0^7 would give us the answer.

1 ^ 33
    1	00000001
^	33	00100001
=	32	00100000

32	00100000
^	54	00110110
=	22	00010110

22 ^ 4
    22	00010110
^	4	00000100
=	18	00010010

18 ^ 8
    18	00010010
^	8	00001000
=	26	00011010

26 ^ 8901
    26	    0000000000011010
^	8901	0010001011000101
=	8927	0010001011011111

8927 ^ 33
    8927	0010001011011111
^	33	    0000000000100001
=	8958	0010001011111110

8958 ^ 1
    8958	0010001011111110
^	1	    0000000000000001
=	8959	0010001011111111

8959 ^ 4
    8959	0010001011111111
^	4	    0000000000000100
=	8955	0010001011111011

8955 ^ 54
    8955	0010001011111011
^	54	    0000000000110110
=	8909	0010001011001101

8909 ^ 8
    8909	0010001011001101
^   8	    0000000000001000
=	8901	0010001011000101

8901 ^ 8901
    8901	0010001011000101
^	8901	0010001011000101
=	0	0000000000000000 (Here we go!)

0 ^ 7
    0	00000000
^	7	00000111
=	7	00000111 Finally :)