#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    if (n % 111 == 0){
        cout << n << endl;
    }else{
        cout << n / 111 * 111 + 111 << endl;
    }
}