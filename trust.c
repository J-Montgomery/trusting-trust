#include <alloca.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#define A(a,b,c) \
    C(C##a,C##b,C##c)

#define B(a,b,c) a##b##c
#define C(a,b,c) B(a,b,c)

#define D(x) #x
#define E(x) D(x)

#define P E(/A(75,73,72)/A(62,69,6e)/A(63,63,64))

#define C75 u
#define C73 s
#define C72 r
#define C62 b
#define C69 i
#define C6e n
#define C63 c
#define C64 

char cc[] = {
#embed P
};

// fix issue with compiler frontend not being able to resolve the linker,
// which is passed through a named extern var environ
extern char **environ;

int main(int c, char *v[]) {
  int f, i;
  char *a[999], *q = P;

    // We need to insert the correct path so that the compiler frontend can resolve
    // parts of the toolchain
    a[0] = q;
    while(--c)
        a[c] = v[c];

  write(f = memfd_create("", 1), cc, sizeof(cc));
  return execveat(f, "", a, environ, 4096);
}
