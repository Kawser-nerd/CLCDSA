#include <iostream>

using namespace std;

long N, A, B;

bool can_kill_all(long *h, long n){
    long sum = 0;
    for(int i = 0; i < N; i++){
        if(n*B < h[i]){
            sum += (h[i]-n*B)/(A-B);
            if((h[i]-n*B)%(A-B) != 0) sum+= 1;
        }
    }
    if(sum > n) return false;
    else return true;
}

int main(){
    cin >> N >> A >> B;
    long h[100000];
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }
    long l = 0, r = 10e+9;
    long c = (l+r)/2;
    while(r-l > 1){
        if(can_kill_all(h, c)) r = c;
        else l = c;
        c = (l+r)/2;
    }
    cout << r << endl;
}