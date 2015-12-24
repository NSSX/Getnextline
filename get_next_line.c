#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
    i++;    
    }
}

int get_next_line(int const fd, char **line)
{
    
    
    
    return (0);
}

int main (int argc, char **argv)
{
    int		fd;
    int ret;
    char buf[BUF_SIZE + 1];
    
	if (argc != 2)
		return (0);

	fd = open(argv[1], O_RDONLY);
    while(ret = read(fd, buf, BUF_SIZE))
    {
        buf[ret] = '\0';
        //ft_putstr(buf);
      
    }
    ret = '\0';
    ft_putstr(buf);
    //ft_putstr("fuckiing yo");
    //ft_putchar(fd + 48);
    return (0);
}