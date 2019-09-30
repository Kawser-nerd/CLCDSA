#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

// "A"

typedef map<string, long long int> Back3;
typedef map<int, Back3> Memo;
Memo result_memo;
string given = "AGTC";
long long int mod = 1e9 + 7;

int ok(string str)
{
    if (str.find("AGC") != string::npos)
    {
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        string t = str;
        char tmp = t[i];
        t[i] = t[i + 1];
        t[i + 1] = tmp;
        if (t.find("AGC") != string::npos)
        {
            return false;
        }
    }
    return true;
}

long long int memoRet(int cur, string back3, int N)
{
    if (result_memo[cur].find(back3) != result_memo[cur].end())
    {
        return result_memo[cur][back3];
    }
    if (cur == N)
    {
        return 1;
    }

    long long int ret = 0;

    for (int i = 0; i < 4; i++)
    {
        string str = back3 + given[i];
        if (ok(str))
        {
            ret = ret + memoRet(cur + 1, str.substr(1), N);
        }
    }
    result_memo[cur][back3] = ret % mod;
    return ret % mod;
}

int main()
{
    int N;
    cin >> N;
    long long int ret = memoRet(0, "TTT", N);
    cout << ret << endl;
    return 0;
}