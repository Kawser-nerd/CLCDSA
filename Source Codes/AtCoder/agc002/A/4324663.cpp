#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    
    cin >> a >> b;
    
    if (a * b <= 0) {
        cout << "Zero" << endl;
    } else if (a > 0) {
        cout << "Positive" << endl;
    } else {
        if ((b - a) % 2 == 0) {
            cout << "Negative" << endl;
        } else {
            cout << "Positive" << endl;   
        }
    }
}