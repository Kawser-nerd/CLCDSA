#include <iostream>
using namespace std;

int main(void)
{
    int A,B,C;
    int t;
    cin >> A >> B >> C;
    cin >> t;

    int count = 0;
    for(int i = 0; i <= C; i++)
    {
        for(int j = 0; j <= B; j++)
        {
            for(int k = 0; k <= A; k++)
            {
                if (i * 50 + j * 100 + k * 500 == t)
                {
                    ++count;
                }
            }
        }
    }
    
    cout << count << endl;

    return 0;
}