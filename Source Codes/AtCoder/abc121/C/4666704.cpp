#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;
int main(){
    int n,m;
    map <long long,int> ab;
    cin >> n >> m;
    vector<long long> a;
    long long q;
    int p;
    for(int i = 0;i<n;i++){
        cin >> q >> p;
        auto itr = ab.find(q);
        if(itr != ab.end()){
            ab[q] = ab[q] + p;
        }
        else{
            ab[q] = p;
            a.push_back(q);
        }
    }
    sort(a.begin(),a.end());
    long long ans = 0;
    int j = 0;
    while(m > 0){
        if(m > ab[a[j]]){
            ans = ans + a[j]*ab[a[j]];
            m = m - ab[a[j]];
        }
        else{
            ans = ans + a[j]*m;
            m = 0;
        }
        j++;
    }
    cout << ans << endl;
}