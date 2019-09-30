#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int64_t x,ans;
    cin>>x;
    ans=x/11*2;
    if(x%11>6)ans+=2;
    else if(x%11)ans++;
    cout<<ans<<endl;
    return 0;
}