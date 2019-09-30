#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int N,A,B;
    scanf("%d %d %d",&N,&A,&B);
    if(N == 1){
        if(A == B)
            printf("1\n");
        else
            printf("0\n");
    }
    else{
        if(A > B)
            printf("0\n");
        else{
//            int max = A + B * (N - 1);
//            int min = A * (N - 1) + B;
//            printf("%lld\n",(long long)(max - min) +1);
            printf("%lld\n",(long long )(B-A)*(N-2)+1); 
        }

    }

    return 0;
}