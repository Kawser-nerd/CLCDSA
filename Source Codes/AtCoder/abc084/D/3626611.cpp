#include <iostream>
#include <cmath>

using namespace std;

#define MAX_N 1000001

bool p[MAX_N] = {false};
int like[MAX_N] = {0};
int acc[MAX_N + 1] = {0};

void sieve()
{
    int lim = sqrt(MAX_N);
    for (int i = 2; i <= MAX_N;i++)
    {
        p[i] = true;
    }
    
    for (int i = 2; i <= lim; i++)
    {
        if (p[i] == false)
        {
            continue;
        }
        int n = i * 2;
        for (int j = 2; n < MAX_N; j++)
        {
            n = i * j;
            p[n] = false;
        }
    }
}

int main()
{
    int Q;
    cin >> Q;

    sieve();

    for (int i = 1; i <= MAX_N;i+=2)
    {
        if(p[i] && p[(i + 1)/2])
        {
            like[i] = 1;
        }
        acc[i] = acc[i - 1] + like[i];
        acc[i + 1] = acc[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        if(l % 2 == 0)
        {
            cout << acc[r] - acc[l - 2] << endl;
        }
        else
        {
            cout << acc[r] - acc[l - 1] << endl;
        }
    }

    return 0;
}