#include<stdio.h>

long long int reverse(long long int a){
    long long int ans=0;
    for(;a > 0 ; a=a/10){
        ans = ans*10 + (a%10);
    }
    return ans;

}
int main() {

    int t;
    long long int arr[1000002];

    int i=0;

    arr[1] = 1;

    for(i=2;i<=1000001;i++) {
        
        if(i%10 != 0){
            arr[i]=arr[i-1]+1;
            long long int rev = reverse(i);
            if(rev < i) {
                 if(arr[i] > arr[rev]+1)
                     arr[i] = arr[rev]+1;
            }
        }else {
            arr[i]=arr[i-1]+1;
        }
    }

    scanf("%d",&t);
    long long int n;
    for(int tt=0;tt<t;tt++) {
         scanf("%lld",&n);
         printf("Case #%d: %lld\n",tt+1,arr[n]);
    }
    return 0;

}
