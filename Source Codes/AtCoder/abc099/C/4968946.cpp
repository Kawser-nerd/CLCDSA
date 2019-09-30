#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v1;
    int tmp=6;
    v1.push_back(1);
    while(tmp<=100000){
        v1.push_back(tmp);
        tmp*=6;
    }
    tmp=9;
    while(tmp<=100000){
        v1.push_back(tmp);
        tmp*=9;
    }
    
    int ans=0;
    int dp[n+1];
    int inf=1000000;
    for(int i=0; i<=n; i++){
        dp[i]=inf;
    }
    dp[0]=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<v1.size(); j++){
            if(i>=v1[j]){
                dp[i]=min(dp[i], dp[i-v1[j]]+1);
            }
        }
    }
    cout << dp[n] << endl;
    
    return 0;
}