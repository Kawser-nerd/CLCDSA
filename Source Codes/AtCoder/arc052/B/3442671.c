#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define LINE_BUF_SIZE 1024
# define pai 3.14125

int main()
{
  static char line[LINE_BUF_SIZE]; // ????????????????

  int n, q; /* ??????N????????Q */

  int x[100]; /* ?????????x?? */
  int r[100]; /* ???????? */
  int h[100]; /* ????? */

  int a[100]; /* ???A */
  int b[100]; /* ???B */

  int row;
  int step;

  int i,j;

  /* ????????????????? */
  float hh;
  float r1;
  float r2;
  float sum;
  float v;

  row = 0;
  step = 0;

  // TODO?????????????
  while (fgets(line, sizeof(line), stdin) != NULL)
  {
        switch(step)
        {
        case 0:
          if (sscanf(line, "%d %d", &n, &q) != 2)
          {
                // ??????
                return EXIT_FAILURE;
          }
          step = 1;
          break;
        case 1: // ???????
          if (sscanf(line, "%d %d %d", &x[row], &r[row], &h[row]) != 3)
          {
                // ??????
          }
          row++;
          if (row >= n)
          {
                row = 0;
                step = 2;
          }
          break;
        case 2: // ?????
          if (sscanf(line, "%d %d", &a[row], &b[row]) != 2)
          {
                // ??????
          }
          row++;
          if (row >= q)
          {
                step = 3;
          }
          break;
        default:
          break;
        }
        if (step >= 3)
        {
          break;
        }
  }

  /* ????? */
  for (i=0; i < q; i++)
  {
        sum = 0.0;
        /* ?????????? */
        for (j=0; j<n; j++)
        {
          /*
                ??????????????? PI/3*h*(r1*r1 + r1*r2 + r2*r2)

                ??????????
                1. ???
                  1-1. ???B( X+H > B )????R(A <= X )
                  1-2. ???B????A( X < A )
                2. ???xx???
                  1-1. ???R(A <= X)  X+H <= B
                  1-2. ???A( X < A ) X+H <= B
           */
          //printf("Q:%d, N:%d, X:%d, H:%d, R:%d, A:%d, B:%d \n", i, j, x[j], h[j], r[j], a[i], b[i]);
          if ( (a[i] <= x[j]) && (x[j] + h[j] <= b[i]) )
          {
                /* ????? */
                hh = h[j];
                r1 = r[j];
                v = M_PI/3.0*hh*(r1*r1);
                //printf("(A) N:%d, Q:%d, ??:%f, ??:%f, ??:%f\n", j, i, r1, hh, v);
                sum += v;
          }
          else if ( (a[i] <= x[j]) && (x[j] <= b[i]) && (b[i] < x[j] + h[j]) )
          {
                /* ?????? */
                hh = b[i] - x[j];
                r1 = r[j];
                r2 = r1*((float)(h[j]-hh)/h[j]);
                v = M_PI/3.0*hh*(r1*r1 + r1*r2 + r2*r2);
                //printf("(B) N:%d, Q:%d, ??:%f, ??:%f, ??:%f, ??:%f\n", j, i, r1, r2, hh, v);
                sum += v;
          }
          else if ( (x[j] < a[i]) && (a[i] < x[j] + h[j]) && (x[j] + h[j] < b[i]) )
          {
                /* ????? */
                hh = a[i] - x[j];
                r1 = r[j]*((float)(h[j]-hh)/h[j]);
                v = M_PI/3.0*(h[j]-hh)*(r1*r1);
                //printf("(C) N:%d, Q:%d, ??:%f, ??:%f, ??:%f\n", j, i, r1, hh, v);
                sum += v;
          }
          else if ( (x[j] < a[i]) && (b[i] <= x[j] + h[j]) )
          {
                /* ?????? */
                hh = a[i] - x[j];
                r1 = r[j]*((float)(h[j]-hh)/h[j]);
                hh = b[i] - x[j];
                r2 = r[j]*((float)(h[j]-hh)/h[j]);
                v = M_PI/3.0*(b[i]-a[i])*(r1*r1 + r1*r2 + r2*r2);
                //printf("(D) N:%d, Q:%d, ??:%f, ??:%f, ??:%f, ??:%f\n", j, i, r1, r2, (float)(b[i]-a[i]), v);
                sum += v;
          }
          else if ( (b[i] <= x[j]) || (x[j] + h[j] < a[i]) )
          {
                // ?????
          }
        }
        printf("%f\n", sum);
  }

  return EXIT_SUCCESS;
}