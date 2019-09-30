#include <stdio.h>

int main(void)
{
  char a[11] ;
  int i ;
  int k=0 ;
  int j=0 ;

  scanf("%s", a) ;

  for(i=0;i<11;i++)
    {
      if(a[i]=='A'||a[i]=='C'||a[i]=='G'||a[i]=='T')
	j++ ;
      else
	{
	  if(k<j)
	    k=j ;
	  j=0 ;
	}
    }

  printf("%d", k) ;
  return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", a) ;
   ^