#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    if(N < 1200){
        cout << "ABC\n";
    }
    else if(N < 2800){
        cout << "ARC\n";
    }
    else{
        cout << "AGC\n";
    }
}