#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> v;
    for(int i = 0; i <= a; ++i){
        for(int j = 0; j <= b; ++j){
            for(int k = 0; k <= c; ++k){
                v.push_back(500*i + 100*j + 50*k);
            }
        }
    }

    int target;
    cin >> target;

    cout << count(v.begin(), v.end(), target) << endl;
}