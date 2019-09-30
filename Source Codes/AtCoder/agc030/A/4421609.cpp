#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    long long n=0,a,b,c;
    cin>>a>>b>>c;
    n+=b;
    n+=min(a+b+1,c);
    cout<<n<<endl;
}