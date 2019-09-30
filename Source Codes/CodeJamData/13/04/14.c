
#include <stdio.h>
#include <stdlib.h>

//exponential 2**n like karps tsp
//really O(n * 2**n)
//might need to renumber keys

/*TODO allow big keys
    print first valid path
*/
typedef struct node {
    struct node *next;
    int key;
} node;

int K,N;

int keyin[30];
node *keyout[30];

int maxkey;
int printme;

char *state; //0=unexplored 1=explored

int found;
int path[30];


void readall(void) {
    int i,j,ki,nk,ko;
    node *q;
    maxkey=0;
    scanf("%d %d",&K,&N);
    //printf("K=%d N=%d\n",K,N);
    for (j=0;j<K;j++) {
        q=malloc(sizeof(node));
        scanf("%d",&(q->key));
        if (q->key >maxkey) maxkey=q->key;
        (q->key)--;
        //printf("Start key %d\n",q->key+1);
        q->next=keyout[N];
        keyout[N]=q;
    }
    for (i=0;i<N;i++) {
        scanf("%d %d",&ki,&nk);
        if (ki>maxkey) maxkey=ki;
        ki--;
        keyin[i]=ki;
        keyout[i]=NULL;
        for (j=0;j<nk;j++) {
            scanf("%d",&ko);
            if (ko>maxkey) maxkey=ko;
            ko--;
            q=malloc(sizeof(node));
            q->key=ko;
            q->next=keyout[i];
            keyout[i]=q;
        }
    }
    state=calloc(1<<N,sizeof(char));
}

void addkeys(int *cnt, int chest, int sign) {
    node *q;
    if (chest<N) {
        //printf("addkeys ch=%d kin=%d kout=",chest,keyin[chest]);
        cnt[keyin[chest]]-=sign;
    }
    q=keyout[chest];
    while (q) {
        //printf("%d ",q->key);
        cnt[q->key]+=sign;
        q=q->next;
    }
    //printf("\n");
}

void dumpkeys(int *kcnt) {
    int i;
    for (i=0;i<maxkey;i++) {
        printf("%d:%d ",i+1,kcnt[i]);
    }
    printf("\n");
}

void freeall(void) {
    int i;
    node *q,*f;
    free(state);
    for (i=0;i<30;i++) {
        q=keyout[i];
        keyout[i]=NULL;
        while (q) {
            f=q;
            q=q->next;
            free(f);
        }
    }
}

void explore2(int st,int *keycnt, int depth) {
    int b;
    if (found) return;
    if (depth==N) {
        for (b=0;b<N;b++) printf("%d ",path[b]+1);
        printf("\n");
        found=1;
        return;
    }
    for (b=0;b<N && !found;b++) {
        //printf("ch%d and=%x st=%x kc=%d\n",b,(st & (1<<b)),state[st ^ (1<<b)],keycnt[keyin[b]]);
        if (    (st & (1<<b))==0 && 
                state[st ^ (1<<b)]==0x0 && 
                keycnt[keyin[b]]>0) {
            addkeys(keycnt,b,1);
            path[depth]=b;
            explore2(st ^ (1<<b) ,keycnt,depth+1);
            addkeys(keycnt,b,-1);
            state[st ^ (1<<b)]=1;
        }
    }
}

void explore(void) {
    static int keycnt[440];
    int b;
    int st;
    //printf("firstest\n");
    //printf("states=");
    //for (b=0;b<(1<<N);b++) printf("%x ",state[b]);
    for (b=0;b<maxkey;b++) keycnt[b]=0;
    addkeys(keycnt,N,1);
    st=0;
    found=0;
    explore2(st,keycnt,0);
}

void treasure(void) {
    readall();
    printme=0;
    explore();
    
    if (!found) printf("IMPOSSIBLE\n");
    freeall();
}

int main(int argc, char **argv) {
    int i,t;
    scanf("%d\n",&t);
    for (i=1;i<=t;i++) {
        printf("Case #%d: ",i);
        treasure();
    }
    return 0;
}