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
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

string s;
int pos;

bool judge(string str){
    if(s.find(str, pos) == pos){
        pos += str.size();
        if(str == "dreamer" && pos != s.size() && s[pos] == 'a'){
            pos -= str.size();
            return false;
        }
        return true;
    }
    return false;
}

int main(){
    cin >> s;
    while(1){
        int ppos = pos;
        if(judge("dreamer")){ continue; }
        if(judge("dream")){ continue; }
        if(judge("eraser")){ continue; }
        if(judge("erase")){ continue; }
        if(pos == s.size()){
            cout << "YES" << endl;
            return 0;
        }
        if(pos == ppos){ break; }
    }
    cout << "NO" <<endl;
    return 0;
}