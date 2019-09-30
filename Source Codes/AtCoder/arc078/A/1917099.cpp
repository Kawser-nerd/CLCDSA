/*main*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N = 200050;
int a[N];
int n;
typedef long long LL;

void init()
{

}

void solve()
{
    cin >> n;
    LL sumX = 0,sumY = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sumY += a[i];
    }
    LL Min = abs(a[0] - (sumY-a[0]));
    for(int i=0; i<n-1; i++)
    {
        sumX += a[i];
        sumY -= a[i];
        if(Min > abs(sumX-sumY))
            Min = abs(sumX-sumY);
        if(Min == 0)
            break;
    }
    cout << Min << endl;
}

int main()
{
    /*init();*/
    solve();
    return 0;
}