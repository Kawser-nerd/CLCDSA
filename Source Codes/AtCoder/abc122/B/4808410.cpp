#include <iostream>
using namespace std;

bool is_acgt(char c)
{
    switch (c)
    {
    case 'A':
    case 'C':
    case 'G':
    case 'T':
        return true;
    default:
        return false;
    }
}

int main()
{
    string S;
    cin >> S;

    int max = 0;
    int strlen = sizeof(S) / sizeof(S[0]);
    int start = -1;
    for (int i = 0; i < strlen; i++)
    {
        char c = S[i];
        if (is_acgt(c))
        {
            if (start == -1)
            {
                start = i;
            }
        }
        else
        {
            if (start != -1)
            {
                if (i - start > max)
                {
                    max = i - start;
                }
                start = -1;
            }
        }
    }
    cout << max << endl;
}