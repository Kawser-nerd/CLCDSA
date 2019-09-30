#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

// ????
bool is_prime(int n){
    if (n == 2){
        return true;
    }
    else if(n < 2 || n % 2 == 0){
        return false;
    }
    else {
        int i = 3;
        int upper_bound = (int)sqrt(n) + 1;
        while(i <= upper_bound){
            if(n % i == 0){
                return false;
            }
            i += 2;
        }
        return true;
    }
}
int main()
{
    int n, ans;
    ans = 0;
    cin >> n;
    cout << (is_prime(n) ? "YES" : "NO")  << endl;
    return 0;
}