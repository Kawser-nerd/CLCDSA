#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    cout << std::fixed << std::setprecision(10);
    std::string s;
    std::string answer;
    cin >> s;
    for (int i = 1; i <= (int)s.size(); i++)
    {
        if (i % 2 == 1)
        {
            answer += s[i - 1];
        }
    }
    cout << answer << endl;

    return 0;
}