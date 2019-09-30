#include <iostream>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <bitset>
#include <deque>
#include <limits>
#include <numeric>
#include <functional>
#define gc getchar()
#define mem(a) memset(a,0,sizeof(a))
#define mod 1000000007
#define sort(a,n,int) sort(a,a+n,less<int>())
using namespace std;
typedef long long ll;
typedef char ch;
typedef double db;
using namespace std;
ll a[1000000];
ll cnt = 0;
inline void mmp()
{
    for ( ll i = 1; i * i <= 2000000000; i++ )
    {
        a[cnt++] = i * i;
    }
}
ll x;
int main()
{
    mmp();
    while ( ~scanf ( "%lld", &x ) )
    {
        for ( ll i = 0; i < cnt; i++ )
        {
            if ( x < a[i] )
            {
                printf ( "%lld\n", a[i - 1] );
                break;
            }
        }
    }
    return 0;
}