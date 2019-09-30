#include<stdio.h>
#include<stdlib.h>

int main(){
  long N,M,X,Y,*a,*b,*pa,*pb,*pab,*ptmp,i,ans=0;

  scanf("%ld%ld%ld%ld",&N,&M,&X,&Y);
  a=calloc(N+1,sizeof(long));
  b=calloc(M+1,sizeof(long));
  pa=a;
  pb=b;

  while(N--)
    scanf("%ld",pa++);
  while(M--)
    scanf("%ld",pb++);

  pa=a;
  pb=b;

  while(1){
    while(*pa+X>*pb){
      *pb++;
      if(!*pb){
	printf("%ld\n",ans);
	return 0;
      }
    }

    *pa++;
    while(*pb+Y>*pa){
      *pa++;
      if(!*pa){
	printf("%ld\n",ans+!!*pb);
	return 0;
      }
    }
    *pb++;
    ans++;
  }
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld%ld",&N,&M,&X,&Y);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",pa++);
     ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",pb++);
     ^