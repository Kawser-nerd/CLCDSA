#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <list>
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
using namespace std;
typedef pair<int,int> P;

int main(void){
    int n,k;
    int x[101];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=2*min(abs(k-x[i]),abs(x[i]));
    }
    cout<<ans<<endl;
    return 0;
}