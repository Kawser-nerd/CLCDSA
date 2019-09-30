#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1030;
ll A[MAX_N][MAX_N];
ll R[MAX_N];

int do_case(){
  int n,p; cin >> n >> p;
  for(int i=0;i<n;i++) cin >> R[i];

  for(int i=0;i<n;i++)
    for(int j=0;j<p;j++)
      cin >> A[i][j];
  for(int i=0;i<n;i++)
    sort(A[i],A[i]+p);

  int ans = 0;
  vector<int> idx(n,0);
  ll curr = 1;
  while(*max_element(idx.begin(),idx.end()) != p){
    for(int i=0;i<n;i++)
      while(A[i][idx[i]] * 100 < curr*90*R[i]){
	idx[i]++;
	if(idx[i] == p)
	  return ans;
      }

    bool good = true;
    for(int i=0;i<n;i++){
      if(!(A[i][idx[i]] * 100 >= curr*90*R[i] &&
	   A[i][idx[i]] * 100 <= curr*110*R[i])){
	good = false;
	break;
      }
    }
    if(good){
      for(int i=0;i<n;i++)
	idx[i]++;
      ans++;
    } else curr++;  
  }
  return ans;
}

int main(){
  int T,C=1; cin >> T;
  while(T--){
    cout << "Case #" << C++ << ": " << do_case() << endl;
  }
}
