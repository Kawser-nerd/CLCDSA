#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
#include <cmath>
#include <cassert>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define show(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll mergecount(vector<int> &a) {
  ll count = 0;
  int n = a.size();
  if (n > 1) {
    vector<int> b(a.begin(), a.begin() + n/2);
    vector<int> c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (int i = 0, j = 0, k = 0; i < n; ++i)
      if (k == c.size())       a[i] = b[j++];
      else if (j == b.size())  a[i] = c[k++];
      else if (b[j] <= c[k])   a[i] = b[j++];
      else                   { a[i] = c[k++]; count += n/2 - j; }
  }
  return count;
}
int main(){
    string S;
    cin >> S;
    int N = (int) S.size();
    vector<int>A;
    int cnt[26] = {};
    rep(i,N){
        A.push_back(S[i]-'a');
        cnt[A[i]]++;
    }
    int man = -1;
    rep(i,26){
        if(cnt[i] % 2){
            if(man != -1){
                cout << -1 << endl;
                return 0;
            }
            man = i;
        }
    }
    vector<int>B;
    vector<int>C;
    vector<bool>used(N,false);
    int cnt2[26] = {};
    rep(i,N){
        if(cnt[A[i]]/2 > cnt2[A[i]]){
            cnt2[A[i]]++;
            used[i] = true;
            B.push_back(A[i]);
            C.push_back(A[i]);
        }
    }
    if(man!=-1)B.push_back(man);
    if(man!=-1)C.push_back(man);
    rep(i,N){
        if(!used[i] and A[i] == man){
            used[i] = true;
            break;
        }
    }
    rep(i,N){
        if(!used[i])B.push_back(A[i]);
    }
    rep(i,N/2){
        C.push_back(C[N/2-i-1]);
    }
    vector<int>D[26];
    vector<int>E(N);
    rep(i,N){
        D[A[i]].push_back(i);
    }
    rep(i,26)reverse(D[i].begin(),D[i].end());
    // show(A.size());
    // rep(i,N){
    //     cout << A[i] <<  " ";
    // }
    // cout << endl;
    // show(C.size());
    // rep(i,N){
    //     cout << C[i] << " ";
    // }
    // cout << endl;
    rep(i,N){
        E[i] = D[C[i]].back();
        D[C[i]].pop_back();
    }
    cout << mergecount(E) << endl;
}