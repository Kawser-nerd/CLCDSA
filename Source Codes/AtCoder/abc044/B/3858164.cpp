//https://atcoder.jp/contests/abc044/tasks/abc044_b
//044-B?C++??????
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main(void){
    string w; cin >> w;
    map<char,int> mp;
    int i;
    for (i = 0; i < w.size(); i++){
        mp[w[i]] += 1;
    }

    for (pair<char,int> x :mp){
        if (x.second%2 != 0){
            cout << "No" << endl; return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}