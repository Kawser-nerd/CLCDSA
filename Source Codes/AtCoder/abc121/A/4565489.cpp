#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

#define ll long long

int main(){

    int H, W;
    int h, w;

    cin >> H >> W;
    cin >> h >> w;

    cout << H * W - (H * w + W * h) + h * w << endl;

    return 0;


}