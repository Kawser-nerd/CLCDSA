#include <iostream>

using namespace std;
int f[200005];
int n, a[200005], pos[200005];


int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    int len = 1;
    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (pos[i + 1] > pos[i])
        {
            len++;
        }
        else
        {
            ans = max(ans, len);
            len = 1;
        }
    }
    ans = max(ans, len);
    cout << n-ans << endl;

    return 0;
}