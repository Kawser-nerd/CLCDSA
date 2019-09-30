#include<stdio.h>
#include<math.h>
double dir(int x0,int y0,int x1,int y1){return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0\
-y1));}

int main(){
  int flg1=0,flg2=0,i,j,x[3],y[3],r,a[200][200];
  scanf("%d%d%d",&y[0],&x[0],&r);scanf("%d%d%d%d",&y[1],&x[1],&y[2],&x[2]);
  for(i=0;i<3;i++){
    x[i]+=100;
    y[i]+=100;
  }

for(i=0;i<200;i++)
    for(j=0;j<200;j++){
      a[i][j]=0;
      if(dir(j,i,x[0],y[0])<=(double)r) a[i][j]=1;
      if(x[1]<=j&&j<=x[2]&&y[1]<=i&&i<=y[2])    a[i][j]=a[i][j]+2;
      if(a[i][j]==1)flg1=1;
      else if(a[i][j]==2)flg2=1;
    }

 if(r==0){   printf("NO\n");
 } else if(flg1==1){  printf("YES\n");
 }else{   printf("NO\n");
 }
 if(x[1]==x[2] || y[1]==y[2]){
   printf("NO\n");
 }else if(flg2==1){  printf("YES\n");
 }else{   printf("NO\n");
 }
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&y[0],&x[0],&r);scanf("%d%d%d%d",&y[1],&x[1],&y[2],&x[2]);
   ^
./Main.c:8:34: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&y[0],&x[0],&r);scanf("%d%d%d%d",&y[1],&x[1],&y[2],&x[2]);
                                  ^