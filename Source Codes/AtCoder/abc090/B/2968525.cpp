#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(){

    int A, B;
    int i;
    int ans = 0;
    string str1, str2;

    cin >> A >> B;

    for(i =A; i <= B; ++i){
        str1 = to_string( i );
        str2 = to_string( i );
        reverse(str2.begin(), str2.end());
        if(str1 == str2){
            ++ans;
        }
    }

    cout << ans << endl;

}