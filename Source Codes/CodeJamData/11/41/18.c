// http://code.google.com/codejam
// Task: 

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Walkway {
public:
    int B, E, w;
//    bool operator < (Walkway ww) { return w < ww.w; }
};

bool less(Walkway w1, Walkway w2)
{
  return (w1.w < w2.w);
}


int main ()
{
    int test_num;
    scanf("%d", &test_num);
    for(int test_idx = 1; test_idx <= test_num; test_idx++) {
        int X, S, R, t, N;
        scanf("%d %d %d %d %d", &X, &S, &R, &t, &N);
        
        Walkway W[N];
        int wD = 0;
        for(int n = 0; n < N; n++) {
            scanf("%d %d %d", &W[n].B, &W[n].E, &W[n].w);
            wD += (W[n].E - W[n].B);
        }

        double res = 0;
        double wT = t;
        if (wD < X) {
            double wTR = (double)(X - wD) / (double)R;
            if (wTR > wT) {
                wTR = wT;
            }
            double wTS = (double)(X - wD - wTR*R) / (double)S;
            res += (wTR + wTS);
            wT -= wTR;
        }

        sort(W, W+N, less);

        for(int n = 0; n < N; n++) {
            double wTR = (double)(W[n].E - W[n].B) / (double)(W[n].w + R);
            if (wTR > wT) {
                wTR = wT;
            }
            double wTS = (double)(W[n].E - W[n].B - wTR*(W[n].w + R)) / (double)(W[n].w + S);
            res += (wTR + wTS);
            wT -= wTR;
        }

        printf("Case #%d: %f\n", test_idx, res);
    }
    return 0;
}
