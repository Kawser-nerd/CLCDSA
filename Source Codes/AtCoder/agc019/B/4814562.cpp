#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <functional>
#include <numeric>
#include <cstring>

using namespace std;

string A, B;

long long cnt[26];
int main()
{
    cin >> A;
    long long N = A.length();
    for (int i = 0; i < N;i++)
    {
        cnt[A[i] - 'a']++;
    }
    long long palindrome_cnt = 0;
    long long canditate_cnt = (N * (N + 1)) / 2;
    for (int i = 0; i < 26;i++)
    {
        palindrome_cnt += (cnt[i] * (cnt[i] + 1)) / 2;
    }
    long long ans = canditate_cnt - palindrome_cnt;
    cout << ans + 1LL << endl;

    return 0;
}