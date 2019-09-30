#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max({a,b,c})-min({a,b,c})<<endl;
}