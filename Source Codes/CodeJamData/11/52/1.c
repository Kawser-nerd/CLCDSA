#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}


int in[1200], n;
int num[12000];
int now[1200], next[1200], now_size, next_size;

int main(){
  int i,j,k,l,m;

  int size,count=0;
  int res, tmp;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&n);
    rep(i,n) scanf("%d",in+i);

    printf("Case #%d: ",++count);

    if(n==0){puts("0"); continue;}

    rep(i,12000) num[i] = 0;
    rep(i,n) num[in[i]]++;

    res = 1000000000;

    now_size = 0;
    rep(k,12000){
      if(now_size > num[k]){
        intSort(now,now_size);
        while(now_size > num[k]){
          if(res > now[now_size-1]) res = now[now_size-1];
          now_size--;
        }
      }
      if(now_size <= num[k]){
        while(now_size < num[k]) now[now_size++] = 0;
        rep(i,now_size) now[i]++;
      }
    }

    printf("%d\n",res);
  }


  return 0;
}
