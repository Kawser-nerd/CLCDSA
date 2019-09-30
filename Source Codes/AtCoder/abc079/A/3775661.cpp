#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int a[] = {0, 0, 0, 0};
    for(auto& e : a)
    {
        e = N % 10;
        N /= 10;
    }
    if(a[1] == a[2])
    {
        if(a[0] == a[1] || a[2] == a[3])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}