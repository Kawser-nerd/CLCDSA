#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if(i % 2 == 0){cout << s[i];}
    }
    return 0;
}