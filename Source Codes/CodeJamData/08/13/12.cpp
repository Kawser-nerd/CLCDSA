#include <iostream>
#include <cmath>
using namespace std;
void print(int a[2][2]) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) printf("%4d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}
void mult(int a[2][2], int b[2][2]) {
//    print(a);
//    print(b);
    int a1 = (a[0][0]*b[0][0])%1000+(a[0][1]*b[1][0])%1000;
    int a2 = (a[0][0]*b[0][1])%1000+(a[0][1]*b[1][1])%1000;
    int b1 = (a[1][0]*b[0][0])%1000+(a[1][1]*b[1][0])%1000;
    int b2 = (a[1][0]*b[0][1])%1000+(a[1][1]*b[1][1])%1000;
    a[0][0]=a1%1000;a[0][1]=a2%1000;a[1][0]=b1%1000;a[1][1]=b2%1000;
//    print(a);
//    system("PAUSE");
}
int main() {
    int T;scanf("%d",&T);for (int t=1; t<=T; t++) {
        int N;scanf("%d",&N);N--;
        // 6 -4 1 0 power of N
        int thepow[2][2]={{6,996},{1,0}};
        int cur[2][2]={{1,0},{0,1}};
        while (N) {
            if (N%2==1) mult(cur,thepow);
            mult(thepow,thepow);
            N/=2;
        }
        int ans = (6*cur[0][0]+2*cur[0][1]+999)%1000;
        printf("Case #%d: %03d\n",t,ans);
    }
}
