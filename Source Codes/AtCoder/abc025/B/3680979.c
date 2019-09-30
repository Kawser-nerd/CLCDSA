#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int N,A,B,ans=0;
	char whichway[5];
  int distance;
  scanf("%d%d%d",&N,&A,&B);
  for(int i=0; i<N; i++) {
    scanf("%s%d",whichway,&distance);
    if(!strcmp(whichway,"East")) {
      if(distance<A) ans+=A;
      else if(B<distance) ans+=B;
      else ans+=distance;
    }else{
      if(distance<A) ans-=A;
      else if(B<distance) ans-=B;
      else ans-=distance;
    }
  }
  if(ans>0) printf("East %d\n",ans);
  else if(ans<0) printf("West %d\n",ans*(-1));
  else printf("%d\n",0);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&N,&A,&B);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",whichway,&distance);
     ^