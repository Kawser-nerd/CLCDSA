#include<iostream>
#include<stdlib.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, num;
    cin >> a >> b;

    char c[7];
    sprintf(c, "%d%d", a, b);
    num = atoi(c);

    cout << num * 2 << "\n";

    return 0;
}