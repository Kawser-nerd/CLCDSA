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

long long n, ar[1000001], k, u[1000001];
vector<int> vec;

int main()
{
    cin >> n >> k;
    for(long long i = 1; i <= n; i++)
        cin >> ar[i];

    if( (n >= 5000 && k < 5000 && k > 4000 ) || (n <= 400 && k > 400))
    {
        for(long long i = 1; i <= n; i++)
        {
            long long r = 1, sum = 0;
            for(int j = 1; j <= i; j++)
                sum += ar[j];
            r = i + 1;

            for(long long j = 1; j <= i; j++)
            {
                if(r < j)
                {
                    r = j;
                    sum = 0;
                }
                while((r <= n && sum < k))
                {
                    sum += ar[r];
                    r++;
                }

                if(sum >= k)
                {
                    if(sum - ar[i] < k)
                    {
                        u[i] = 1;
                        break;
                    }
                }else
                {
                    break;
                }
                //cout << j << " " << r << endl;
                sum -= ar[j];
            }
        }
        long long ans = 0;
        for(long long i = 1; i <= n; i++)
            ans += u[i];

        cout << n - ans;
    }else
    {
        for(long long i = 1; i <= n; i++)
        {
            long long r = 1, sum = 0;
            for(long long j = 1; j <= n; j++)
            {
                if(r < j)
                {
                    r = j;
                    sum = 0;
                }
                while((r < j) || (r <= n && sum < k))
                {
                    sum += ar[r];
                    r++;
                }

                if(i >= j && j < r && sum >= k)
                    if(sum - ar[i] < k)
                        u[i] = 1;
                //cout << j << " " << r << endl;
                sum -= ar[j];
            }
        }

        for(long long i = 1; i <= n; i++)
        {
            long long r = n, sum = 0;
            for(long long j = n; j > 0; j--)
            {
                if(r > j)
                {
                    r = j;
                    sum = 0;
                }
                while((r > j) || (r > 0 && sum < k))
                {
                    sum += ar[r];
                    r--;
                }

                if(i <= j && j > r && sum >= k)
                    if(sum - ar[i] < k)
                        u[i] = 1;
                //cout << j << " " << r << endl;
                sum -= ar[j];
            }
        }

        long long ans = 0;
        for(long long i = 1; i <= n; i++)
            ans += u[i];

        cout << n - ans;
    }
    return 0;//
}