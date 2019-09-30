#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

long long pascal[100][100];

void make_table()
{
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    for (int i = 2; i < 60;i++)
    {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
}

int main()
{
    long long en = 0, on = 0;
    long long n, p;
    make_table();
    cin >> n >> p;
    long long ensum = 1;
    long long onsum1 = 0;
    long long onsum2 = 0;
    for (long long i = 0; i < n;i++)
    {
        long long a;
        cin >> a;
        if(a % 2 == 0)
        {
            en++;
        }
        else
        {
            on++;
        }
    }
    for (int i = 1; i <= en; i++)
    {
        ensum += pascal[en][i];
    }

    for (int i = 1; i <= on; i+=2)
    {
        onsum1 += pascal[on][i];
    }
    for (int i = 0; i <= on; i += 2)
    {
        onsum2 += pascal[on][i];
    }
    long long ans = ensum * (p == 1 ? onsum1 : onsum2);

    cout << ans << endl;

    return 0;
}