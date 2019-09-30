#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>

using namespace std;

const int shift=22;
const unsigned long mm=(1UL<<shift)-1UL;

unsigned char c[500][501];
//unsigned int field[500][500];

int R,C,D;

bool do_square(int i, int j, int size)
{
  unsigned long mcx=0;
  unsigned long mcy=0;
  unsigned long m=0;
  for(int x=0;x<size;++x){
    for(int y=0;y<size;++y){
      mcx += (c[i+x][j+y] - '0')*(i+x);
      mcy += (c[i+x][j+y] - '0')*(j+y);
      m += (c[i+x][j+y] - '0');
    }
  }
  mcx -= (c[i+0][j+0] - '0')*(i+0);
  mcx -= (c[i+size-1][j+0] - '0')*(i+size-1);
  mcx -= (c[i+0][j+size-1] - '0')*(i+0);
  mcx -= (c[i+size-1][j+size-1] - '0')*(i+size-1);

  mcy -= (c[i+0][j+0] - '0')*(j+0);
  mcy -= (c[i+size-1][j+0] - '0')*(j+0);
  mcy -= (c[i+0][j+size-1] - '0')*(j+size-1);
  mcy -= (c[i+size-1][j+size-1] - '0')*(j+size-1);

  m -= (c[i+0][j+0] - '0');
  m -= (c[i+size-1][j+0] - '0');
  m -= (c[i+0][j+size-1] - '0');
  m -= (c[i+size-1][j+size-1] - '0');

  mcx *= 2;
  mcy *= 2;

  if(mcx != m*(2*i+size-1)) return false;
  if(mcy != m*(2*j+size-1)) return false;

  return true;
}

void do_case(void)
{
  cin>>R>>C>>D;
  for(int i=0;i<R;++i) cin>>c[i];

  int maxsize = R < C ? R : C;
  for(int size=maxsize;size>=3;--size){
    for(int i=0;i<=R-size;++i){
      for(int j=0;j<=C-size;++j){
        if(do_square(i, j, size)) {
          cout<<size<<'\n';
          return;
        }
      }
    }
  }
  cout<<"IMPOSSIBLE\n";
}

int main()
{
  freopen("input.data", "r", stdin);
  //freopen("output.data", "r", stdout);

  int cases;
  cin>>cases;
  int i = 1;
  do{
    printf("Case #%d: ", i);
    do_case();
  }while(++i <= cases);

  return 0;
}
