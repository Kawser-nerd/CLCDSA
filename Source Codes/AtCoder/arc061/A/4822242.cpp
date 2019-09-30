#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

int main(void)
{
    long long ans = 0;
    string s;
    cin >> s;
    for(int i = 0;i < (1 << (s.size() - 1));i++)
    {
        int tmp = 0;
        for(int j = 0;j < s.size() - 1;j++)
        {
            if(i & (1 << j))
            {
                ans += stoll(s.substr(tmp,j - tmp + 1));
                tmp = j + 1;
            }
        }
        ans += stoll(s.substr(tmp,s.size() - tmp));
    }
    cout << ans << endl;
    return 0;
}