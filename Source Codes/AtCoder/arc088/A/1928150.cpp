#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll x, y;
    cin >> x >> y;
    int cnt = 0;
    while (x <= y) {
        x *= 2;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}