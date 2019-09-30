#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int isPossible(int r, int c, int m)
{
  int empty=r*c -m;
  if (empty <= 0)
    return 0;
  else if (empty>=2 && empty<4)
    return (r==1 || c==1);
  else
    return 1;
}

/* void fillMineArea(int* tab, int r, int c, int m) */
/* /\* Fills the board tab with m mines. The top-left corner is a forbidden area: */
/*    [ 0 X (...) ] */
/*    [ X X (...) ] */
/*    [ (.......) ]*\/ */
/* { */
/*   int j=r-1; */
/*   int i=c-1; */
/*   int cur; */
/*   int limitj; */
/*   int limiti=0; */
/*   if (r*c-m == 1) */
/*     limitj=1; */
/*   else */
/*     limitj=2; */
/*   tab[0]=2; */
/*   for(cur=0; cur<m; cur++){ */
/*     /\* fprintf(stderr,"Putting a mine at position (%d,%d)\n",i,j); *\/ */
/*     tab[c*j+i]=1; */
/*     i--; */
/*     if (i < limiti){ */
/*       i=c-1; */
/*       j--; */
/*       if (j < limitj) */
/*         limiti=limitj; */
/*     } */
/*   } */
/* } */

int getTabValue(int* tab, int r, int c, int i, int j)
{
  if ((i < 0) || (j < 0) || (i >= c) || (j >= r))
    return -1;
  else
    return tab[c*j+i];
}

int setTabValue(int* tab, int r, int c, int i, int j, int v)
{
  if ((i < 0) || (j < 0) || (i >= c) || (j >= r))
    return 0;
  else{
    tab[c*j+i]=v;
    return 1;
  }
}


int fillMineArea(int* tab, int r, int c, int m)
/* 0 for a mine, 1 for no mine, 2 for the initial click */
{
  int neighborsi[8]={-1,0,1,-1,1,-1,0,1};
  int neighborsj[8]={-1,-1,-1,0,0,1,1,1};
  int cur=r*c-m-1;
  int i=0,j=0,k;
  int ni=0,nj=0;
  int cnt;
  tab[0]=2; // Initial click
  for (j=0;j<r;j++){
    for (i=0;i<c;i++){
      if (getTabValue(tab,r,c,i,j)>0){
        cnt=0;
        for (k=0;k<8;k++){ // Check that we can claim those neighbors
          ni=i+neighborsi[k];
          nj=j+neighborsj[k];
          if (getTabValue(tab,r,c,ni,nj) == 0){ // Not claimed yet
            cnt++;
          }
        }
        if ((cnt > cur) || ((cnt == cur -1) && (r>1) && (c>1))) continue;
        /* If there is only one space to claim after claiming all
           these neighbors, we are likely to be in trouble, so we give
           up. In the border cases, the neighbor at stake will
           reappear later with cnt==cur. */
        for (k=0;k<8;k++){
          ni=i+neighborsi[k];
          nj=j+neighborsj[k];
          if (getTabValue(tab,r,c,ni,nj) == 0){ // Not claimed yet
            (void)setTabValue(tab,r,c,ni,nj,1);
            cur--;
          }
        }
      }
    }
  }
  /* fprintf(stderr,"Exitting the loop, remains %d empty spots to place\n",cur); */
  if (cur==0)
    return 0;
  else
    return 1;
}

void printMineArea(int* tab, int r, int c)
{
  int i,j;
  for (j=0;j<r;j++){
    for (i=0;i<c;i++){
      if (tab[c*j+i]==2)
        printf("%c",'c');
      else if (tab[c*j+i]==1){
        printf("%c",'.');
        /* fprintf(stderr,"Printing a mine at position (%d,%d)\n",i,j); */
      }
      else
        printf("%c",'*');
    }
    printf("\n");
  }
}



int main()
{
  int i;
  int T;
  scanf("%d",&T);
  int r,c,m;
  int test;
  int* tab;
  for (i = 1; i <= T; i++) {
    scanf("%d %d %d",&r,&c,&m);
    printf("Case #%d:\n",i);
    tab=(void*)calloc(r*c,sizeof(int));
    test=fillMineArea(tab,r,c,m);
    if (test==0)
      printMineArea(tab,r,c);
    else{
      printf("Impossible\n");
      /* printMineArea(tab,r,c); */
    }
    free(tab);
  }
    
  return 0;
}
