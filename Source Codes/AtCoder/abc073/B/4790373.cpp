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
    int n,l,r,ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> l >> r;
        ans += r - l + 1;
    }
    cout << ans << endl;
    return 0;
}