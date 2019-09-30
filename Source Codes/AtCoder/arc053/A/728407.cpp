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
    int H;
    int W;
    cin >> H;
    cin >> W;
    cout << ( W - 1 ) * H + ( H - 1 ) * W << endl;
}