#include <iostream>
using namespace std;

int main() {
    int N, A; cin >> N >> A;
    int nN = N / 500;
    nN = N - nN * 500;
    if (nN <= A)  {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}