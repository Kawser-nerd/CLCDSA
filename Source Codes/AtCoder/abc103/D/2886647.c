#include <stdio.h>
#include <stdlib.h>

#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

typedef struct {
    int left, right;
}Range;

Range island[100005];

int Range_cmp(const void *p, const void * q);

int main()
{
    int n, m;
    int i, j, k;
    int ans = 1;
    Range temp;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++){
        scanf("%d %d", &island[i].left, &island[i].right);
    }

    qsort(island, m, sizeof(Range), Range_cmp);

    temp.left = 0; temp.right = n;
    for (i = 0; i < m; i++) {
        if (temp.right <= island[i].left || temp.left >= island[i].right) {
            ans++;
            temp.left = island[i].left; temp.right = island[i].right;
        } else {
            temp.left = max(temp.left, island[i].left);
            temp.right = min(temp.right, island[i].right);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}

int Range_cmp(const void *p, const void * q)
{
    int ret;

    ret = (((Range *)p)->left < ((Range *)q)->left ? 1 :
           ((Range *)p)->left ==((Range *)q)->left && ((Range *)p)->right < ((Range *)q)->right ? 1 :
           0);
        
    return ret;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:24:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &island[i].left, &island[i].right);
         ^