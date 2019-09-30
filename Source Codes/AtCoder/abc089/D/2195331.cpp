#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

#define MAX 310

using namespace std;

typedef long long int Int;

int H,W,D;
int Q;

map<int,pair<int,int> > A;

int px[MAX*MAX],py[MAX*MAX];
int dp[MAX*MAX];

int main(void) {
    cin>>H>>W>>D;
    for(int i = 1;i <= H;i++) {
        for(int j = 1;j <= W;j++) {
            int temp;
            cin>>temp;
            px[temp] = j;
            py[temp] = i;
        }
    }

    for(int i = D+1;i <= W*H;i++) {
      dp[i] = dp[i-D]+abs(px[i]-px[i-D])+abs(py[i]-py[i-D]);
    }

    cin>>Q;

    for(int i = 0;i < Q;i++) {
        int l,r;
        cin>>l>>r;
        cout<<dp[r]-dp[l]<<endl;
    }

    return 0;
}