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
    int n,k,x,ans = 0;
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> x;
        if(abs(k - x) < x){ans += abs(k - x) * 2;}
        else{ans += x * 2;}
    }
    cout << ans << endl;
    return 0;
}