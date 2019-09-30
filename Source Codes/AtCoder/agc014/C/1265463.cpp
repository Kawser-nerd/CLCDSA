#include<cstdio>
#include<algorithm>
#include<iostream>
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,r,l) for(int i = r; i >= l; i--)
using namespace std;

const int MAXN = 810;

int s[MAXN][MAXN],map[MAXN][MAXN],n,m,k,l,r;
int qx[MAXN*MAXN],qy[MAXN*MAXN];
int ans = 9999999;

char getChar(){
  char ch = '\n';
  while(ch == '\n' || ch == '\r'){
    ch = getchar();
  }
  return ch;
}

int min(int x, int y){
  return x < y ? x : y;
}

int calc(int x,int y){
  int res = min(x-1,y-1);
  res = min(n-x,res);
  res = min(m-y,res);
  return res;
}

void update(int x,int y){
  ans = min(ans,calc(x,y));
}

void push(int x,int y,int step){
  if(map[x][y] != '.') return;
  map[x][y] = 'S';
  s[x][y] = step;
  r = r + 1;
  qx[r] = x;
  qy[r] = y;
  update(x,y);
}

int main(){
  scanf("%d %d %d\n",&n,&m,&k);
  FOR(i,1,n)
    FOR(j,1,m) {
    map[i][j] = getChar();
    if(map[i][j] == 'S'){
      qx[0] = i; qy[0] = j;
      update(i,j);
    }
  }
  l = 0; r = 0;
  while(l <= r){
    int x = qx[l], y = qy[l];
    int step = s[x][y] + 1;
    if(step > k) break;
    if(x > 1) push(x-1,y,step);
    if(x < n) push(x+1,y,step);
    if(y > 1) push(x,y-1,step);
    if(y < m) push(x,y+1,step);
    l = l + 1;
  }
  ans = ans + k - 1;
  if(calc(qx[0],qy[0]) == 0){
    printf("0");
  }else{
    printf("%d",ans/k + 1);
  }
  return 0;
}