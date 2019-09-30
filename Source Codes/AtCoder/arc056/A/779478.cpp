#include <iostream>
using namespace std;
int main(void){
    long A, B, K, L;
    cin >> A >> B >> K >> L;
    long a = K / L;
    cout << min({A * K, a * B + (K % L) * A, (a + 1) * B}) << endl;
}