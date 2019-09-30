//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


int main(){
    string s;
    cin>>s;
    if(s.size()==1 or s.size()==1 ){cout<<"-1 -1"<<endl; return 0;}
    if(s[0]==s[1]){cout<<1<<" "<<2<<endl;return 0;}
    for(int i=0;i<s.size()-2;i++){
        if(s[i]==s[i+1] or s[i]==s[i+2] ) {cout<<i+1<<" "<<i+3<<endl;return 0;}
        }
    cout<<"-1 -1"<<endl;
    return 0;
};