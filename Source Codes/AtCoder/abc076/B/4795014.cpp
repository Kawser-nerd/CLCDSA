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
    int n,k,ans = 1;
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        if(ans * 2 < ans + k){ans *= 2;}
        else{ans += k;}
    }
    cout << ans << endl;
    return 0;
}