#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> p;
    p.resize(k);
    for(int i = 0; i < k; i++){
        cin >> p[i];
    }

    vector<int> path;
    path.push_back(a);
    for(int i = 0; i < k; i++){
        path.push_back(p[i]);
    }
    path.push_back(b);

    sort(path.begin(), path.end());
    for(int i = 1; i < path.size(); i++){
        if(path[i - 1] == path[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}