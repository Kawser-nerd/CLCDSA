#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int n,m,a,b,c,i,max=0,min=1e9,d[100010],s=0;
  int f[100010]={};
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  for(i=0;i<n;i++){      
    min=MIN(min,d[i]);
    max=MAX(max,d[i]-min);
  }
  //printf("%d\n",max);
  min=1e9;
  for(i=0;i<n;i++){
    min=MIN(min,d[i]);//printf("%d %d\n",min,d[i]);
    if(d[i]-min==max)f[i]=1;
  }
  //for(i=0;i<n;i++)printf("%d %d\n",d[i],f[i]);
  a=-1;
  c=b=0;
  //printf("%d\n",max);
  for(i=n-1;i>-1;i--){//printf("%d %d %d\n",a,b,c);
    if(f[i]){
      if(a==d[i])c++;
      else{
	s+=MIN(c,b);
	c=1;
	b=0;
	a=d[i];
      }
    }
    else if(a-d[i]==max)b++;
  }
  printf("%d\n",s+MIN(b,c));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:8:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&d[i]);
                   ^