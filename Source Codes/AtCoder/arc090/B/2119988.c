#include<stdio.h>
int ta[100010],to[400040],co[400040],nt[400040];
long long d[100010];
int main(){
  int n,m,i,j,t,r,a,b,c,q[100010],u[100010]={};
  for(i=0;i<100005;i++)d[i]=ta[i]=-1;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d %d %d",&a,&b,&c);
    nt[i  ]=ta[to[i+m]=a];
    nt[i+m]=ta[to[i  ]=b];
    co[ta[b]=i+m]=-c;
    co[ta[a]=i  ]= c;
  }
  for(j=1;j<=n;j++){
    if(u[j])continue;
    d[j]=1e10;
    q[t=0]=j;
    u[q[t]]=1;
    for(r=1;r-t;t++){
      //for(i=0;i<n;i++)printf("%d ",d[i+1]);printf("\n");
      for(i=ta[q[t]];i+1;i=nt[i]){//printf("%d %d\n",q[t],to[i]);
		if(d[to[i]]>0&&d[to[i]]!=d[q[t]]+co[i])goto END;
		if(u[to[i]])continue;
		d[to[i]]=d[q[t]]+co[i];
      	u[to[i]]=1;
		q[r++]=to[i];
      }
    }
  }
  printf("Yes\n");
  return 0;
 END:;
  printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a,&b,&c);
     ^