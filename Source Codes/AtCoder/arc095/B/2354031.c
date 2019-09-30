#include <stdio.h>
#include <string.h>

long long int temp[100000];
void MergeSort(long long int x[ ],long long int left,long long int right)
{
    long long int mid, i, j, k;

    if (left >= right)              /* ??????????? */
        return;                     /* ???????? */

                                    /* ???????????? */
    mid = (left + right) / 2;       /* ?????? */
    MergeSort(x, left, mid);        /* ???????? */
    MergeSort(x, mid + 1, right);   /* ???????? */

      /* x[left] ?? x[mid] ????????? */
    for (i = left; i <= mid; i++)
        temp[i] = x[i];

      /* x[mid + 1] ?? x[right] ??????? */
    for (i = mid + 1, j = right; i <= right; i++, j--)
        temp[i] = x[j];

    i = left;         /* i ?j ??????????? */
    j = right;        /* k ???????????? */

    for (k = left; k <= right; k++)    /* ??????????? */
        if (temp[i] <= temp[j])        /* ????????? */
            x[k] = temp[i++];
        else
            x[k] = temp[j--];
}


int main (void){
int N;
long long int max;
long long int ans;
long long int A[100000];
scanf("%d",&N);
for (int i = 0; i < N; i++) {
        scanf("%lld",&A[i]);
}
MergeSort(A, 0, N-1);
max=A[N-1]/2;
if (N==2) {
  ans=A[0];
}else{
for (int i = 1; i < N-1; i++) {
if (max<=A[i]) {
  if (A[i]-max<=max-A[i-1]) {
    ans=A[i];
  }else{
    ans=A[i-1];
  }
  break;
}
}
}
printf("%lld %lld\n",A[N-1],ans);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&N);
 ^
./Main.c:43:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&A[i]);
         ^