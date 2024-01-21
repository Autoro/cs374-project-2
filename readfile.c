#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        write(2, "Invalid usage\n", 14);

        return 1;
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        perror("open");

        return 1;
    }

    char buffer[2048];
    int count = read(fd, buffer, sizeof(buffer));

    write(1, buffer, count);

    close(fd);
}
