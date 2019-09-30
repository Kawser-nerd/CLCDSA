#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// A=0, K=0 ==> B=x
// A=0, K=1 ==> none
// A=1, K=0 ==> B=0
// A=1, K=1 ==> B=1
// total = 3^k
// x1 = #(a < A, b < B)
// x2 = #(a < A, b >= B)
// x3 = #(a >= A, b < B)
// x4 = #(a >= A, b >= B)
// x1 + x2 + x3 = 3^k
int main(void)
{
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++)
  {
    unsigned int A, B, K;
    scanf("%u %u %u", &A, &B, &K);

    //int count = 0, counta = 0, countb = 0, countab = 1;
    uint64_t counts[8] = {0};
    counts[7] = 1;
    for (int bit = 30; bit >= 0; bit--)
    {
      unsigned int mask = (1u << bit);
      bool aset = ((A & mask) != 0);
      bool bset = ((B & mask) != 0);
      bool kset = ((K & mask) != 0);
      uint64_t newcounts[8] = {0};
      for (int x = 0; x < 4; x++)
      {
        bool a = ((x & 1) != 0);
        bool b = ((x & 2) != 0);
        bool k = (a && b);
        for (int i = 0; i < 8; i++)
        {
          int idx = i;
          if (!a && aset)
            idx &= ~1;
          else if (a && !aset && (i & 1))
            continue;

          if (!b && bset)
            idx &= ~2;
          else if (b && !bset && (i & 2))
            continue;

          if (!k && kset)
            idx &= ~4;
          else if (k && !kset && (i & 4))
            continue;

          newcounts[idx] += counts[i];
          //if (counts[i] > 0)
          //  printf("  x=%d i=%d idx=%d (==> %d)\n", x, i, idx, newcounts[idx]);
        }

      }
      memcpy(counts, newcounts, sizeof(counts));
      /*
      if (kset)
      {
        if (aset)
        {
          if (bset)
          {
            count = 4*count + 2*counta + 2*countb + countab;
            counta = 2*counta + countab;
            countb = 2*countb + countab;
            //countab = countab;
          }
          else
          {
            count = 4*count + 2*counta;
            counta = 2*counta;
            countb = 2*countb + countab;
            //countab = countab;
          }
        }
        else
        {
          if (bset)
          {
            count = 4*count + 2*countb;
            counta = 2*counta + countab;
            countb = 2*countb;
            //countab = countab;
          }
          else
          {
            count = 4*count;
            counta = 2*counta;
            countb = 2*countb;
            //countab = countab;
          }
        }
      }
      else
      {
        if (aset)
        {
          if (bset)
          {
            count = 3*count + 2*counta + 2*countb + countab;
            counta = counta + countab;
            countb = countb + countab;
            countab = 0;
          }
          else
          {
            count = 3*count + 2*counta;
            //counta = counta;
            countb = 2*countb + countab;
            //countab = countab;
          }
        }
        else
        {
          if (bset)
          {
            count = 3*count + 2*countb;
            counta = 2*counta + countab;
            //countb = countb;
            //countab = countab;
          }
          else
          {
            count = 3*count;
            counta = 2*counta;
            countb = 2*countb;
            //countab = countab;
          }
        }
      }
      */

      //printf("bit=%d count=%d counta=%d countb=%d countab=%d\n", bit, count, counta, countb, countab);
      /*
      printf("bit=%d", bit);
      for (int i = 0; i < 8; i++)
        printf(" c[%d]=%d", i, counts[i]);
        printf("\n");//*/
    }

    printf("Case #%d: %lld\n", t, counts[0]);
  }

  return 0;
}
