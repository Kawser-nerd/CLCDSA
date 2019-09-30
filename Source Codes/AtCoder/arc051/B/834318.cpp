#include<iostream>

using namespace std;
#define int long long
int counter;
int gcd(int a, int b){
    if(b==0) return a;
    counter++;
    return gcd(b, a%b);
}
signed main(){

    int K;
    cin>> K;

    int fib[45];
    fib[1]=fib[2]=1;
    for(int i=3; i<45; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }

    cout<< fib[K+2]<< " "<< fib[K+1]<< endl;
    return 0;
}