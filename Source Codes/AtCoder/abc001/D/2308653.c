#include <stdio.h>
#include <stdlib.h>

int ho_mi_list[288]; // 0 0000-0005
                     // 1 0005-0010
                     // 2 0010-0015

void write_list(int ho, int mi, int con);
int   read_list(int ho, int mi);
void  round_back(int* n);
void round_front(int* n);

int main(void) {
  int inputs;
  int i, ho, mi;
  int tmp1, tmp2;
  int ho1, mi1, ho2, mi2;
  int before;
  scanf("%d", &inputs);
  for (i = 0; i < inputs; i++) {
    scanf("%d-%d", &tmp1, &tmp2);
    ho1 = tmp1 / 100;
    mi1 = tmp1 % 100;
    ho2 = tmp2 / 100;
    mi2 = tmp2 % 100;
    round_back(&mi1);
    round_front(&mi2);
    if (mi2 == 60) {
    	ho2++;
      	mi2 = 0;
    }
    ho = ho1;
    mi = mi1;
    while (ho2 * 100 + mi2 > ho * 100 + mi) {
      write_list(ho, mi, 1);
      mi += 5;
      if (mi >= 60) {
        mi = 0;
        ho++;
      }
    }
  }
  before = 0;
  for (ho = 0; ho <= 23; ho++) {
    for (mi = 0; mi <= 55; mi += 5) {
      if (read_list(ho, mi) == 1) {
        if (before == 0) {
   	      ho1 = ho;
    	  mi1 = mi;
       	  before = 1;
        }
      } else if (before == 1) {
      	before = 0;
        printf("%02d%02d-%02d%02d\n", ho1, mi1, ho, mi);
      }
    }
  }
  if (before == 1) {
    printf("%02d%02d-2400\n", ho1, mi1);
  }
  return 0;
}

void write_list(int ho, int mi, int con) {
  ho_mi_list[ho * 12 + mi / 5] = con;
}

int read_list(int ho, int mi) {
  return ho_mi_list[ho * 12 + mi / 5];
}

void round_back(int* n) {
  if (*n % 5 != 0) {
  	*n -= *n % 5;
  }
}

void round_front(int* n) {
  if (*n % 5 != 0) {
  	*n += 5 - *n % 5;
  }
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &inputs);
   ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d-%d", &tmp1, &tmp2);
     ^