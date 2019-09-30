#include <stdio.h>
#include <stdlib.h>
void usort(int*,int);

int main(){
  int n,k,r,*a;
  double rate=0;
  scanf("%d%d",&n,&k);
  a=(int*)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++) scanf("%d",&a[i]);
  usort(a,n);
  for (int i=n-k;i<n;i++) rate=(rate+a[i])/2;
  printf("%f\n",rate);
  return 0;
}

void usort(int *a,int n){
    int *store;
    int hf=n,unit=1,a1,a2;
    store=(int *)malloc((int)sizeof(int)*n);
    for (int i=0;i<n;i++) store[i]=a[i];
    while (hf>1){
        if (hf==2){
            hf=(hf+1)/2;
            for (int i=0;i<hf;i++){
                a1=0;
                a2=0;
                while (a1+a2<2*unit && 2*i*unit+a1+a2<n){
                    if (a1==unit){
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                        a2++;
                    }
                    else if (a2==unit || (2*i+1)*unit+a2==n){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                        a1++;
                    }
                    else if (a[(2*i+1)*unit+a2]>a[2*i*unit+a1]){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                        a1++;
                    }
                    else {
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                        a2++;
                    }
                }
            }
            for (int i=0;i<n;i++) a[i]=store[i];
            break;
        }
        else if (hf%2){
            hf=(hf+1)/2;
            for (int i=0;i<hf-1;i++){
                a1=0;
                a2=0;
                while (a1+a2<2*unit && 2*i*unit+a1+a2<n){
                    if (a1==unit){
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                        a2++;
                    }
                    else if (a2==unit || (2*i+1)*unit+a2==n){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                        a1++;
                    }
                    else if (a[(2*i+1)*unit+a2]>a[2*i*unit+a1]){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                        a1++;
                    }
                    else {
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                        a2++;
                    }
                }
            }
        }
        else {
            hf=(hf+1)/2;
            for (int i=0;i<hf;i++){
                a1=0;
                a2=0;
                while (a1+a2<2*unit && 2*i*unit+a1+a2<n){
                    if (a1==unit){
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                        a2++;
                    }
                    else if (a2==unit || (2*i+1)*unit+a2==n){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                        a1++;
                    }
                    else if (a[(2*i+1)*unit+a2]>a[2*i*unit+a1]){
                        store[2*i*unit+a1+a2]=a[2*i*unit+a1];
                        a1++;
                    }
                    else {
                        store[2*i*unit+a1+a2]=a[(2*i+1)*unit+a2];
                        a2++;
                    }
                }
            }
        }
        unit*=2;
        for (int i=0;i<n;i++) a[i]=store[i];
    }
    free(store);
    return;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:10:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for (int i=0;i<n;i++) scanf("%d",&a[i]);
                         ^