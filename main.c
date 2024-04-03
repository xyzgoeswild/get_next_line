#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return (0);

    line = get_next_line(fd);
    while(line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (0);
}