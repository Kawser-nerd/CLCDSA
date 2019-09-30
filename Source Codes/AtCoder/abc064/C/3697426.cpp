#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    const int c = 400;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> rate(9, 0);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int i=0; i<n; ++i){
        for(int j=1; j<=9; ++j){
            if(j == 9){
                rate[8]++;
                break;
            }
            else if(a[i] < c * j){
                rate[j-1]++;
                break;
            }
        }
    }
    int min = 0;
    int max = 0;
    for (int i=0; i<8; ++i){
        if(i == 7){
            min += (rate[7] > 0 || rate[8] > 0) ? 1 : 0;
        }
        else {
            min += (rate[i] > 0) ? 1 : 0;
            max += (rate[i] > 0) ? 1 : 0;
        }
    }
    max += rate[8] + ((rate[7] > 0) ? 1 : 0);
    cout << min << " " << max << endl;
}