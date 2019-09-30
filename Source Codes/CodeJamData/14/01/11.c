#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

uint32_t intersectRows(uint32_t row1, uint32_t row2)
{
  uint32_t res=row1&row2;
  return res;
}

uint32_t addToCards(uint32_t res, int card)
{
  uint32_t add=(1 << (card-1));
  return res+add;
}

int findSolutions(uint32_t inter)
{
  /* Finds the solutions in the intersection. If none, return 0. If
     exactly 1, returns that solution. If more than one, returns
     17. */
  int res=0;
  int i;
  uint32_t tmp=inter;
  uint32_t m=0;
  for (i = 0; i < 16; i++) {
    m=(tmp%2);
    if (m==1){
      if (res == 0)
        res=(i+1);
      else if (res < 17){
        res=17;
        break;
      }
    }
    tmp=(tmp>>1);
  }
  return res;
}

void printRes(int c, int num){
  printf("Case #%d: ", c);
  if (num == 0)
    printf("Volunteer cheated!");
  else if (num < 17)
    printf("%d",num);
  else
    printf("Bad magician!");
  printf ("\n");
}

int main ()
{
  int T;
  int rows[2];
  int card;
  uint32_t inter;
  int c,row,col,i;
  int res;
  uint32_t tab[2][4];
  scanf("%d",&T);
  for (c=1;c<=T;c++){
    for (i=0;i<2;i++){
      scanf("%d",&rows[i]);
      for (row=0;row<4;row++){
        tab[i][row]=0;
        for (col=0; col<4; col++){
          scanf("%d",&card);
          tab[i][row]=addToCards(tab[i][row],card);
        }
      }
    }
    inter=intersectRows(tab[0][rows[0]-1],tab[1][rows[1]-1]);
    res=findSolutions(inter);
    printRes(c,res);
  }
  return 0;
}
