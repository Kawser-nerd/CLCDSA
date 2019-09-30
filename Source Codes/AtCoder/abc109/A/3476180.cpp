#include <iostream>

using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    bool judge = false;
    int x = A * B;
    
    for(int C = 1; C <= 3; C++){
        if(x * C % 2 != 0){
            judge = true;
            break;
        }
    }
    
    if(judge){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}