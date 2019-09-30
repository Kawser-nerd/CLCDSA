#include <iostream>

#define P 1000000007
#define N_MAX 200001

using namespace std;

long inv[N_MAX];
long fac[N_MAX];
long finv[N_MAX];

void init(){
    inv[0] = 1;
    fac[0] = 1;
    finv[0] = 1;
    inv[1] = 1;
    fac[1] = 1;
    finv[1] = 1;
    for(int i = 2; i < N_MAX; i++){
        fac[i] = (fac[i-1]*i)%P;
        inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
        finv[i] = (finv[i-1]*inv[i])%P;
    }
}

int main(){
    int H, W, A, B;
    long ans = 0;
    cin >> H >> W >> A >> B;
    H--;W--;A--;B--;
    init();
    long comb0 = (((fac[H-A+B]*finv[B])%P)*finv[H-A])%P;
    //cout << comb0 << endl;
    if(A != 0){
        for(int i = B+1; i <= W; i++){
            long comb1, comb2;

            comb1 = (((fac[H-A+i]*finv[i])%P)*finv[H-A])%P;
            comb2 = (((fac[W-i+A-1]*finv[A-1])%P)*finv[W-i])%P;
            ans = (((ans+(comb1-comb0)*comb2)%P)+P)%P;
            //cout << ans << endl;
        }
    }else{
        long comb1 = (((fac[H+W]*finv[H])%P)*finv[W])%P;
        ans = (((comb1-comb0)%P)+P)%P;
    }
    cout << ans << endl;
}