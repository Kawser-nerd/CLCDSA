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
#include <array>
#include <fstream>

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

    ios::sync_with_stdio(false);
}

static vector<string> words;

static void load_dict()
{
    ifstream in("garbled_email_dictionary.txt");
    string word;
    while (in >> word)
        words.push_back(word);
}

static int solve(const string &garbled)
{
    int L = SZ(garbled);
    typedef array<int, 6> col;
    col bad;
    fill(RA(bad), INT_MAX / 2);
    vector<col> dp(L + 1, bad);
    fill(RA(dp[0]), 0);
    for (int i = 1; i <= L; i++)
    {
        for (const string & d : words)
        {
            int P = SZ(d);
            int start = i - P;
            if (start < 0)
                continue;
            int first = INT_MAX / 4, last = INT_MIN / 2, wrong = 0;
            for (int j = 0; j < P; j++)
                if (d[j] != garbled[start + j])
                {
                    if (j - last < 5)
                        goto bad;
                    if (first > j)
                        first = j;
                    last = j;
                    wrong++;
                }
            if (wrong == 0)
            {
                for (int j = 0; j <= 5; j++)
                    dp[i][j] = min(dp[i][j], dp[i - P][max(j - P, 0)]);
            }
            else
            {
                int x = max(0, 4 - first);
                int y = min(P - 1 - last, 5);
                for (int j = 0; j <= y; j++)
                    dp[i][j] = min(dp[i][j], dp[i - P][x] + wrong);
            }
bad:;
        }
    }
    return dp[L][0];
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    load_dict();

    int cases;
    cin >> cases;
    vector<string> garbled(cases);
    vector<int> ans(cases);
    for (int cas = 0; cas < cases; cas++)
    {
        cin >> garbled[cas];
    }
#pragma omp parallel for
    for (int cas = 0; cas < cases; cas++)
    {
        ans[cas] = solve(garbled[cas]);
    }
    for (int cas = 0; cas < cases; cas++)
    {
        cout << "Case #" << cas + 1 << ": " << ans[cas] << "\n";
    }
    return 0;
}
