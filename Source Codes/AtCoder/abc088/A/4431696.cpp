#include<iostream>
using namespace std;

int main(){
    int A,N;
    cin >> N >> A;
    if(N%500<=A){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}