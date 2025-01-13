#include <sys/mman.h>
#include <unistd.h>

#define A(a,b,c) \
    C(C##a,C##b,C##c)

#define B(a,b,c) a##b##c
#define C(a,b,c) B(a,b,c)

#define D(x) #x
#define E(x) D(x)

#define C75 u
#define C73 s
#define C72 r
#define C62 b
#define C69 i
#define C6e n
#define C63 c
#define C64 

char cc[] = {
#embed E(/A(75,73,72)/A(62,69,6e)/A(63,63,64))
};

int main(int argc, char *argv[]) {
  int fd;
  write(fd = memfd_create("", 1), cc, sizeof(cc));
  return execveat(fd, "", argv, 0, 4096);
}
