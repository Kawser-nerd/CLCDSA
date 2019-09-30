#include<stdio.h>
int d[2][100010],w=0;
int ta[100010],to[200010],nt[200010];
void f(int s){
  int i,j,t,r,q[100010];
  d[w][q[t=0]=s]=1;
  for(r=1;r-t;t++){
    for(i=ta[q[t]];i+1;i=nt[i]){
      if(d[w][to[i]])continue;
      d[w][to[i]]=d[w][q[t]]+1;
      q[r++]=to[i];
    }
  }
}
int main(){
  int n,a,b,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)ta[i+1]=-1;
  for(i=0;i<n-1;i++){
    scanf("%d %d",&a,&b);
    nt[i    ]=ta[to[i+n]=a];
    nt[i+n  ]=ta[to[i  ]=b];
    ta[a]=i;
    ta[b]=i+n;
  }
  f(1);
  w++;//for(i=1;i<=n;i++)printf("%d %d\n",d[0][i],d[1][i]);
  f(n);
  for(i=a=b=0;i<n;i++){
    if(d[0][i+1]>d[1][i+1])b++;
    else a++;
  }
  //for(i=1;i<=n;i++)printf("%d %d\n",d[0][i],d[1][i]);
  printf("%s\n",b<a?"Fennec":"Snuke");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^