#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    
    int Xs[N], Hs[N];
    double Vs[N];
    
    for (int i=0; i<N; i++) {
        int X, R, H;
        cin >> X >> R >> H;
        
        Xs[i] = X;
        Hs[i] = H;
        Vs[i] = 3.14159265 * R * R * H / 3.0;
    }
    
    for (int j=0; j<Q; j++) {
        int A, B;
        cin >> A >> B;
        
        double Vr = 0;
        
        for (int i=0; i<N; i++) {
            if (Xs[i] + Hs[i] <= A) {
                
            } else if (B <= Xs[i]) {
            
            } else if ((A <= Xs[i]) && ((Xs[i] + Hs[i]) <= B)) {
                // ??????
                Vr += Vs[i];
            } else if ((Xs[i] < A) && (B < (Xs[i] + Hs[i]))) {
                // ???
                double Hb = (Xs[i] + Hs[i]) - B;
                double w = (Hb / Hs[i]);
                double Vb = w * w * w * Vs[i];
                
                double Ha = (Xs[i] + Hs[i]) - A;
                double q = (Ha / Hs[i]);
                double Va = q * q * q * Vs[i];
                
                Vr += Va - Vb;
            } else if ((A <= Xs[i]) && (B <= (Xs[i] + Hs[i]))) {
                // ????????
                double Hb = (Xs[i] + Hs[i]) - B;
                double w = (Hb / Hs[i]);
                double Vb = w * w * w * Vs[i];
                
                Vr += Vs[i] - Vb;
            } else if ((Xs[i] <= A) && ((Xs[i] + Hs[i]) <= B)) {
                // ????????
                double Hb = (Xs[i] + Hs[i]) - A;
                double w = (Hb / Hs[i]);
                double Va = w * w * w * Vs[i];
                Vr += Va;
            }
        }
        
        cout << fixed << setprecision(10) << Vr << endl;
    }
    
    cout << flush;
    
    return 0;
}