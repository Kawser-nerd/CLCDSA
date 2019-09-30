#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int x[100] = {};
int r[100] = {};
int h[100] = {};

int a[100000] = {};
int b[100000] = {};

int main(int argc, const char * argv[]) {
    int i,j;
    int N,Q;

    scanf("%d %d", &N, &Q);
    for(i=0; i<N; ++i){
        scanf("%d %d %d", &x[i], &r[i], &h[i]);
    }
    for(i=0; i<Q; ++i){
        scanf("%d %d", &a[i], &b[i]);
    }
    
    for(i=0; i<Q; ++i){
        double V=0.0;
        int A=a[i], B=b[i];
        for(j=0; j<N; ++j){
            double vc = 0.0;
            unsigned long long X=x[j], R=r[j], H=h[j];
            
            if(X>=B) continue;
            if(X+H<=A) continue;

            if(X<A) {
                if(X+H>B){
                    vc = R*R*H * ( (X+H-A) * (X+H-A) * (X+H-A) - (X+H-B) * (X+H-B) * (X+H-B) ) / (double)( H*H*H );
                } else {
                    vc = R*R*H * (X+H-A) * (X+H-A) * (X+H-A) / (double)( H*H*H );
                }
            } else {
                if(X+H>B){
//                    int temp1 = R*R*H;
//                    int temp2 = H*H*H - (X+H-B) * (X+H-B) * (X+H-B);
//                    double temp3 = (double)H*H*H;
//                    int temp4 = temp1 * temp2;
//                    vc = temp4 / temp3;
                    vc = R*R*H * ( H*H*H - (X+H-B) * (X+H-B) * (X+H-B) ) / (double)( H*H*H );
                } else {
                    vc = R*R*H;
                }
            }
            V += vc;
        }
        V = V * acos(-1) / 3.0;
        printf("%f\n", V);
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &Q);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &x[i], &r[i], &h[i]);
         ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a[i], &b[i]);
         ^