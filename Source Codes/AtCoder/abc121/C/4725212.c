#include <stdio.h>
#include <stdlib.h>
void usort(long *a,long n){
    long *store;
    long hf=n,unit=1,a1,a2;
    store=malloc((long)sizeof(long)*n*2);
    for (int i=0;i<2*n;i++){
      store[i]=a[i];
    }
    while (hf>1){
        if (hf==2){
            hf=(hf+1)/2;
            for (long i=0;i<hf;i++){
                a1=0;
                a2=0;
                while (a1+a2<2*unit && 2*i*unit+a1+a2<n){
                    if (a1==unit){
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                      store[2*i*unit+a1+a2+n]=a[(2*i+1)*unit+a2+n];
                        a2++;
                    }
                    else if (a2==unit || (2*i+1)*unit+a2==n){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                      store[2*i*unit+a1+a2+n]=a[2*i*unit+a1+n];
                        a1++;
                    }
                    else if (a[(2*i+1)*unit+a2]>a[2*i*unit+a1]){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                      store[2*i*unit+a1+a2+n]=a[2*i*unit+a1+n];
                        a1++;
                    }
                    else {
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                      store[2*i*unit+a1+a2+n]=a[(2*i+1)*unit+a2+n];
                        a2++;
                    }
                }
            }
            for (long i=0;i<2*n;i++) a[i]=store[i];
            break;
        }
        else if (hf%2){
            hf=(hf+1)/2;
            for (long i=0;i<hf-1;i++){
                a1=0;
                a2=0;
                while (a1+a2<2*unit && 2*i*unit+a1+a2<n){
                    if (a1==unit){
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                      store[2*i*unit+a1+a2+n]=a[(2*i+1)*unit+a2+n];
                        a2++;
                    }
                    else if (a2==unit || (2*i+1)*unit+a2==n){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                      store[2*i*unit+a1+a2+n]=a[2*i*unit+a1+n];
                        a1++;
                    }
                    else if (a[(2*i+1)*unit+a2]>a[2*i*unit+a1]){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                      store[2*i*unit+a1+a2+n]=a[2*i*unit+a1+n];
                        a1++;
                    }
                    else {
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                      store[2*i*unit+a1+a2+n]=a[(2*i+1)*unit+a2+n];
                        a2++;
                    }
                }
            }
        }
        else {
            hf=(hf+1)/2;
            for (long i=0;i<hf;i++){
                a1=0;
                a2=0;
                while (a1+a2<2*unit && 2*i*unit+a1+a2<n){
                    if (a1==unit){
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                      store[2*i*unit+a1+a2+n]=a[(2*i+1)*unit+a2+n];
                        a2++;
                    }
                    else if (a2==unit || (2*i+1)*unit+a2==n){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                      store[2*i*unit+a1+a2+n]=a[2*i*unit+a1+n];
                        a1++;
                    }
                    else if (a[(2*i+1)*unit+a2]>a[2*i*unit+a1]){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                      store[2*i*unit+a1+a2+n]=a[2*i*unit+a1+n];
                        a1++;
                    }
                    else {
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                      store[2*i*unit+a1+a2+n]=a[(2*i+1)*unit+a2+n];
                        a2++;
                    }
                }
            }
        }
        unit*=2;
        for (long i=0;i<2*n;i++) a[i]=store[i];
    }
    free(store);
    return;
}

int main(){
    long n,m,*d,cost=0;
    scanf("%ld%ld",&n,&m);
    d=malloc((long)sizeof(long)*n*2);
    for (long i=0;i<n;i++) scanf("%ld%ld",&d[i],&d[i+n]);
    usort(d,n);
    for (long i=0;i<n;i++){
      if (m>d[i+n]){
        cost+=d[i]*d[i+n];
        m-=d[i+n];
      }
      else {
        cost+=d[i]*m;
        break;
      }
    }
  printf("%ld\n",cost);
    free(d);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:109:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&n,&m);
     ^
./Main.c:111:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (long i=0;i<n;i++) scanf("%ld%ld",&d[i],&d[i+n]);
                            ^