#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include<queue>
#include<stack>
#include<set>

using namespace std;
vector<pair<long long, long long> >V;

long long n, m;
long long a[100005], b[100005];
long long answer;

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
    V.push_back(make_pair(a[i], b[i]));
  }
  sort(V.begin(), V.end());
  long long cnt = m;
  long long place = 0;
  while(cnt > 0){
    if(cnt < V[place].second){
      answer += cnt * V[place].first;
    }else{
      answer += V[place].first * V[place].second;
    }
    cnt -= V[place].second;
    place++;
  }
  cout << answer << endl;
}