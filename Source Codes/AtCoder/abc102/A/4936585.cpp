#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;
int gcd(int a,int b){
   if(b==0)return a;
   return gcd(b,a%b);
}
long long lcm(int a,int b){
   return (long long)a*b/(long long)gcd(a,b);
}


int main(){
    int n;
    cin>>n;
    cout<<lcm(2,n)<<endl;
    
    
}