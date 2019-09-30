#include<iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ranka, rankb, rankc;

    if (a>b && a>c && b>c) ranka = 1, rankb = 2, rankc = 3;
    if (a>b && a>c && c>b) ranka = 1, rankb = 3, rankc = 2;
    if (b>a && b>c && a>c) ranka = 2, rankb = 1, rankc = 3;
    if (b>a && b>c && c>a) ranka = 3, rankb = 1, rankc = 2;
    if (c>a && c>b && a>b) ranka = 2, rankb = 3, rankc = 1;
    if (c>a && c>b && b>a) ranka = 3, rankb = 2, rankc = 1;
    cout << ranka << endl << rankb << endl << rankc << endl;
}