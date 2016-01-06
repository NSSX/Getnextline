#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include "libft.h"

int lineorend(char *chaine)
{
  int result;
  int i;

  i = 0;
  result = 4;
  while(chaine[i] && result == 4)
    {
      
      if(chaine[i] == '\n')
	result = 1;
      i++;
    }
  if(!chaine[i] && result == 4)
    result = 0;
  return (result);
}

int amalloc(char *chaine)
{
  int i;

  i = 0;
  while(chaine[i] != '\n' && chaine[i] != '\0')
    {
      i++;
    }
  return (i);
}

int get_next_line(int const fd, char **line)
{
  static  int thereturn;
  int ret;
  char buf[BUFF_SIZE + 1];
  static char *chaine;
  int mall;
  int i;
 
  mall = 0;
  thereturn = 4;
  i = 0;
      if(fd <= 0 || line == NULL)
        return (-1);
  if (!chaine)
    chaine = ft_strnew(BUFF_SIZE + 1);
    while(thereturn == 4)
    {
      if((ret = read(fd, buf, BUFF_SIZE)))
	{
	  buf[BUFF_SIZE] = '\0';
	  chaine = ft_strjoin(chaine,buf);
	}
      if(ret == -1)
	return (-1);
      else if(lineorend(chaine) == 1)
        thereturn = 1;
      else if(lineorend(chaine) == 0 && ret == 0)
	thereturn = 0;
    }
    mall = amalloc(chaine);
    line[0] = ft_strnew(mall + 1);
    while(i < mall)
      {
	
	line[0][i] = chaine[i];
	i++;
      }
    line[0][i] = '\0';
    i = 0;
    while(chaine[i] != '\n' && chaine[i] != '\0')
      i++;
    i++;  
    chaine = ft_strsub(chaine,i,ft_strlen(chaine));
    return (thereturn);
}
/*
int main (int argc, char **argv)
{
    int	     fd;
    char *line;

    if (argc != 2)
      return (0);
    fd = open(argv[1], O_RDONLY);    
      while(get_next_line(fd, &line))
      {
	printf("\nma ligne : %s\n",line);
	free(line);
       }
      printf("\nma ligne : %s\n",line);
    return (0);
    }*/
