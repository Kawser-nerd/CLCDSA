#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 1000000000


void merge_sort(int *t1, int *s1, int left, int right);


int main(){
  char buf[1024];
  int N,M;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d", &N, &M);

  int *A=(int *)malloc(sizeof(int)*N);
  int *B=(int *)malloc(sizeof(int)*N);

  rep(i,N){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%d %d", &A[i], &B[i]);
  }

  merge_sort(A, B, 0, N-1);

  long sum=0;
  long count=0;
  int number=0;

  while(number!=N && count+B[number]<=M){
    //printf("A[%d] = %d, B[%d] = %d\n", number, A[number], number, B[number]);
    //?????????long????????????int*int??????long??????????
    sum+=(long)A[number]*B[number];
    count+=B[number];
    number++;
    //printf("%ld\n", sum);
  }

  sum+=A[number]*(M-count);

  printf("%ld\n", sum);

  return 0;

}


void merge_sort(int *t1, int *s1, int left, int right){    //?????????
    if(left==right){
        ;
    }
    else{
        int n2=(right-left+1)/2;
        int n3=right-left+1-n2;
        int i=0,j=0,k=0;

        // rep(p,n2+n3){
        //   printf("t1[%d] = %p, t1[%d][0] = %d, t1[%d][1] = %d\n", p, t1[p], p, t1[p][0], p, t1[p][1]);
        // }

        merge_sort(t1, s1, left, left+n2-1);
        merge_sort(t1, s1, left+n2, right);

        int *t2=(int *)malloc(sizeof(int)*n2);
        int *t3=(int *)malloc(sizeof(int)*n3);
        int *s2=(int *)malloc(sizeof(int)*n2);
        int *s3=(int *)malloc(sizeof(int)*n3);

        for(i=0;i<n2;i++){
          t2[i]=t1[left+i];
          s2[i]=s1[left+i];
        }
        for(i=0;i<n3;i++){
          t3[i]=t1[left+n2+i];
          s3[i]=s1[left+n2+i];
        }

        // printf("t2[0] = %d, t3[0] = %d\n", t2[0], t3[0]);
        // printf("s2[0] = %d, s3[0] = %d\n", s2[0], s3[0]);

        //??????n?????????????????????????????
        for(i=0;i<n2+n3;i++){
            if(k==n3 || (j<n2 && t2[j]<t3[k])){
                t1[left+i]=t2[j];
                s1[left+i]=s2[j];
                j++;
            }
            else{
                t1[left+i]=t3[k];
                s1[left+i]=s3[k];
                k++;
            }
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:32:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf,sizeof(buf),stdin);
     ^