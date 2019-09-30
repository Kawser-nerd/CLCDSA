#include <stdio.h>
int deg(long long int n){
    long long int k=1;
    for(int i=0;;i++){
        if(n>=k)k*=2;
        else {
            return i;
            break;
        }
    }
}
long long int pow(int n){
    if(n==0)return 1;
    else return 2*pow(n-1);
}
int main(void){
    long long int A,B;
    scanf("%lld %lld",&A,&B);
    long long int ans=0;
    int Bdeg=deg(B);
    int Adeg=deg(A);
    int subBdeg;
    while(1){
        if(Adeg==Bdeg){
            A-=pow(Adeg-1);
            B-=pow(Bdeg-1);
        }
        else{
            ans+=pow(Bdeg-1);
            ans-=A;
            subBdeg=deg(B-pow(Bdeg-1));
            B=pow(Bdeg-1)+pow(subBdeg)-1;
            if(B-pow(Bdeg-1)<A){
                ans+=(B-A)+1;
            }
            else ans+=pow(Bdeg-1);
            break;
        }
        if(A==B){
            ans++;
            break;
        }
        Adeg=deg(A);
        Bdeg=deg(B);
    }
    printf("%lld",ans);
    return 0;
} ./Main.c:12:15: warning: conflicting types for built-in function ‘pow’
 long long int pow(int n){
               ^
./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&A,&B);
     ^