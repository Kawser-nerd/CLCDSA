#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int time[100];
    for (int i = 0; i <= 100; ++i) {
        time[i] = 0;
    }


    for (int i = A; i < B; ++i) {
        ++time[i];
    }

    for (int i = C; i < D; ++i) {
        ++time[i];
    }

    int counter = 0;
    for (int i = 0; i <= 100; ++i) {

        if (time[i] == 2) {
            ++counter;
        }
    }

    cout << counter;
}