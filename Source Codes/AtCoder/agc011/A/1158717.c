#include<stdio.h>
#include<stdlib.h>
int *temp;

void MergeSort(int x[ ], int left, int right)
{
    int mid, i, j, k;
	
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

int main()
{
int N,C,K,B,P,s,F;
int *T;
int i,j;

scanf("%d %d %d",&N,&C,&K);
T = (int *)malloc(N * sizeof(int));
temp = (int *)malloc(N * sizeof(int));

B=1;
P=0;

for(i=0;i<N;i++){
scanf("%d",&T[i]);
}

MergeSort(T,0,N-1);

F=T[0];
for(i=0;i<N;i++){
if(P<C && (T[i]-F)<=K){
P++;
}else if(P==C || (T[i]-F)>K){
B++;
P=1;
F=T[i];
}
}

printf("%d",B);
free(T);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d %d",&N,&C,&K);
 ^
./Main.c:49:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&T[i]);
 ^