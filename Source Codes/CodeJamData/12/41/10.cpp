#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<"="<<(x)<<endl;

int d[10002], l[10002];
int dp[10002];

void eval(){
    int N;
    int D;
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>d[i]>>l[i];
    }
    cin>>D;
    d[0]=l[0]=0;
    d[N+1]=D;
    l[N+1]=0;
    N+=2;
    dp[1]=d[1];
    for(int i=2; i<N; i++)
    {
        dp[i]=-1;
        for(int j=0; j<i; j++)
        {
            if(dp[j]+d[j]>=d[i])
            {
                dp[i]=d[i]-d[j];
                break;
            }
        }
        dp[i]=min(dp[i], l[i]);
    }
    cout<<(dp[N-1]==0 ? "YES":"NO")<<endl;
}

int main(){
	int cases;
	string line;
	getline(cin, line);
	istringstream(line)>>cases;
	for(int i=1; i<=cases; i++){
		cout<<"Case #"<<i<<": ";
		eval();
	}
	return 0;
}
