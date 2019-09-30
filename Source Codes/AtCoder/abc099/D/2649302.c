#include<stdio.h>
int main(){
  int i[3],n,m,ans=1e9,s=0,a,b,d[50][50],c[510][510],e[5][50]={};
  scanf("%d %d",&n,&m);
  for(a=0;a<m;a++){
    for(b=0;b<m;b++)scanf("%d",&d[a][b]);
  }
  for(a=0;a<n;a++){
    for(b=0;b<n;b++)scanf("%d",&c[a][b]);
  }
  for(a=0;a<n;a++){
    for(b=0;b<n;b++)e[(a+b+2)%3][c[a][b]-1]++;
  }
  /*for(a=0;a<3;a++){
    for(b=0;b<m;b++)printf("%d ",e[a][b]);printf("\n");
    }//*/
  for(i[0]=0;i[0]<m;i[0]++){
    for(i[1]=0;i[1]<m;i[1]++){
      for(i[2]=0;i[2]<m;i[2]++){
	if(i[0]==i[1]||i[1]==i[2]||i[2]==i[0])continue;
	for(a=s=0;a<3;a++){
	  for(b=0;b<m;b++)s+=d[b][i[a]]*e[a][b];
	}
	/*for(a=s=0;a<n;a++){
	  for(b=0;b<n;b++)s+=d[c[a][b]-1][i[(a+b+2)%3]];
	  }//*/
	if(ans>s)ans=s;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:6:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(b=0;b<m;b++)scanf("%d",&d[a][b]);
                     ^
./Main.c:9:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(b=0;b<n;b++)scanf("%d",&c[a][b]);
                     ^