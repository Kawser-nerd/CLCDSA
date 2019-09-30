#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int tc, i, cn;
  char m[256], l[101];
  scanf("%d", &tc);
  m[' ']=' ';
  m['a']='y';
  m['b']='h';
  m['c']='e';
  m['d']='s';
  m['e']='o';
  m['f']='c';
  m['g']='v';
  m['h']='x';
  m['i']='d';
  m['j']='u';
  m['k']='i';
  m['l']='g';
  m['m']='l';
  m['n']='b';
  m['o']='k';
  m['p']='r';
  m['q']='z';
  m['r']='t';
  m['s']='n';
  m['t']='w';
  m['u']='j';
  m['v']='p';
  m['w']='f';
  m['x']='m';
  m['y']='a';
  m['z']='q';
  while(getchar()!='\n');
  for(cn=1;cn<=tc;cn++) {
    gets(l);
    printf("Case #%d: ", cn);
    for(i=0;l[i]!='\0';i++)
      if(m[l[i]]=='?')
	printf("\nneed %c\n", l[i]);
      else
	printf("%c", m[l[i]]);
    printf("\n");
  }
  return 0;
}
