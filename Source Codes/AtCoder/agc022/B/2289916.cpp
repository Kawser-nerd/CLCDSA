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

const int INF = 1 << 29;
const ll LL_INF = 1LL << 60;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int N;
const int MAX_V = 30000;
queue<int> A, B, C;
int main()
{
    cin >> N;
    if (N == 3)
    {
        cout << "2 5 63" << endl;
        return 0;
    }
    if (N == 4)
    {
        cout << "2 5 20 63" << endl;
        return 0;
    }
    if (N == 5)
    {
        cout << "2 5 20 30 63" << endl;
        return 0;
    }
    for (int i = 2; i <= MAX_V; i++)
    {
        if (i % 2 == 0 || i % 3 == 0)
        {
            if (i % 6 == 0)
            {
                A.push(i);
            }
            else if (i % 2 == 0)
            {
                B.push(i);
            }
            else if (i % 3 == 0)
            {
                C.push(i);
            }
        }
    }
    vector<int> results;
    int sum = 0;
    while (results.size() < N)
    {
        int a = A.size() > 0 ? A.front() : 114514;
        int b = B.size() > 0 ? B.front() : 114514;
        int c = C.size() > 0 ? C.front() : 114514;
        if (a < b and a < c)
        {
            results.push_back(a);
            A.pop();
            sum += a;
        }
        if (b < a and b < c)
        {
            results.push_back(b);
            B.pop();
            sum += b;
        }
        if (c < a and c < b)
        {
            results.push_back(c);
            C.pop();
            sum += c;
        }
    }
    // cerr << "sum = " << sum << endl;
    // cerr << A.size() << " " << B.size() << " " << C.size() << endl;
    //2,3,4,6,8,9
    if (sum % 6 == 2)
    {
        for (int i = 0; i < N; i++)
        {
            if (results[i] == 8)
            {
                assert(A.size());
                sum -= results[i];
                results[i] = A.front();
                sum += results[i];
                break;
            }
        }
    }
    else if (sum % 6 == 3)
    {

        for (int i = 0; i < N; i++)
        {
            if (results[i] == 9)
            {
                assert(A.size());
                sum -= results[i];
                results[i] = A.front();
                sum += results[i];
                break;
            }
        }
    }
    else if (sum % 6 == 5)
    {
        for (int i = 0; i < N; i++)
        {
            if (results[i] == 9)
            {
                if (B.size() > 0)
                {
                    // assert(B.size());
                    int b = B.front();
                    B.pop();
                    while (b % 6 != 4)
                    {
                        assert(B.size());
                        b = B.front();
                        B.pop();
                    }
                    sum -= results[i];
                    results[i] = b;
                    sum += results[i];
                }

                break;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}