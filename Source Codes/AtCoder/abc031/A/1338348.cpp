#include <iostream>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    cout << max((A+1)*B, (B+1)*A) << endl;

    return 0;
        
}