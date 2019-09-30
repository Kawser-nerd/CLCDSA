#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, x;
vector<int> a;

int main()
{
    scanf(" %d %d", &N, &x);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        scanf(" %d", &tmp);
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());

    int result = 0;

    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        x -= a[i];
        if (x < 0)
        {
            break;
        }

        if (i == size - 1)
        {
            if (x == 0)
            {
                result++;
            }
            break;
        }

        result++;
    }

    printf("%d\n", result);
}