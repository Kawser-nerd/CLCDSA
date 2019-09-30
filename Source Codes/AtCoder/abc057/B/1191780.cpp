#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;
int dist(int x1,int y1,int x2,int y2){
  return abs(x1-x2)+abs(y1-y2);
}

int main(){
  int N,M;
  vector<int> a,b,c,d;
  cin >> N >> M;
  a.resize(N);
  b.resize(N);
  c.resize(M);
  d.resize(M);
  for(int i=0;i<N;i++){ cin >> a[i] >> b[i]; }
  for(int j=0;j<M;j++){ cin >> c[j] >> d[j]; }
  for(int i=0;i<N;i++){
    int min=INT_MAX;
    int index=0;
    for(int j=0;j<M;j++){
      int distance = dist(a[i],b[i],c[j],d[j]);
      if(min >  distance ){
         min = distance;
         index=j;
      }
     }
     cout << index+1 << endl;
  }
  return 0;
}