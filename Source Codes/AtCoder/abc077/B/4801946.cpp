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
    int n,ans = 0;
    cin >> n;
    for(int i = 1;;i++)
    {
        if(n < i * i){ans = (i - 1) * (i - 1); break;}
    }
    cout << ans << endl;
    return 0;
}