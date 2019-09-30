#include <iostream>
using namespace std;
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        int N,S,P; scanf("%d %d %d",&N,&S,&P);
        int a=0,b=0,c=0,d=0;
        for (int i=0; i<N; i++) {
            int points; scanf("%d",&points);
            // ok, don't want to bother thinking about special cases and missing one, so brute force
            bool normal=false, surprise=false;
            for (int j=0; j<=10; j++)
            for (int k=j; k<=10; k++)
            for (int l=k; l<=10; l++) {
                if (j+k+l!=points || l-j>2 || l<P) continue;
                if (l-j<2) normal=true;
                if (l-j==2) surprise=true;
            }
            //printf("%d: %d %d\n",points,normal,surprise);
            if (!normal && !surprise) a++;
            if (normal && !surprise) b++;
            if (!normal && surprise) c++;
            if (normal && surprise) d++;
        }
        assert(a+b+c+d==N);
        //printf("%d,%d,%d,%d\n",a,b,c,d);
        int y = min(S,c);
        S-=y;
        int w = min(S,a);
        S-=w;
        int z = min(S,d);
        S-=z;
        int x = min(S,b);
        S-=x;         
        assert(S==0);       
        int ans = b+d-x+y;
        printf("Case #%d: %d\n",t,ans);
    }
}
/*
a: neither - w
b: normal - x
c: surprise - y
d: both - z

then answer is (b-x) + y + d
= b + d + y - x
y is as large as poss
x is as small as poss

*/
