#define _POSIX_C_SOURCE 1

#include <inttypes.h>
#include <string.h>
#include <stdio.h>

#include <fcntl.h>  // open, O_RDONLY, O_WRONLY, O_CREAT, O_EXCL
#include <sys/stat.h> // mode_t, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#include <unistd.h> // read, write
#include <errno.h>  // errn
#include <locale.h>  // setlocale()

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    uint32_t bytes = 0;

    if (argc == 1)
    {
        uint32_t n = 0;
        unsigned char c;
        while ((n = read(0, &c, sizeof(unsigned char))) > 0)     
        {
            bytes += n;
        }

        printf("%d Zeichen\n", bytes);
        return 0;
    }
    
    for (int i = 1; i < argc; ++i)
    {
        struct stat sb;
        
        if (stat(argv[i], &sb) < 0)
        {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            continue;
        }

        printf("%s: %ld Zeichen\n", argv[i], sb.st_size);
    }

    return 0;
}