#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int main(void)
{
    int i;
    int n, m;
    int *xs;
    int sum = 0;
    
    scanf("%d %d", &n, &m);
    
    xs = malloc(m * sizeof(int));
    
    for(i = 0; i < m; ++i){
        scanf("%d", &xs[i]);
    }
  
    qsort(xs, m, sizeof(int), cmp);
    
    for(i = m-1; i > 0; --i){
        xs[i] -= xs[i-1];  //1..m-1: distances
    }
    
    qsort(&xs[1], m-1, sizeof(int), cmp);
  
    for(i = 1; i <= m-n; ++i)
        sum += xs[i]; 
  
    printf("%d", sum);
  
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &xs[i]);
         ^