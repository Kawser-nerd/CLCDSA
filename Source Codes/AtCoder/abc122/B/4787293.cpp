#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string inputString;
    string atgc = "ATGC";
    cin >> inputString;
    int length = inputString.length();
    int max_length = 0;
    int p_length = 0;
    for (int i = 0; i < length; i++)
    {
        p_length = 0;
        for (int j = 0; j < length - i; j++)
        {
            if (atgc.find(inputString[i + j]) != string::npos)
            {
                p_length += 1;
            }
            else
            {
                break;
            }
        }
        if (p_length >= max_length)
        {
            max_length = p_length;
        }
    }
    cout << max_length << endl;
    return 0;
}