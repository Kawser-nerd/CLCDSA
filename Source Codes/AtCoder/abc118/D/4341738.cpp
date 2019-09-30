//encoding:utf-8
#include<iostream> //c++
#include<time.h> //???????
#include<stack> //????????????????????
#include<queue> //???????????????????
#include<math.h>
#include<vector>
#include<algorithm> //sort ?????
#include<string>
#include <unordered_set>//c++11???

#define ll long long
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<int>can(M);
  for(int i=0;i<M;i++){
    cin>>can[i];
  }
  sort(can.rbegin(),can.rend());
  // vector<int> sticks{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  vector<int> sticks{0,2,5,5,4,5,6,3,7,6};


  vector<int>dp(N+1);
  for(int i=1;i<N+1;i++){
    dp[i]=-1;
  }
  dp[0]=0;
  for(int i=1;i<N+1;i++){
    for (auto x:can){
      if(i>=sticks[x]){
        dp[i] = max(dp[i],dp[i-sticks[x]]+1);
      }
    }
  }


  // ???????????????????????
  // ????????????????????????
  int remain = N;
  while(remain>0){
    for(auto x:can){
      if(dp[remain-sticks[x]]==dp[remain]-1){
        if(dp[remain-sticks[x]]>0 || remain-sticks[x]==0){
          remain -= sticks[x];
          cout<<x;
          break;
        }
      }
    }
  }
  // while (remain > 0) {
  //   // cout<<remain<<endl;
  //     for (auto x:can) {
  //         if (dp[remain - sticks[x]] == dp[remain] - 1)
  //             if (dp[remain - sticks[x]] > 0 || remain - sticks[x] == 0) {
  //                 remain -= sticks[x];
  //                 cout << x;
  //                 break;
  //             }
  //     }
  // }

  cout<<endl;

  return 0;
}