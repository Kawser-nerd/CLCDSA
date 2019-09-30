#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
???????????
???????
*/
#define max 9223372036854775807

long long Max(long long a,long long b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

void merge(long long *a,int left,int mid,int right){
        int n1 = mid - left;
        int n2 = right - mid;
        long long L[n1+1],R[n2+1];
        int i;
        for(i=0;i<n1;i++){
            L[i] = a[left + i];
        }
        for(i=0;i<n2;i++){
            R[i] = a[mid + i];
        }
        L[n1]=max;
        R[n2]=max;
        int j=0,k=0;
        for(i=left;i<right;i++){
            if(L[j]<R[k]){
                a[i] = L[j];
                j++;
            }
            else{
                a[i] = R[k];
                k++;
            }
        }

}


void merge_sort(long long *a,int left,int right){
    int middle;
    if(left + 1 < right){
        middle = (left + right)/2;
        merge_sort(a,left,middle);
        merge_sort(a,middle,right);
        merge(a,left,middle,right);
    }
}


int main(void){
    int i,N,M;
    scanf("%d %d",&N,&M);
    long long x[N],y[N],z[N],val1[N],val2[N],val3[N],val4[N],val5[N],val6[N],val7[N],val8[N];
    for(i=0;i<N;i++){
        scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
        val1[i]=x[i]+y[i]+z[i];
        val2[i]=((-1)*x[i])+y[i]+z[i];
        val3[i]=x[i]+((-1)*y[i])+z[i];
        val4[i]=x[i]+y[i]+((-1)*z[i]);
        val5[i]=x[i]+(-1)*(y[i]+z[i]);
        val6[i]=y[i]+(-1)*(x[i]+z[i]);
        val7[i]=z[i]+(-1)*(x[i]+z[i]);
        val8[i]=(-1)*val1[i];
    }
    merge_sort(val1,0,N);
    merge_sort(val2,0,N);
    merge_sort(val3,0,N);
    merge_sort(val4,0,N);
    merge_sort(val5,0,N);
    merge_sort(val6,0,N);
    merge_sort(val7,0,N);
    merge_sort(val8,0,N);
    for(i=N-1;i>0;i--){
        val1[i-1]+=val1[i];
        val2[i-1]+=val2[i];
        val3[i-1]+=val3[i];
        val4[i-1]+=val4[i];
        val5[i-1]+=val5[i];
        val6[i-1]+=val6[i];
        val7[i-1]+=val7[i];
        val8[i-1]+=val8[i];
    }
    long long ans = Max(Max(Max(val1[N-M],val2[N-M]),Max(val3[N-M],val4[N-M])),Max(Max(val5[N-M],val6[N-M]),Max(val7[N-M],val8[N-M])));
    printf("%lld\n",ans);


    return 0;
} ./Main.c: In function ‘main’:
./Main.c:59:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:62:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
         ^