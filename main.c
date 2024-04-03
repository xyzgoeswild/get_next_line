#include "get_next_line_bonus.h"
#include "get_next_line.h"

#include "stdio.h"

int main(void)
{
    int     fd[3];
    int     i;
    char    *res;

    fd[0] = open("t1.txt", O_RDONLY);
    fd[1] = open("t2.txt", O_RDONLY);
    fd[2] = open("t3.txt", O_RDONLY);

    printf("\n\n-----------------------------------------\n\n");
    while (i < 3)
	{
		res = get_next_line(fd[0]);
		printf("line[%i] : %s", i, res);
        free(res);
		i++;
	}
    i = 0;
    printf("\n\n-----------------------------------------\n\n");
    while (i < 5)
	{
		res = get_next_line(fd[1]);
		printf("line[%i] : %s", i, res);
        free(res);
        i++;
	}
    i = 0;
    printf("\n\n-----------------------------------------\n\n");
    while (i < 3)
	{
		res = get_next_line(fd[2]);
		printf("line[%i] : %s", i, res);
        free(res);
		i++;
	}
    printf("\n\n-----------------------------------------\n\n");

    close(fd[0]);
    close(fd[1]);
    close(fd[2]);
}
