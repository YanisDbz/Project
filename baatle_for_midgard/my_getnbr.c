void my_putchar (char c);
void my_put_nbr (int c);
int	my_getnbr(char	*str)
{
  int r;
  int s;
  r=0;
  s=1;
  while(*str =='-' || *str=='+')
    {
      if(*str =='-')
	s*= -1 ;
      str++;
    }
  while(*str!='\0' && *str>='0' && *str<='9')
    {
      if(r==2147483647)
	return(0);
      if(r==2147483647 && s==1)
	return(0);
      if(r==2147483647 && s==-1)
	return(0);
      r=r*10 +(*str-48);
      
      str=str+1;
    }
  if(s==-1)
    r*= -1;
  return(r);
}
