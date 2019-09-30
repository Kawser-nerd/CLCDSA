#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int N;
int S[30000];
int E[30000];
int imos[12 * 6 + 2];

int rounds(int s)
{
    int h = s / 100;
    int m = s % 100;

    return h * 100 + ((int)(m / 5) * 5);
}
int rounde(int e)
{
    int h = e / 100;
    int m = e % 100;

    int t;
    if (m % 5 == 0)
    {
        t = 0;
    }
    else
    {
        t = 1;
    }
    m = ((int)(m / 5) + t) * 5;
    h += m / 60;
    m %= 60;
    return h * 100 + m;
}

int to_index(int T)
{
    int h = T / 100;
    int m = T % 100;
    return h * 12 + m / 5;
}
int index_to(int i)
{
    int h = i / 12;
    int m = i % 12;
    return h * 100 + m * 5;
}

int main()
{
    cin >> N;
    int I = to_index(2400);
    for (int i = 0; i < N; i++)
    {
        scanf("%d-%d", &S[i], &E[i]);
        S[i] = rounds(S[i]);
        E[i] = rounde(E[i]);
        //printf("%d == %d\n", S, index_to(to_index(S)));
        imos[to_index(S[i])]++;
        imos[to_index(E[i])]--;
    }
    int v = 0;
    for (int i = 0; i <= I + 1;i++)
    {
        v += imos[i];
        imos[i] = v;
        //printf("%04d-%04d %d\n",index_to(i), index_to(i + 1), imos[i]);
    }
    int s, e;
    for (int i = 0; i <= I; i++)
    {
        while(imos[i] <= 0 && i < I)
        {
            i++;
        }
        if (i >= I)
        {
            break;
        }
        s = index_to(i);

        while (imos[i] >= 1 && i <= I)
        {
            i++;
        }
        e = index_to(i);
        printf("%04d-%04d\n", s, e);
    }
    return 0;
}