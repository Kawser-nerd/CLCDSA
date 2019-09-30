#include <stdio.h>
#include <math.h>

int main(void)
{
  int N, Q;  //N:?????,Q:??????
  int X[200], R[200], H[100], A[100], B[100], h[100];
  double V[200];  //??

  scanf("%d %d", &N, &Q);

  int i, j;
  double tmp1, tmp2;
  for (i = 0; i < N; i++)
    scanf("%d %d %d", &X[i], &R[i], &H[i]);
  for (i = 0; i < Q; i++)
    scanf("%d %d", &A[i], &B[i]);

  for (i = 0; i < Q; i++) {
    V[i] = 0;
    for(j = 0; j < N; j++) {
      h[j] = H[j] + X[j];
      if (h[j] < A[i] || B[i] < X[j])  { //??????????????????
        V[i] += 0;
      }
      else {
        if (A[i] <= X[j]) {     //?????????);
          if (h[j]<= B[i])  //B????
            V[i] += ( R[j]*R[j]*M_PI*H[j] / 3);
          else   {           //B?????
            tmp1 = R[j]*R[j]*M_PI*H[j] / 3;
            tmp2 = (double)(h[j]-B[i])*R[j] / H[j];  //????????
            V[i] += ( tmp1 - (tmp2*tmp2*M_PI*(h[j]-B[i])/3) );
              }
        }
        else {      //A???????
          if (h[j] < B[i]) {   //B???????
            tmp1 = (double)(h[j]-A[i])*R[j] / H[j];
            V[i] += (tmp1*tmp1*M_PI*(h[j]-A[i]) / 3);
          }
          else  {  //B????
            tmp1 = (double)(h[j]-A[i])*R[j] / H[j];
            tmp2 = tmp1*tmp1*M_PI*(h[j]-A[i])/3;
            tmp1 = (double)(h[j]-B[i])*R[j]/H[j];
            V[i] += ( tmp2 - (tmp1*tmp1*M_PI*(h[j]-B[i])/3) );
          }
       }

      }

    }  //?????
  }


  for (i = 0; i < Q; i++) {
    printf("%lf\n", V[i]);
  }


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &Q);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &X[i], &R[i], &H[i]);
     ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &A[i], &B[i]);
     ^