#include<iostream>

using namespace std;

int main(){
    char A,B;
    cin >> A >> B;
    if(A < B){
        cout << "<" << endl;
    }else if(A > B){
        cout << ">" << endl;
    }else{
        cout << "=" << endl;
    }
}