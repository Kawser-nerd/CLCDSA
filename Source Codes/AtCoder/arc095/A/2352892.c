#include <stdio.h>
#include <stdlib.h>
void MergeSort(long long int x[ ],long long int left,long long int right);
        long long int temp[200001];
int main (void){
        int ans;
        int N;
        long long int A[200001];
        long long int B[200001];

        scanf("%d",&N);
        for (int i = 0; i < N; i++) {
                scanf("%lld",&A[i]);
                B[i]=A[i];
        }

MergeSort(A, 0, N-1);
if(N==2){
  printf("%lld\n",A[1]);
  printf("%lld\n",A[0]);
}else{
for (int i = 0; i < N; i++) {
  if (B[i]<=A[(N/2)-1]) {
    printf("%lld\n",A[N/2]);
  }else{
    printf("%lld\n",A[(N/2)-1]);
  }
      }
}
        return 0;
}

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
} ./Main.c: In function ‘main’:
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&N);
         ^
./Main.c:13:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%lld",&A[i]);
                 ^