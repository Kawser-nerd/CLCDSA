#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int i = 0;
    bool f = true;

    string s1 = "dream";
    string s2 = "dreamer";
    string s3 = "erase";
    string s4 = "eraser";
    int l1 = 5;
    int l2 = 7;
    int l3 = 5;
    int l4 = 6;

    for (; i < s.length();)
    {
        if (s.substr(i, l1+l4) == s1+s4)
        {
            i += l1 + l4;
        }
        else if (s.substr(i, l1 + l3) == s1 + s3)
        {
            i += l1 + l3;
        }
        else if(s.substr(i, l2) == s2)
        {
            i += l2;
        }
        else if (s.substr(i, l4) == s4)
        {
            i += l4;
        }
        else if (s.substr(i, l1) == s1 || s.substr(i, l3) == s3)
        {
            i += l1;
        }
        else
        {
            f = false;
            break;
        }
    }

    cout << (f ? "YES" : "NO") << endl;

    return 0;
}