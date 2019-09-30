#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long A,B;
    scanf("%lld %lld",&A,&B);
    long long a=0,b=0;
    long long tmpA=--A;
    long long tmpB=B;
    long long digitA=1;
    long long digitB=1;
    while(tmpA>9){
        tmpA/=10;
        digitA*=10;
    }
    tmpA=A;
    while(digitA>0){
        if((A/digitA)%10==4){
            a+=3*digitA;
            digitA/=10;
            while(digitA>0){
                a+=7*digitA;
                digitA/=10;
            }
        }else if((A/digitA)%10==9){
            while(digitA>0){
                a+=7*digitA;
                digitA/=10;
            }
        }else{
            if((A/digitA)%10<4){
                a+=((A/digitA)%10)*digitA;
            }else{
                a+=(((A/digitA)%10)-1)*digitA;
            }
            digitA/=10;
        }
    }

    while(tmpB>9){
        tmpB/=10;
        digitB*=10;
    }
    tmpB=B;
    while(digitB>0){
        if((B/digitB)%10==4){
            b+=3*digitB;
            digitB/=10;
            while(digitB>0){
                b+=7*digitB;
                digitB/=10;
            }
        }else if((B/digitB)%10==9){
            while(digitB>0){
                b+=7*digitB;
                digitB/=10;
            }
        }else{
            if((B/digitB)%10<4){
                b+=((B/digitB)%10)*digitB;
            }else{
                b+=(((B/digitB)%10)-1)*digitB;
            }
            digitB/=10;
        }
    }
    long long tmpa=a,tmpb=b;
    a=0,b=0;
    long long tmp=1;
    while(tmpa>0){
        a+=(tmpa%10)*tmp;
        tmpa/=10;
        tmp*=8;
    }
    tmp=1;
    while(tmpb>0){
        b+=(tmpb%10)*tmp;
        tmpb/=10;
        tmp*=8;
    }
    printf("%lld\n",B-A-(b-a));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&A,&B);
     ^