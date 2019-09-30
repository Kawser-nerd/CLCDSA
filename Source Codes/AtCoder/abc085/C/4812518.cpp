#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {

    int N, Y;
    cin >> N >> Y;

    int mai10000 = -1;
    int mai5000 = -1;
    int mai1000 = -1;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j + i <= N; ++j) {
            int k = N - i - j;
            int total = 10000 * i + 5000 * j + 1000 * k;
            if (total == Y) {
                mai10000 = i;
                mai5000 = j;
                mai1000 = k;
            }
        }
    }

    cout << mai10000 << " " << mai5000 << " " << mai1000 << endl;
}