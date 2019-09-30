#include<iostream>

using namespace std;

int main(){
    int N,A;
    cin >> N >> A;
    if(N % 500 <= A){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}