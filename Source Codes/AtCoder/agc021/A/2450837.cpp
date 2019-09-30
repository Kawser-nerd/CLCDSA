#include <iostream>
#include <algorithm>
#include <string>
#include <functional> 
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <cstdlib>
typedef long long ll;
#define fi first
#define se second

using namespace std;

int main(){

    string n;
    cin >> n;
    int ans1,ans2=0;
    if(n[0] == '9'){
        ans1 = n.size()*9 -1;
    }else{
        int a = n[0] - '0';
        ans1 = n.size()*9 - 9 + a-1;
    }
    for(int i=0;i<n.size();i++){
        ans2 += n[i] -'0';
    }
    
    cout << max(ans1,ans2);

    return 0;
}