#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin  >> N;
    int Ntmp = N;
    int x = 0;

    while(Ntmp != 0) {
        x += Ntmp % 10;
        Ntmp /= 10;
    }

    cout << (N % x == 0 ? "Yes" : "No") << endl;

    return 0;
}