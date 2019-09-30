#include <stdio.h>
#include <stdlib.h>

#define SMALL
//#define LARGE

int main(int argc, char *argv[])
{
//  char map[]="ynficwlbkuomxsevzpdrjgthaq";
  char map[]="yhesocvxduiglbkrztnwjpfmaq";
  char G[101], *p;
  int c,T;
  
  freopen("a.txt", "rt", stdin);
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif

  scanf("%d\n",&T);
  for (c=0;c<T;c++) {
      gets(G);
      for(p=G;*p!=0;p++) 
        if(*p!=' ') *p=map[*p-97];
      printf("Case #%d: %s\n",c+1,G);
  }  
  return 0;
}
