#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int w,h,n;
int x[30],y[30];
int *dp;
int zaX[62],zaY[62];
int lenX,lenY;

int toIndex(int a,int c){
  int *za=(c?zaX:zaY);
  int l=0;
  int r=(c?lenX:lenY);
  while(r-l>1){
    int m=(l+r)/2;
    if(za[m]<=a){
      l=m;
    } else {
      r=m;
    }
  }
  return l;
}

int POS(int a,int b,int c,int d){
  int res=toIndex(a,1);
  res=62*res+toIndex(b,0);
  res=62*res+toIndex(c,1);
  res=62*res+toIndex(d,0);
  return res;
}

int calc(int sw,int sh,int tw,int th){
  if(dp[POS(sw,sh,tw,th)]>=0) return dp[POS(sw,sh,tw,th)];
  int max=0;
  int i;
  for(i=0;i<n;i++){
    if(sw<=x[i] && x[i]<=tw && sh<=y[i] && y[i]<=th){
      int local=(tw-sw+1)+(th-sh);
      local+=calc(sw    ,sh    ,x[i]-1,y[i]-1);
      local+=calc(x[i]+1,sh    ,tw    ,y[i]-1);
      local+=calc(sw    ,y[i]+1,x[i]-1,th);
      local+=calc(x[i]+1,y[i]+1,tw    ,th);
      if(max<local) max=local;
    }
  }
  dp[POS(sw,sh,tw,th)]=max;
  return max;
}

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  scanf("%d%d%d",&w,&h,&n);
  int i;
  for(i=0;i<n;i++) scanf("%d%d",x+i,y+i);
  for(i=0;i<n;i++){
    zaX[2*i]  =x[i]-1;
    zaX[2*i+1]=x[i]+1;
    zaY[2*i]  =y[i]-1;
    zaY[2*i+1]=y[i]+1;
  }
  zaX[2*n]  =1;
  zaX[2*n+1]=w;
  zaY[2*n]  =1;
  zaY[2*n+1]=h;
  qsort(zaX,2*n+2,sizeof(int),cmp);
  qsort(zaY,2*n+2,sizeof(int),cmp);
  lenX=i=0;
  while(i<2*n+2){
    zaX[lenX++]=zaX[i++];
    while(i<2*n+2 && zaX[i]==zaX[lenX-1]) i++;
  }
  lenY=i=0;
  while(i<2*n+2){
    zaY[lenY++]=zaY[i++];
    while(i<2*n+2 && zaY[i]==zaY[lenY-1]) i++;
  }
  dp=(int *)calloc(62*62*62*62,sizeof(int));
  for(i=0;i<62*62*62*62;i++) dp[i]=-1;
  int ans=calc(1,1,w,h);
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&w,&h,&n);
   ^
./Main.c:59:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",x+i,y+i);
                    ^