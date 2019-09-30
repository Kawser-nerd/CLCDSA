#include <iostream>
using namespace std;

int main(void){
    int a, b, k;
    cin >> a >> b >> k;

    int count = 0;
    for(int i = std::min(a,b); i > 0 ; i--){
        if(a % i == 0 && b % i == 0){;
            if(++count == k){
                cout << i;
                return 0;
            }
        }
    }
}