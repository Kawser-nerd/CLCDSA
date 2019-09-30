#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t;
long long money;
long long fee;
int n;
/*
long long dp[2000001];
*/

struct fun
{
    long long time, price;
} data[200];

bool operator < (const fun& a, const fun& b)
{
    return a.time < b.time || a.time == b.time && a.price > b.price;
}


long long getdays (long long i)
{
    long long tmp = money - i * fee;

    long long days = 0;
    for (int j = 0; j < n; j ++)
    {
        long long deltat = (data[j].time - (j > 0? data[j-1].time : 0));

//            cout << "j = " << j << ", deltat = " << deltat << endl;

        if (tmp / data[j].price / i / deltat >= 1)
        {
            days += deltat * i;
            tmp -= (data[j].price * i * deltat);
        }
        else
        {
            days += tmp / data[j].price;
            break;
        }
    }
    
    return days;
}

long long work ()
{
    sort (data, data + n);
    {
        int m = 0;
        for (int i = 0; i < n; i ++)
        {
            while (m > 0 && data[i].price <= data[m - 1].price)
                m --;
            data[m ++ ] =data[i];
        }
        n = m;
    }

    long long ll = 1, rr = money / fee;

    while (ll < rr)
    {
        long long mm1 = (ll * 2 + rr) / 3;
        long long mm2 = (ll + rr * 2 + 2) / 3;

        long long d1 = getdays (mm1);
        long long d2 = getdays (mm2);
        if (d1 > d2)
            rr = mm2 - 1;
        else
            ll = mm1 + 1;
    }

    return getdays(ll);
}

int main ()
{
    cin >> t;
    for (int ct = 1; ct <= t; ct ++)
    {
        cin >> money >> fee >> n;
        for (int i = 0; i < n; i ++)
        {
            cin >> data[i].price >> data[i].time;
            data[i].time ++;
        }

        cout << "Case #" << ct << ": " << work() << endl;
    }

    return 0;
}
