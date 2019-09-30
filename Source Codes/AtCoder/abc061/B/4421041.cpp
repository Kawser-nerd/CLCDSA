#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define LL long long 
char d[105][105];

int main(){
    int n, m;
    int a,b,c;
    LL H, W;
    LL ans = 1e18;
    cin >> n >> m;
    vector< vector<int> > E(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--,b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        cout<< E[i].size() << endl;
    }  

}