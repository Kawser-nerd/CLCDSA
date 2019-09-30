#include<stdio.h>

int main(void){
  int t,array[2][4][4],i,j,k,fir,sec,count,ans;
  scanf("%d",&t);
  for(i=1;i<=t;i++){
    count=-1;
    scanf("%d",&fir);
    for(j=0;j<4;j++)
      for(k=0;k<4;k++)
	scanf("%d",&array[0][j][k]);
    scanf("%d",&sec);
    for(j=0;j<4;j++)
      for(k=0;k<4;k++)
	scanf("%d",&array[1][j][k]);
    
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	if(array[0][fir-1][j]==array[1][sec-1][k]){
	  count++;
	  ans=array[0][fir-1][j];
	}
      }
    }

    printf("Case #%d: ",i);
    if(!count) printf("%d\n",ans);
    else if(count>0) puts("Bad magician!");
    else puts("Volunteer cheated!");
  }
  return 0;
}

    
