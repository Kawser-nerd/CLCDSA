#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

#define fr first
#define sc second
#define mk make_pair

using namespace std;

int x, ans = 0, i;

int main()
{
    cin >> x;
    for(i = 1; i <= 1e9; i++)
    {
        if(x <= 0)
            break;
        x = x - i;
        ans++;
    }

    cout << i - 1;
    return 0;
}