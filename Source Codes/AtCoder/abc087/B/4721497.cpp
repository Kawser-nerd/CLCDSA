#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int result = 0;
    for (int c_i = 0; c_i <= c; ++c_i)
        for (int b_i = 0; b_i <= b; ++b_i)
            for (int a_i = 0; a_i <= a; ++a_i)
                if (50 * c_i + b_i * 100 + 500 * a_i == x)
                    ++result;

    cout << result << endl;

    return 0;
}