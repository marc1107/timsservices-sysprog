#define _POSIX_C_SOURCE 1

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <fcntl.h>  // open, O_RDONLY, O_WRONLY, O_CREAT, O_EXCL
#include <sys/stat.h> // mode_t, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#include <unistd.h> // read, write
#include <errno.h>  // errn

int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s [src] [dst]", argv[0]);
        return -1;
    }

    int fdSrc = open(argv[1], O_RDONLY);
    if(errno)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    struct stat sb;
    
    if(fstat(fdSrc, &sb) < 0)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }
    
    unsigned char *buffer = malloc(sb.st_size);

    read(fdSrc, buffer, sb.st_size);
    if(errno)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        free(buffer);
        return -1;
    }

    int fdDst = creat(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    write(fdDst, buffer, sb.st_size);
    if(errno)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        free(buffer);
        return -1;
    }

    close(fdSrc);
    close(fdDst);
    free(buffer);
    return 0;
}
