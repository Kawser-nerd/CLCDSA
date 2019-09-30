#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>


int main(void)
{	
	int L,R,i,j,sum=0;
	int l[100],r[100];
	scanf("%d %d",&L,&R);
	
	for(i=0;i<L;i++){
		scanf("%d",&l[i]);
	}
	for(i=0;i<R;i++){
		scanf("%d",&r[i]);
	}
	
	for(i=0;i<L;i++){
		for(j=0;j<R;j++){
			if(l[i]==r[j]){
				sum++;
				l[i]=0;
				r[j]=1000;
			}
		}
	}
	
	printf("%d\n",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&L,&R);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&l[i]);
   ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&r[i]);
   ^