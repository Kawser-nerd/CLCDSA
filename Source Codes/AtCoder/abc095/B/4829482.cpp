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
    int n,x,m[110],ans = 0,count = 0;
    cin >> n >> x;
    for(int i = 0;i < n;i++)
    {
        cin >> m[i];
        ans += m[i];
        count++;
    }
    sort(m,m + n);

    for(;;)
    {
        if(ans + m[0]  <= x){ans += m[0]; count++;}
        else{break;}
    }
    cout << count << endl;
    return 0;
}