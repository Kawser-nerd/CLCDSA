#include <iostream>
using namespace std;
int main(void)
{
    int a, b, c, cnt = 0;
    cin >> a >> b >> c;
    while ((c != 0) || ((a != 0) && (b != 0)))
    {
        if ((c == 0) && (b != 0) && (a != 0))
        {
            break;
        }
        c--;
        cnt++;
        if (b != 0)
        {
            b--;
            cnt++;
        }
        else if (a != 0)
        {
            a--;
        }
        else
        {
            break;
        }
    }
    if (b != 0)
    {
        cnt += b;
    }
    cout << cnt << endl;
    return 0;
}