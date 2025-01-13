#define A(a, b, c)C(A##a,A##b,A##c)

#define B(a, b, c)a##b##c
#define C(a, b, c)B(a,b,c)

#define D(x) #x
#define E(x) D(x)

#define F(a,b,c,d,e,f)H(A##a,A##b,A##c,A##d,A##e,A##f)

#define G(a,b,c,d,e,f)a##b##c##d##e##f
#define H(a,b,c,d,e,f)G(a,b,c,d,e,f)

#define A1 b
#define A2 c
#define A8 i
#define AD n
#define AH r
#define AI s
#define AJ t
#define AK u
#define AO y
#define AQ  

#define A0 a
#define A3 d
#define A4 e
#define A5 f
#define A6 g
#define A7 h
#define A9 j
#define AA k
#define AB l
#define AC m
#define AE o
#define AF p
#define AG q
#define AL v
#define AM w
#define AN x
#define AP z

//rename, strcpy, strlen, access, write, alloca, environ, fork
#define Z1 F(H,4,D,0,C,4) // rename
#define Z2 F(I,J,H,2,F,O) // strcpy
#define Z3 F(I,J,H,B,4,D) // strlen
#define Z4 F(0,B,B,E,2,0) // alloca
#define Z5 F(M,0,8,J,Q,Q) // wait
#define Z6 F(0,2,2,4,I,I) // access
#define Z7 A(5,E,H) // for
#define Z8 A(8,D,J) // int
#define Z9 F(5,E,H,A,Q,Q) // fork
#define ZA F(M,H,8,J,4,Q) // write
#define ZB A(8, 5, Q) // if
#define ZC F(2,7,0,H,Q,Q) // char
#define ZD F(4,D,L,8,H,E) // enviro
#define ZE F(4,N,J,4,H,D) // extern
#define ZF F(C,0,8,D,Q,Q) // main
#define ZG F(I,8,P,4,E,5) // sizeof
#define ZH F(H,4,J,K,H,D) // return
Z1
Z2
Z3
Z4
Z5
Z6
Z7
Z8
Z9
ZA
ZB
ZC
ZD
ZE
ZF
ZG
ZH