#include<stdio.h>
int main(){
  int n,i,j,k,s=0,M=1e9+7;
  int d[10][60]={};
  char s1[100],s2[100];
  scanf("%d",&n);
  scanf("%s %s",s1,s2);
  for(i=0;i<9;i++){
    if(s1[0]==s2[0]&&i/3==i%3)d[i][0]=1;
    if(s1[0]!=s2[0]&&i/3!=i%3)d[i][1]=1;
  }
  for(i=s1[0]==s2[0]?0:1;i<n;i++){//printf("%d:",i);
    //for(j=0;j<9;j++)printf("%d ",d[j][i]);printf("\n");
    for(j=0;j<9;j++){
      for(k=0;k<9;k++){
	if(s1[i]==s2[i]){
	  if(j/3-j%3)continue;
	  if(s1[i+1]==s2[i+1]){
	    if(k/3-k%3)continue;
	    if(j/3==k/3)continue;
	    d[k][i+1]=(d[k][i+1]+d[j][i])%M;
	  }
	  else{
	    if(k/3==k%3)continue;
	    if(j/3==k/3||j%3==k%3)continue;
	    d[k][i+2]=(d[k][i+2]+d[j][i])%M;
	  }	  
	}
	else{
	  if(j/3==j%3)continue;
	  if(s1[i+1]==s2[i+1]){
	    if(k/3-k%3)continue;
	    if(j/3==k/3||j%3==k%3)continue;
	    d[k][i+1]=(d[k][i+1]+d[j][i])%M;
	  }
	  else{
	    if(k/3==k%3)continue;
	    if(j/3==k/3||j%3==k%3)continue;
	    d[k][i+2]=(d[k][i+2]+d[j][i])%M;
	  }
	}
      }
    }
    if(s1[i+1]-s2[i+1])i++;
  }
  for(i=0;i<9;i++)s=(s+d[i][n-1])%M;
  printf("%d\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",s1,s2);
   ^