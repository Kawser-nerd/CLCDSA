#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, k, l;
    bool b;
    b = true;
    string price;
    cin >> n >> k;
    vector<int> d(k);
    for(int i=0; i<k; ++i){
        cin >> d[i];
    }
    for(int i=n; i<100000; ++i){
        price = to_string(i);
        l = price.length();
        b = true;
        for(int j=0; j<l; ++j){
            for(int u=0; u<k; ++u){
                if(price[j] - '0' == d[u]){
                    b = false;
                }
            }
        }
        if(b){
            cout << price << endl;
            break;
        }
    }
}