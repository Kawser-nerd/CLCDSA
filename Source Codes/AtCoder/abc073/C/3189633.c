#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/*
?????
????????


*/

#define max 2147483647

void merge(int *a,int left,int mid,int right){
        int n1 = mid - left;
        int n2 = right - mid;
        int L[n1+1],R[n2+1];
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


void merge_sort(int *a,int left,int right){
    int middle;
    if(left + 1 < right){
        middle = (left + right)/2;
        merge_sort(a,left,middle);
        merge_sort(a,middle,right);
        merge(a,left,middle,right);
    }
}

/*
????????
a[n]?????????->counter += 1

?????????

*/

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n);
    int now,c = 1,counter = 0;
    now = a[0];
    for(i=1;i<n;i++){
        if(a[i] == now){
            c++;
        }else{
            now = a[i];
            counter += c%2;
            c=1;
        }
    }
    counter += c%2;

    printf("%d\n",counter);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:62:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:66:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^