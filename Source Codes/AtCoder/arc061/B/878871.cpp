#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

long long A[100001], B[100001];
map<pair<long long, long long>, int> black;

int main(){
  int H,W,N;
  cin >> H >> W >> N;
  int dx[] = {-1,-1,-1,0,0,0,1,1,1};
  int dy[] = {-1,0,1,-1,0,1,-1,0,1};
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i];
    A[i] = A[i]-1;
    B[i] = B[i]-1;
    for(int d=0; d<9; d++){
      long long x = A[i]+dx[d];
      long long y = B[i]+dy[d];
      if(0<x&&x<H-1&&0<y&&y<W-1){
        black[make_pair(x,y)]++;
      }
    }
  }

  long long res[10];
  res[0] = (H-2)*(W-2);
  for(int i=1; i<10; i++) res[i] = 0;
  for(auto i=black.begin(); i!=black.end(); i++){
    if(i->first.first==0||i->first.first==H-1||
       i->first.second==0||i->first.second==W-1) continue;
    int n=i->second;
    if(n > 9) cout << "Too many!" << endl;
    if(n < 1) cout << "Too small!" << endl;
    res[n]++;
  }

  for(int i=1; i<10; i++){
    res[0] -= res[i];
  }
  for(int i=0; i<10; i++){
    cout << res[i] << endl;
  }
  return 0;
}