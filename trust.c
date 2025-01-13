#include <sys/mman.h>
#include <unistd.h>

char cc[] = {
#embed "/usr/bin/cc"
};

int main(int argc, char *argv[]) {
  int fd;
  write(fd = memfd_create("", 1), cc, sizeof(cc));
  return execveat(fd, "", argv, 0, 4096);
}
