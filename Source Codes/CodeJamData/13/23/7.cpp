#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int DICT_SIZE = 521196, DIST = 5;

ifstream fdict("garbled_email_dictionary.txt");
vector<string> dict;
map<string, vector<string> > prefix_to_word;

void add_prefix_to_word(string prefix, string word)
{
    if (prefix_to_word.find(prefix) == prefix_to_word.end())
        prefix_to_word[prefix] = vector<string>();

    prefix_to_word[prefix].push_back(word);
}

void initialize()
{
    string x;

    while (fdict >> x)
        dict.push_back(x);

    assert((int) dict.size() == DICT_SIZE);

    for (int i = 0; i < (int) dict.size(); i++)
    {
        string word = dict[i];

        if ((int) word.length() <= DIST)
            add_prefix_to_word(word, word);
        else
            add_prefix_to_word(word.substr(0, DIST), word);
    }
}

const int S_MAX = 4005, INF = 1000000005;

int N;
string S;
int dp[S_MAX][DIST];

vector<string> change_one(string str)
{
    vector<string> strings;
    strings.push_back(str);

    for (int i = 0; i < (int) str.length(); i++)
        for (char c = 'a'; c <= 'z'; c++)
            if (c != str[i])
            {
                swap(str[i], c);
                strings.push_back(str);
                swap(str[i], c);
            }

    return strings;
}

pair<int, int> acceptable(string word, string sub, int d)
{
    int last = -1 - d;
    int mismatches = 0;

    for (int i = 0; i < (int) word.length(); i++)
        if (word[i] != sub[i])
        {
            if (i - last < DIST)
                return make_pair(-1, -1);

            last = i;
            mismatches++;
        }

    return make_pair(min((int) word.length() - 1 - last, DIST - 1), mismatches);
}

void solve_case(int test_case)
{
    cin >> S;
    N = S.length();
    memset(dp, 63, sizeof(dp));
    dp[0][DIST - 1] = 0;

    for (int n = 0; n < N; n++)
        for (int d = 0; d < DIST; d++)
            if (dp[n][d] < INF)
                for (int len = 1; len <= DIST; len++)
                {
                    vector<string> prefixes = change_one(S.substr(n, len));

                    for (int p = 0; p < (int) prefixes.size(); p++)
                    {
                        const vector<string> &words = prefix_to_word[prefixes[p]];

                        for (int w = 0; w < (int) words.size(); w++)
                        {
                            string word = words[w];

                            if (n + (int) word.length() > N)
                                continue;

                            pair<int, int> result = acceptable(word, S.substr(n, word.length()), d);

                            if (result.first != -1)
                            {
                                int new_n = n + word.length(), new_d = result.first;
                                dp[new_n][new_d] = min(dp[new_n][new_d], dp[n][d] + result.second);
                            }
                        }
                    }
                }

    int best = INF;

    for (int d = 0; d < DIST; d++)
        best = min(best, dp[N][d]);

    printf("Case #%d: %d\n", test_case, best);
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
