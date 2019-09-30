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
    bool judge = false;
    int n[26];
    char ans;
    string s;
    cin >> s;
    for(int i = 0;i < 26;i++){n[i] = 0;}
    for(int i = 0;i < s.size();i++)
    {
        n[s[i] - 97] = 1;
    }
    for(int i = 0;i < 26;i++)
    {
        if(n[i] == 0){ans = i + 97; judge = true; break;}
    }
    if(judge){cout << ans << endl;}
    else{cout << "None" << endl;}
    return 0;
}