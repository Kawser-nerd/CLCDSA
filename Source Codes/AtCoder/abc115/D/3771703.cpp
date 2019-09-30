#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> a(1, 1), p(1, 1);

long long f(int N, long long X){
//    printf("N=%d, X=%d\n", N, X);
//    printf("a=%d, p=%d\n", a[N-1], p[N-1]);
    if(N==0){
//        printf("N=0\n");
        return 1;
    }
    else if(X==1){
//        printf("X=1\n");
        return 0;
    }
    else if(1<X && X<a[N-1]+2){
//        printf("X<a+2\n", X,);
        return f(N-1, X-1);
    }
    else if(X==a[N-1]+2){
//        printf("X=a+2\n");
        return p[N-1]+1;
    }
    else if(a[N-1]+2<X && X<2*a[N-1]+3){
//        printf("X<2a+3\n");
        return p[N-1]+1+f(N-1, X-a[N-1]-2);
    }
    else if(X==2*a[N-1]+3){
//        printf("X=2a+3\n");
        return 2*p[N-1]+1;
    }
}

int main(void){
    int N, i;
  	long long X;
    scanf("%d %lld", &N, &X);
    for(i=0; i<N-1; i++){
        a.push_back(2*a[i]+3);
//        printf("a[%d]=%d, ", i+1, a[i+1]);
        p.push_back(2*p[i]+1);
//        printf("p[%d]=%d\n", i+1, p[i+1]);
    }
    printf("%lld", f(N, X));
    return 0;
} ./Main.cpp:34:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.