#include <iostream>

using namespace std;

int main() {
    int numbers[11] = {0};
    int A, B, C;
    cin >> A >> B >> C;
    numbers[A] += 1;
    numbers[B] += 1;
    numbers[C] += 1;
    if(numbers[5] == 2 and numbers[7] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}