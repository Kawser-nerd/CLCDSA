#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char *hogege = "oieastbg";

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

char cnv(char a){
  int i;
  rep(i,8) if(a==hogege[i]) return '0' + i;
  return 0;
}

int main(){
  int i,j,k,l,m,n;
  char in[20000], a, b;
  int app[300][300], deg[300];
  int size, count = 0;
  int res;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&k);
    scanf("%s",in);

    rep(i,300) rep(j,300) app[i][j] = 0;
    rep(i,300) deg[i] = 0;
    res = 1;

    for(i=1;;i++){
      if(in[i]<' ') break;
      a = cnv(in[i-1]);
      b = cnv(in[i]);

      app[in[i-1]][in[i]] = 1;
      if(a) app[a][in[i]] = 1;
      if(b) app[in[i-1]][b] = 1;
      if(a && b) app[a][b] = 1;
    }

    rep(i,300) rep(j,300) if(app[i][j]){
      res++;
      deg[i]++; deg[j]--;
    }

    for(;;){
      intSort(deg, 300);
           if(deg[0] < -1 && deg[299] > 1){
        res++;
        deg[0]++; deg[299]--;
      }
      else if(deg[0] < -1 && deg[298] > 0){
        res++;
        deg[0]++; deg[298]--;
      }
      else if(deg[1] < 0 && deg[299] > 1){
        res++;
        deg[1]++; deg[299]--;
      }
      else if(deg[1] < 0 && deg[298] > 0){
        res++;
        deg[1]++; deg[298]--;
      }
      else break;
    }

    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
