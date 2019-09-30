#include<iostream>
using namespace std;
 
int main(void){
    long long A, B, C, K;
    cin >> A >> B >> C >> K;
    if (K%2){
        cout << B-A << endl;
    }else{
        cout << A-B << endl;
    }
    return 0;
}