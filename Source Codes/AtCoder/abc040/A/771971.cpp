#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<math.h>
using namespace std;

int main()
{
    // get a integer
    int N, X;
    cin >> N >> X;

    int a = X - 1;
    int b = N - X;

    cout << ( a < b ? a : b ) << endl;
}