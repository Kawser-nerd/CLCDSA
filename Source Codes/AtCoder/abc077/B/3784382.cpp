#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int i;
    for(i = 1; i <= 100000; ++i)
    {
        if(i * i > N)
            break;
    }
    i--;
    cout << i * i << endl;
    return 0;
}