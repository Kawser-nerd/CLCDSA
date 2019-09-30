#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(d >= ((max(a, c) - min(a, c))))
        cout << "Yes" << endl;
    else if((d >= ((max(a, b) - min(a, b)))) &&
            (d >= ((max(b, c) - min(b, c)))))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}