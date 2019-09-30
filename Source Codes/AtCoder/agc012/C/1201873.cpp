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
#include <queue>

#define fr first
#define sc second
#define mk make_pair

using namespace std;

long long n;
vector<int> vec;

int main()
{
    deque<int> ans;
    cin >> n;
    while(n)
    {
        if(n % 2 == 1)
        {
            vec.push_back(1);
            n = n / 2;
        }else
        {
            vec.push_back(0);
            n--;
        }
    }

    int p = 1;
    for(int i = vec.size() - 1; i >= 0; i--)
    {
        if(vec[i] == 1)
        {
            ans.push_back(p);
        }else
        {
            ans.push_front(p);
        }
        p++;
    }
    cout << ans.size() * 2 << endl;
    while(!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop_front();
    }

    for(int i = 1; i < p; i++)
        cout << i << " ";
    return 0;
}