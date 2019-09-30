#include <iostream>
#include <algorithm>
using namespace std;
int n,cnt=0;
int main(void){
    cin>>n;
    n<<=1;
    int a[n];
    for(auto& i:a)cin>>i;
    sort(a,a+n);
    for(int i=-2;(i+=2)-n;)cnt+=a[i];
    cout<<cnt<<endl;
    return 0;
}