#include <stdio.h>

int C,D,V;

int coin[200];
int value[200];

void add(int v) {
    int i;
    //printf("add %d\n",v);
    for (i=V-v;i>=0;i--) {
        if (value[i]) value[i+v]=1;
    }
}

void bf(void) {
    int i,j,extra=0;
    scanf("%d %d %d", &C, &D, &V);
    for (i=0;i<D;i++) scanf("%d",coin+i);
    for (i=1;i<=V;i++) value[i]=0;
    value[0]=1;
    for (i=0;i<D;i++) {
        for (j=0;j<C;j++) add(coin[i]);
    }
    /*
    printf("\n");
    for (i=0;i<=V;i++) printf("%d:%d ",i,value[i]);
    printf("\n");
    */
    for (i=0;i<=V;i++) {
        if (value[i]==0) {
            //printf("[%d] ",i);
            for (j=0;j<C;j++) add(i);
            extra++;
        }
    }
    printf("%d\n",extra);
}

int main(int argc, char **argv) {
    int T;
    int i;
    scanf("%d",&T);
    for (i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        bf();
    }
    return 0;
}
