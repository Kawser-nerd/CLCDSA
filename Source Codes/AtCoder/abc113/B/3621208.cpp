#include <iostream>
using namespace std;

double ave_temp, temp_ave_temp_diff, temp, temp_diff;
int X, N, A, T;
int ans_0index;

constexpr double ave_temp_const = 0.006;

inline double calc_ave_temp(double x)
{
    return T - ave_temp_const * x;
}

inline double abs(double x)
{
    return x > 0 ? x : x * -1;
}

inline double calc_ave_temp_diff(double x)
{
    return min(abs(A - calc_ave_temp(x)), abs(calc_ave_temp(x) - A));
}

int main(int argc, char const *argv[])
{
    cin >> N;
    cin >> T >> A;

    cin >> X;
    temp_diff = calc_ave_temp_diff(X);
    ans_0index = 0;
    temp_ave_temp_diff = temp_diff;

    for (int i = 1; i < N; ++i)
    {
        cin >> X;

        temp_diff = calc_ave_temp_diff(X);

        if (temp_ave_temp_diff > temp_diff)
        {
            ans_0index = i;
            temp_ave_temp_diff = temp_diff;
        }
    }

    cout << ans_0index + 1 << endl;
}