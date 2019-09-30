#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main(){
    ll X,A,B,N, K,sum=0,l=0,r=0, tmp = 1000000000000000000LL;;
    cin >> X >> A >> B;
    if(B-A <= 0){
        cout << "delicious" << endl;
    }
    else if(B-A <= X){
        cout << "safe" << endl;
    }else{
        cout << "dangerous" << endl;
    }
}