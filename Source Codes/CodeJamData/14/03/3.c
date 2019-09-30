#include <stdio.h>
#include <string.h>

int uu[55][55][2555];
int st[55][55][2555];
int nxt[55][55][2555];
char s[55][55];
#define enc(a,b,c) ((w)*1000000+(h)*1000000+(n))

int solve(int w,int h,int n)
{
  if( !uu[w][h][n] ) return 0;
  int res = 0,i;
  int x,y;
  if( !res && n>=w && h>2 ) {
    if( solve(w,h-1,n-w) ) {
      nxt[w][h][n] = enc(w,h-1,n-w);
      for( i = 0; i < w; i++ ) s[h-1][i] = '*';
      return 1;
      //res = 1;
    }
  }
  if( !res && n>=h && w>2 ) {
    if( solve(w-1,h,n-h) ) {
      for( i = 0; i < h; i++ ) s[i][w-1] = '*';
      return 1;
      //res = 1;
    }
  }
  if( n < w && n < h ) {
    if( n == 0 ) {
      for( y = 0; y < h; y++ ) {
        for( x = 0; x < w; x++ ) s[y][x] = '.';
      }
      s[0][0] = 'c';
      return 1;
    } else {
      for( i = 0; i < n; i++ ) {
        //printf("%d %d %d %d %d %d\n",w-i,h-(n-i),i,w,h,n);
        if( w-i >= 3 && h-((n-1)-(i)) >= 3 ) {
          //puts("aaaaa");
          //printf("%d\n",i);
          for( y = 0; y < h; y++ ) {
            for( x = 0; x < w; x++ ) s[y][x] = '.';
          }
          s[h-1][w-1] = '*';
          for( x = 0; x < i; x++ ) s[h-1][w-x-1-1] = '*';
          for( y = 0; y < ((n-1)-(i)); y++ ) s[h-y-1-1][w-1] = '*';
          s[0][0] = 'c';
          /*
            for( y = 0; y < h; y++ ) {
            for( x = 0; x < w; x++ ) printf("%c",s[y][x]);
            puts("");
            }*/
          return 1;
        }
      }
    }
  }
  return uu[w][h][n]=0;
}

int aaa(int w,int h,int n)
{
  int i,j;
  if( w == 1 || h == 1 ) {
    if( w == 1 ) {
      for( i = 0; i < h; i++ ) {
        if( i < n ) s[i][0] = '*';
        else s[i][0] = '.';
      }
      s[h-1][0] = 'c';
    }
    if( h == 1 ) {
      for( i = 0; i < w; i++ ) {
        if( i < n ) s[0][i] = '*';
        else s[0][i] = '.';
      }
      s[0][w-1] = 'c';
    }
    return 1;
  }  
  if( w*h-n == 1 ) {
    for( i = 0; i < h; i++ ) {
      for( j = 0; j < w; j++ ) s[i][j] = '*';
    }
    s[0][0] = 'c';
    return 1;
  }
  return solve(w,h,n);
}

int main(void)
{
  int T,ttt;
  int h,w,m,i,j,k;
  scanf("%d",&T);
  //printf("%d\n",solve(2,3,0));
  /*
  for( i = 1; i <= 5; i++ ) {
    for( j = i; j <= 5; j++ ) {
      for( k = 0; k <= i*j; k++ ) {
        printf("%dx%d %d %d\n",i,j,k,aaa(i,j,k));
      }
    }
  }//*/
  for(ttt=1;ttt<=T;ttt++){
    printf("Case #%d:\n",ttt);
    memset(uu,-1,sizeof(uu));
    scanf("%d%d%d",&h,&w,&m);
    if( aaa(w,h,m) ) {
      //puts("possible");
      for( i = 0; i < h; i++ ) {
        for( j = 0; j < w; j++ ) printf("%c",s[i][j]);
        puts("");
      }
    } else {
      puts("Impossible");
    }
  }
  return 0;
}
