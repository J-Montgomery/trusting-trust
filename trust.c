// #define _GNU_SOURCE 
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// char cc[] = {
// #embed "/usr/bin/cc" 
// };

// int main(int argc, char *argv[]) {
//     printf("Starting cc\n");

//     FILE *fp = fmemopen(cc, 928584, "r");
//     int fd = fileno(fp);
//     int ret = execveat(fd, NULL, argv, NULL ,AT_EMPTY_PATH);
//     printf("%d\n", ret);
//     return 0;
// }

#define _GNU_SOURCE 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
extern char **environ;

char cc[] = {
#embed "/usr/bin/cc" 
};

int main(int argc, char *argv[]) {
    int fd = memfd_create("", MFD_CLOEXEC);
    write(fd, cc, sizeof(cc));
    lseek(fd, 0, SEEK_SET);

    int ret = execveat(fd, "", argv, environ, AT_EMPTY_PATH);
    perror("execveat failed");
    return 1;
}