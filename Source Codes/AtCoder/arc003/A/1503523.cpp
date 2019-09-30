#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int GPA['F' + 1];

    GPA['A'] = 4;
    GPA['B'] = 3;
    GPA['C'] = 2;
    GPA['D'] = 1;
    GPA['F'] = 0;

    int N;
    string line;

    cin >> N;
    cin >> line;

    int sum = 0;

    for (char c:line) sum += GPA[c];

    cout << fixed << setprecision(9) << (double) sum / N << endl;
}