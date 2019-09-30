#include <iostream>
using namespace std;
int main()
{
    int N;
    int a[101];
    int count = 0;

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for (size_t i = 0; i < N - 1; i++)
    {
        int buf1, buf2;
        buf1 = a[i];
        buf2 = a[i + 1];

        if (buf1 == buf2)
        {
            a[i + 1] = 1000000000;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}