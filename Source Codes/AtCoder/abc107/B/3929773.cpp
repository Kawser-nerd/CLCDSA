#include <iostream>
#include <vector>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<int>hc(h), wc(w);
  vector<vector<char>>grid(h, vector<char>(w));
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    cin >> grid[i][j];
    if(grid[i][j]=='.'){
      hc[i]++;
      wc[j]++;
    }
  }
  for(int i=0; i<h; i++){
    if(hc[i]==w)continue;
    for(int j=0; j<w; j++){
      if(wc[j]==h)continue;
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}