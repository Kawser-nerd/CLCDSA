#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N, P;
    cin >> N >> P;
    int odds = 0, evens = 0, tmp;
    long long evens_x = 0, odds_x = 0;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp % 2 == 0) evens++;
        else odds++;
    }

    evens_x = (long long)pow(2, evens);

    if (odds == 0 && P == 0) {
        cout << (long long)(evens_x) << endl;
    } else if (odds == 0 && P == 1) {
        cout << 0 << endl;
    } else {
        odds_x = (long long)pow(2, odds - 1);

        cout << (long long)(evens_x * odds_x) << endl;
    }

    return 0;
}