#include<iostream>
#include<vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
    int a,b,k,r;
    cin >> a >> b >> k;
    swap(a,b);
    while ((r=a%b)) {
    a = b;
    b = r;
    }
    vector<int> ans;
    for(int i=1;i<=b;i++){
        if(b%i==0)
        ans.push_back(i);
    }
    sort(ans.begin(),ans.end(),greater<int>());
    cout << ans[k-1] <<endl;
    return 0;
}