#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    int n, m, p1, p2, ans;
    ans = 0;
    cin >> n >> m;
    vector<set<int>> path;
    vector<int> p;
    path.resize(n+1);
    for(int i=0; i<m; ++i){
        cin >> p1 >> p2;
        path[p1].insert(p2);
        path[p2].insert(p1);
    }
    for(int i=1; i<=n; ++i){
        p.push_back(i);
    }
    do {
        if(p[0] != 1){
            break;
        }
        for(int i=0; i<n; ++i){
            if(i == n-1){
                ans++;
            }
            else if(path[p[i]].find(p[i+1]) == path[p[i]].end()){
                break;
            }
        }
    } while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}