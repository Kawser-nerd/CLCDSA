#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> edge[108000];
int cnta, cntb;
int a, b, n;
int la, lb;
int cnt[108000];
bool valid[108000];
void ok(){
  cout << "First" << endl;
  exit(0);
}

int main(){
  cin >> n ;
  for(int i = 0;i < n-1;i++){
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
    cnt[a]++;
    cnt[b]++;
  }

  vector<int> ones;
  for(int i = 1;i <= n;i++){
    if(edge[i].size() == 1)
      ones.push_back(i);
    valid[i] = true;
  }
  
  while(!ones.empty()){
    int x = ones.back();ones.pop_back();
    valid[x] = false;
    for(int i = 0;i < edge[x].size();i++){
      int to = edge[x][i];
      if(!valid[to])continue;
      for(int j = 0;j < edge[to].size();j++){
	int tto = edge[to][j];
	if(!valid[tto])continue;
	cnt[tto]--;
	if(cnt[tto] == 0)ok();
	if(cnt[tto] == 1)ones.push_back(tto);
      }
      valid[to] = false;
      
    }
  }
  cout << "Second" << endl;
  return 0;
}