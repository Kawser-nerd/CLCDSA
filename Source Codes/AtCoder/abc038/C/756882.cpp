#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int n = 0;
    int d = 0;
    long long s = 0;
    
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        
        if (n < a) {
        } else {
            n = 0;
            d = 0;
        }
        
        n = a;
        d++;
        s += d;
    }
    
    cout << s << endl;
    
    return 0;
}