#include<stdio.h>
int d[2][100010],r[2],u[100010];
int ta[100010],to[200010],nt[200010];
int f(int s,int j){
  int i;
  u[s]=1;
  d[j][r[j]++]=s;
  for(i=ta[s];i+1;i=nt[i]){
    if(u[to[i]])continue;
    if(f(to[i],j))return 1;
  }
  return 1;
}
int main(){
  int n,m,i,a,b;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)ta[i+1]=-1;
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    nt[i  ]=ta[to[i+m]=a];
    nt[i+m]=ta[to[i  ]=b];
    ta[a]=i;
    ta[b]=i+m;
  }
  /*for(i=0;i<n;i++){printf("%d:",i+1);
    for(a=ta[i+1];a+1;a=nt[a])printf("%d ",to[a]);printf("\n");
    }//return 0;*/
  f(1,0);
  u[1]=0;
  f(1,1);
  //for(i=0;i<r[0];i++)printf("%d ",d[0][i]);printf("\n");
  //for(i=0;i<r[1];i++)printf("%d ",d[1][i]);printf("\n");return 0;
  printf("%d\n",r[0]+r[1]-1);
  for(i=r[0];--i;)printf("%d ",d[0][i]);
  printf("1");
  for(i=1;i<r[1];i++)printf(" %d",d[1][i]);
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^