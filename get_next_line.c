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
  result = 0;
  while(chaine[i] && result == 0)
    {
      if(chaine[i] == '\n' || chaine[i] == '\0')
	result = 1;
      i++;
    }
  return (result);
}


int lineorend2(char *chaine)
{
  int result;
  int i;

  i = 0;
  result = 0;
  while(chaine[i] && result == 0)
    {
      if(chaine[i] == '\n')
        result = 1;
      else if(chaine[i] == '\0')
	result = 2;
      i++;
    }
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
  int thereturn;
  int ret;
  char buf[BUFF_SIZE + 1];
  static char *chaine;
  int mall;
  int i;

  thereturn = 1;
  i = 0;
  if (!chaine)
    chaine = ft_strnew(BUFF_SIZE + 1);
  
  while(lineorend(chaine) != 1)
    { 
      ret = read(fd, buf, BUFF_SIZE);
      printf(" %d ",ret);
      chaine = ft_strjoin(chaine,buf);
    }
  mall = amalloc(chaine);
  line = (char **)malloc(sizeof(char *) * 2);
  line[0] = (char *)malloc(sizeof(char) * mall + 1);
  while(i < mall)
    {
      line[0][i] = chaine[i];
      i++;
    }
  printf("\n\nma ligne : %s",line[0]);
  i = 0;
  while(i < mall)
    {
      chaine[i] = ' ';
      i++;
    }
  chaine = ft_strtrim(chaine);
  return (ret);
}

int main (int argc, char **argv)
{
    int	     fd;
    char *line;

    if (argc != 2)
      return (0);
    fd = open(argv[1], O_RDONLY);    
    printf(" return : %d",get_next_line(fd, &line)); 
    free(line); 
    /*   printf(" return : %d",get_next_line(fd, &line));
   free(line);
   printf(" return : %d",get_next_line(fd, &line));
   free(line);
   printf(" return : %d",get_next_line(fd, &line));
   free(line);
   printf(" return : %d",get_next_line(fd, &line));
   free(line);*/
    return (0);
}
