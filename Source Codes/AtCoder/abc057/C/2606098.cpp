#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    long N;
    cin>>N;
    long n = sqrt(N);
    int MIN = 1<<30;
    for (long a=1; a<=n; ++a) {
        long mod = N % a;
        if (mod == 0) {
            long b = N / a;
            int lena = to_string(a).size();
            int lenb = to_string(b).size();
            MIN = min(max(lena,lenb), MIN);
        }
    }
    cout<<MIN<<endl;
    return 0;
}