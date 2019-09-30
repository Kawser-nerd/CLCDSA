#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

string s;
int cnt;
bool tsumu(string ab){
    int idx = 0;
    for(uint i=0;i<s.size();i++){
        if(s[i] == ab[idx % 2]){
            idx++;
        }else if(cnt == 0 && i != s.size() - 1){
            cnt++;
        }else{
            // cout << (s.size() % 2 == 0 ? "Second" : "First") << endl;
            // return 0;
            return false;
        }
    }
    return true;
}

int main(){
    cin >> s;
    if(s.front() == s.back()){
        cout << (s.size() % 2 == 0 ? "First" : "Second") << endl;
    }else{
        cout << (s.size() % 2 == 0 ? "Second" : "First") << endl;
    }
    return 0;
    map<char, int> cs;
    for(char c : s){
        cs[c]++;
    }
    for(uint i=1;i<s.size()-1;i++){
        if(s[i-1] != s[i+1]){
            s.erase(i);
        }
    }
    if(cs.size() == 2){
        cout << "Second" << endl;
        return 0;
    }
    char c1 = s[0], c2 = s[1];
    // string ab = {c1, c2};
    // tsumu({c1, c2});
    if(!tsumu({c1, c2})){
        cnt = 0;
        if(!tsumu({s[0], s[2]})){
            cout << (s.size() % 2 == 0 ? "Second" : "First") << endl;
            return 0;
        }else{
            cout << (cnt == 0 ? "Second" : "First") << endl;
        }
    }else{
        cout << (cnt == 0 ? "Second" : "First") << endl;
    }
    return 0;
}