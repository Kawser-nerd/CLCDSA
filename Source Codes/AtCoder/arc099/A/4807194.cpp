#include<iostream>
using namespace std;
#define ll long long

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n ; i++)
        cin >> a[i];
    n = n - x;
    ll c = 1;
    c = c + n / (x-1);
    if(n % (x-1) != 0)
        c++;
    cout << c <<endl;

    return 0;
}