#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int comp( const void *c1, const void *c2 );

int main(void)
{
	char s[8001];
	int  x, y, i, j, c, xx[8000]={0}, yy[8000]={0}, xm=0, ym=0;
    
	scanf("%s", s);
	scanf("%d %d", &x, &y);
	
	c = 0; j = 0;
	for(i = 0; i <= strlen(s); i++){
	    if(s[i] == 'F'){
	        c++;
	    }else{
	        if(j%2){
	            yy[j] = c;
	        }else{
	            xx[j] = c;
	        }
	        c = 0;
	        j++;
	    }
	}
	xm = xx[0];
	xx[0] = 0;
	qsort( xx, strlen(s), sizeof(int), comp);
	qsort( yy, strlen(s), sizeof(int), comp);

	for(i = 0; xx[i] != 0; i++){
	    if(xm <= x){
	        xm += xx[i];
	    }else{
	        xm -= xx[i];
	    }
	}
	for(i = 0; yy[i] != 0; i++){
	    if(ym <= y){
	        ym += yy[i];
	    }else{
	        ym -= yy[i];
	    }
	}

	printf("%s\n", xm==x&&ym==y?"Yes":"No");
	return 0;
}

int comp( const void *c1, const void *c2 )
{
  int tmp1 = *(int *)c1;
  int tmp2 = *(int *)c2;
 
  if( tmp1 > tmp2 )  return -1;
  if( tmp1 == tmp2 ) return  0;
  if( tmp1 < tmp2 )  return  1;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &x, &y);
  ^