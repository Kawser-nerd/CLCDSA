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
ch a[5][10];
int main()
{
    while(~scanf("%s",a[0]))
    {
        scanf("%s",a[1]);
        if(a[0][0] == a[1][2] && a[0][1] == a[1][1] && a[0][2] == a[1][0])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}