#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int p;
    map<int,int> b;
    int c[n];
    for(int i = 0;i<n;i++){
        cin >> p;
        b[i+1] = p;
        c[i] = p;
    }
    bool flag = true;
    bool flag2 = false;
    int q = 0;
    int ans[n];
    while(q<n){
        for(int i = 0;i<n;i++){
            if(b[n-i] == n-i){
                for(int j = n-i+1;j<n+1;j++){
                    b[j]++;
                }
                ans[q] = c[n-i-1];
                b[n-i] = 120;
                flag2 = true;
                break;
            }
        }
        if(flag2 == false){
            flag = false;
            break;
        }
        else{
            q++;
            flag2 = false;
        }
    }
    if(flag != true){
        cout << -1 << endl;
    }
    else{
        for(int i = 0;i<n;i++){
            cout << ans[n-1-i] << endl;
        }
    }
}