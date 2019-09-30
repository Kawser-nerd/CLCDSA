#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x,y,mn;
char in[510][510];
int sum[510][510], tmp[510][510];

int get_sum(int x1, int x2, int y1, int y2){
  return sum[x2+1][y2+1] - sum[x1][y2+1] - sum[x2+1][y1] + sum[x1][y1];
}

int main(){
  int i,j,k,l,m,n;
  int res;
  int x_st, y_st, x_ed, y_ed, len;

  int a, b;

  int size, count=0;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"size %d\n",size);

    scanf("%d%d%d",&x,&y,&n);
    rep(i,x) scanf("%s",in[i]);

    rep(i,x) rep(j,y) in[i][j] -= '0';

    rep(i,x){
      tmp[i][0] = 0;
      rep(j,y) tmp[i][j+1] = tmp[i][j] + in[i][j];
    }

    rep(j,y+1){
      sum[0][j] = 0;
      rep(i,x) sum[i+1][j] = sum[i][j] + tmp[i][j];
    }

    res = 2;
    mn = x; if(mn > y) mn = y;

    REP(k,3,mn+1){
      len = k/2;
      
      rep(x_st, x-k+1) rep(y_st, y-k+1){
        x_ed = x_st + k - 1;
        y_ed = y_st + k - 1;
        
        a = get_sum(x_st, x_st+(len-1), y_st, y_ed) - in[x_st][y_st] - in[x_st][y_ed];
        b = get_sum(x_ed-(len-1), x_ed, y_st, y_ed) - in[x_ed][y_st] - in[x_ed][y_ed];
        if(a!=b) continue;
        
        a = get_sum(x_st, x_ed, y_st, y_st+(len-1)) - in[x_st][y_st] - in[x_ed][y_st];
        b = get_sum(x_st, x_ed, y_ed-(len-1), y_ed) - in[x_st][y_ed] - in[x_ed][y_ed];
        if(a!=b) continue;

        res = k;
      }
    }

    printf("Case #%d: ",++count);
    if(res<=2){puts("IMPOSSIBLE"); continue;}
    printf("%d\n",res);
  }


  return 0;
}
