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

int n, ar[1000001];

int main()
{
    cin >> n;
    for(int i =0 ; i < n * 3; i++)
        cin >> ar[i];
    sort(ar, ar + n * 3);
    long long sum = 0;
    int k = n;
    int t = n * 3;
    while(k--)
    {
        t = t - 2;
        sum += ar[t];
    }
    cout << sum;
    return 0;
}