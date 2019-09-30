#include <cstdio>
int a[100005];
int main(int argc, char const *argv[])
{
    long long n;
    long long suma =0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        suma += a[i];
    }
    long long sumy = suma/(((1+n)*n)/2);
    if(sumy * (((1+n)*n)/2) != suma ){
        printf("NO\n");
        return 0;
    }


    for (int i=0;i<n-1;i++){
        long long k = a[i+1]-a[i];
        long long y = (sumy - k)/n;
        if(y<0 || y*n != sumy -k){
            printf("NO\n");
            return 0;
        }

    }
    printf("YES\n");


    return 0;
}