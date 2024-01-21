#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

void convert_buffer_toupper(char* buffer, int count)
{
    for(int i = 0; i < count; i++)
    {
        buffer[i] = toupper(buffer[i]);
    }
}

void print_to_console(int fd)
{
    char buffer[2048];
    int count = 0;

    count = read(fd, buffer, sizeof(buffer));
    while (count > 0)
    {
        convert_buffer_toupper(buffer, count);
        write(1, buffer, count);
        count = read(fd, buffer, sizeof(buffer));
    }
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        print_to_console(0);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            int fd = open(argv[i], O_RDONLY);

            if(fd == -1)
            {
                perror("open");
                continue;
            }
            
            print_to_console(fd);
            close(fd);
        }
    }
}
