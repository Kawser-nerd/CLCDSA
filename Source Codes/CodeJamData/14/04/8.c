#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int i;
  int j;
} pair;

void swap_double(double* tab, int i, int j)
{
  double tmp=tab[i];
  tab[i]=tab[j];
  tab[j]=tmp;
}

void quicksort_double_iter(double* tab, int len)
{
  pair init={0,len-1};
  int num_pairs=1;
  int i,j;
  pair* queue=calloc(len,sizeof(pair));
  queue[0]=init;
  pair cur;
  while (num_pairs > 0){
    cur=queue[num_pairs-1];
    num_pairs--;
    i=cur.i;
    j=cur.j;
    if (i >= j) continue;
    int pivot=i;
    double val=tab[pivot];
    /* fprintf(stderr,"Quicksort between %llu and %llu, pivot=%llu (val=%llu)\n",i,j,pivot,val); */
    int k;
    for (k = i; k <= j; k++) {
      if ((k < pivot) && (tab[k] > val)){
        swap_double(tab,k,pivot);
        pivot=k;
      }
      else if ((k > pivot) && (tab[k] < val)){
        swap_double(tab,pivot+1,k);
        swap_double(tab,pivot+1,pivot);
        pivot=pivot+1;
      }
    }
    if (pivot > 0){
      pair init={i,pivot-1};
      queue[num_pairs]=init;
      num_pairs++;
    }      
    pair init={pivot+1,j};
    queue[num_pairs]=init;
    num_pairs++;
  }
  free(queue);
}

void mergeWeights(int* res, double* N, double* K, int len)
/* Sorted weights, 0 for Naomi, 1 for Ken */
{
  int i=0,j=0,cur=0;
  while (cur < 2*len) {
    if (i >= len)
      res[cur]=1;
    else if (j >= len)
      res[cur]=0;
    else{
      if (N[i] < K[j]){
        res[cur]=0;
        i++;
      }
      else{
        res[cur]=1;
        j++;
      }
    }
    cur++;
  }
}

int scoreWar(int* merge, int len)
/* On a regular play, N plays her weights greatest first.  She then
   wins if w[i] is such that w[i+1]...w[i+k] belong to her and there
   isn't more than k weights belonging to K above.
*/
{
  int i=len-1;
  int res=0;
  int balance=0;
  for(i=len-1;i>=0;i--){
    if ((merge[i]==0) && (balance==0))
      res++;
    else if (merge[i]==0)
      balance--;
    else
      balance++;
  }
  return res;
}

int scoreDeceitfulWar(int* merge, int len)
/* N loses what K would win if he was playing first with the optimal
   strategy.
*/
{
  int i=len-1;
  int res=len/2;
  int balance=0;
  for(i=len-1;i>=0;i--){
    if ((merge[i]==1) && (balance==0))
      res--;
    else if (merge[i]==1)
      balance--;
    else
      balance++;
  }
  return res;
}


int main ()
{
  int T;
  scanf("%d",&T);
  int num;
  double* N;
  double* K;
  int Sd,Sw;
  int i,j;
  int* merge;
  for (i = 1; i <= T; i++) {
    printf("Case #%d: ",i);
    scanf("%d",&num);
    N=(void*)calloc(num,sizeof(double));
    K=(void*)calloc(num,sizeof(double));
    merge=(void*)calloc(2*num,sizeof(int));
    for (j=0;j<num;j++)
      scanf("%lf",&N[j]);
    for (j=0;j<num;j++)
      scanf("%lf",&K[j]);
    quicksort_double_iter(N,num);
    quicksort_double_iter(K,num);

    mergeWeights(merge,N,K,num);
    
    Sw=scoreWar(merge,2*num);
    Sd=scoreDeceitfulWar(merge,2*num);
    
    printf("%d %d\n",Sd,Sw);
    
    free(N);
    free(K);
    free(merge);
  }
  return 0;
}
