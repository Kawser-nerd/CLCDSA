#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
//?????
int gcd(int a,int b){
    if(b > a){
        swap(a,b);
    }
    bool flag = true;
    int gcdl;
    while(flag){
        if(a%b == 0){
            flag = false;
            gcdl = b;
        }
        else{
            swap(a,b);
            b = b % a;
        }
    }
    return gcdl;
}
int main(){
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }   
    long long tem = gcd(a[0],a[1]);
    for(int i = 2;i<n;i++){
        tem = gcd(tem,a[i]);
    }
    cout << tem << endl;
}