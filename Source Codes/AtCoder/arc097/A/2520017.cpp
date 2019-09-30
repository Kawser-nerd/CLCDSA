#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string s;
    int k;
    vector<string> a(0);
    cin >> s >> k;
    for(int i = 0;i<s.length();i++){
        for(int j = 1;j<=k && i+j<=s.length();j++){
            a.push_back(s.substr(i,j));
        }
    }
    sort(a.begin(),a.end());
    unique(a.begin(),a.end());
    cout << a[k-1] << endl;
    return 0;
}