#include <iostream>
using namespace std;

int main(){
    int A,B;
    char op;

    cin >> A >> op >> B;
    
    cout << (op == '+' ? A + B : A - B) << endl;

    return 0;
}