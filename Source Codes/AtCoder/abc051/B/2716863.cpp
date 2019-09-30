// A - Haiku

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int k,s;
    cin >> k >> s;
    int count = 0;

    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            int rest = s - (i+j);
            if(rest >= 0 && rest <= k){
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}