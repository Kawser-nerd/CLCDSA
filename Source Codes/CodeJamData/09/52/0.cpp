#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
}

#define MOD 10009

static int n, k;
static int dict[100][26];

map<string, int> cache[12];

static int solve(const string &letters, int k)
{
    if (cache[k].count(letters))
        return cache[k][letters];

    int &ans = cache[k][letters];

    if (letters.empty())
    {
        ans = 1;
        for (int i = 0; i < k; i++)
            ans = (ans * n) % MOD;
        return ans;
    }
    if (k == 0) return 0;

    int L = SZ(letters);
    ans = 0;
    for (int bm = 0; bm < (1 << L); bm++)
    {
        string letters1;
        string letters2;
        for (int i = 0; i < L; i++)
        {
            if (bm & (1 << i))
                letters1 += letters[i];
            else
                letters2 += letters[i];
        }

        int mult = solve(letters2, k - 1);
        int sum = 0;
        for (int w = 0; w < n; w++)
        {
            int prod = 1;
            for (int j = 0; j < SZ(letters1); j++)
            {
                prod *= dict[w][letters1[j] - 'a'];
                prod %= MOD;
            }
            sum += prod;
            sum %= MOD;
        }
        ans = (ans + sum * mult) % MOD;
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        memset(dict, 0, sizeof(dict));

        string polystr;
        cin >> polystr >> k >> n;
        assert(n <= 100);
        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            for (int j = 0; j < SZ(word); j++)
                dict[i][word[j] - 'a']++;
        }

        for (int i = 0; i <= k; i++)
            cache[i].clear();

        for (int i = 0; i < SZ(polystr); i++)
            if (polystr[i] == '+') polystr[i] = ' ';
        vector<string> polys;
        splitstr(polystr, polys);

        printf("Case #%d:", cas + 1);

        for (int i = 1; i <= k; i++)
        {
            int total = 0;
            for (int j = 0; j < SZ(polys); j++)
                total = (total + solve(polys[j], i)) % MOD;
            printf(" %d", total);
        }
        printf("\n");
    }
    return 0;
}
