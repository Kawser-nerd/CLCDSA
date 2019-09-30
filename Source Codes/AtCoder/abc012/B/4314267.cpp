#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int h = N / 3600; N %= 3600;
    int m = N / 60; N %= 60;
    int s = N;
    cout << setw(2) << setfill('0') << h << ':';
    cout << setw(2) << setfill('0') << m << ':';
    cout << setw(2) << setfill('0') << s << endl;
    return 0;
}