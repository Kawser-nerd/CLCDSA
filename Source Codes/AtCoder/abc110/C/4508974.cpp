#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<int> abcd(string a){
    vector<int> alp;
    int p;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0;i<26;i++){
        p = 0;
        for(int j = 0;j<a.size();j++){
            if(a[j] == alpha[i]){
                p++;
            }
        }
        alp.push_back(p);
    }
    return alp;
}
int main(){
    string s,t;
    cin >> s >> t;
    vector<int> sal = abcd(s);
    vector<int> tal = abcd(t);
    sort(sal.begin(),sal.end());
    sort(tal.begin(),tal.end());
    string ans = "Yes";
    for(int i = 0;i<26;i++){
        if(sal[i] != tal[i]){
            ans = "No";
            break;
        } 
    }
    cout << ans << endl;
}