#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int a,b,c,d,e,f,i,j,s[10010],w[10010],x=1,y=0;
  scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
  for(i=0;i<f;i++)s[i+1]=w[i+1]=0;
  s[0]=w[0]=1;
  x=a*100;
  for(i=0;i*100<=f;i++){
    // printf("%d\n",w[i]);
    if(w[i])w[i+a]=w[i+b]=1;
  }
  for(i=0;i<=f;i++){
    //printf("%d ",s[i]);
    if(s[i])s[i+c]=s[i+d]=1;
  }//printf("\n");
  for(i=a;i*100<=f;i++){
    if(w[i]==0)continue;
    for(j=0;j<=f;j++){
      if(s[j]==0)continue;
      if(j>i*e||i*100+j>f)continue;
      if((i*100+j)*y<(x+y)*j){
	x=i*100;
	y=j;
      }
    }
  }
  printf("%d %d\n",x+y,y);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
   ^