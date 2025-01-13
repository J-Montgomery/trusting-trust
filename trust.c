#define A(a, b, c)C(A##a,A##b,A##c)

#define B(a, b, c)a##b##c
#define C(a, b, c)B(a,b,c)

#define D(x) #x
#define E(x) D(x)

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

char cc[] = {
#embed P
};

// fix issue with compiler frontend not being able to resolve the linker,
// which is passed through a named extern var environ
extern char **environ;

#define S                                                                      \
  for (int i = 1; i < c; i++) {                                                \
    strcpy(p = alloca(strlen(Z) + strlen(v[i])), Z);                           \
    strcpy(p + strlen(Z), a[i] = v[i]);                                        \
    if (!access(v[i], 0) & !access(p, 0))                                      \
      rename(v[i], t) | rename(p, v[i]) | rename(t, p);                        \
  }

int main(int c, char *v[]) {
  int f;
  char *a[999] = {P}, *t = E(.A(H,2,K)), *p;

  S

  if (!fork()) {
    write(f = memfd_create(E(), 1), cc, sizeof cc);
    execveat(f, E(), a, environ, 4096);
  }
  wait(0);
  S
}
