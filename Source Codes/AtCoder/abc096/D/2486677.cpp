#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using max_priority_queue = priority_queue<T>;
template <class T>
using min_priority_queue = priority_queue<T, std::vector<T>, std::greater<T>>;

const int INF = 1 << 29;
const ll LL_INF = 1LL << 60;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int N;
const int MAX_VAL = 55555;
bool is_prime[MAX_VAL + 1];
vector<int> primes;
void sieve()
{
    for (int i = 0; i < MAX_VAL + 1; i++)
    {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_VAL; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAX_VAL; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

bool is_prime_func(int val)
{
    for (int i = 2; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    sieve();
    cin >> N;
    int pos = 2;
    int cnt = 0;
    while (cnt < N)
    {

        if (is_prime[pos] and pos % 5 ==1)
        {
            cnt++;
            cout << pos << " ";
        }
        pos++;
    }
    return 0;
}