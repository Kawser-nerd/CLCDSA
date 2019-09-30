#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
typedef struct LIST{
    int to;
    struct LIST *next;
}Edge;
Edge *edge[100001];
int used[100001];
int ans[100000];
int size1=0,size2=0;
void add(int v,int t){
    Edge *temp = (Edge*)malloc(sizeof(Edge));
    temp->to=t;
    temp->next=edge[v];
    edge[v]=temp;
    return;
}
void end(int v){
    for(int i=1;i<=v;i++){
        for(Edge *e=edge[i]->next;e!=NULL;e=e->next){
            free(e);
        }
    }
    return;
}
int check(int v){
    for(Edge *e=edge[v];e!=NULL;e=e->next){
        if(!used[e->to]) return e->to;
    }
    return -1;
}
int main(void){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    FOR(i,0,m){
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    int s=1,g=edge[1]->to;
    used[s]=used[g]=1;
    ans[size1++]=s;
    while(1){
        int t=check(s);
        if(t==-1) break;
        else{
            s=t;
            used[s]=1;
            ans[size1++]=s;
        }
    }
    size2 = size1;
    ans[size2++]=g;
    while(1){
        int t=check(g);
        if(t==-1) break;
        else{
            g=t;
            used[g]=1;
            ans[size2++]=g;
        }
    }
    printf("%d\n",size2);
    for(int i=size1-1;i>=0;i--) printf("%d\n",ans[i]);
    for(int i=size1;i<size2;i++) printf("%d\n",ans[i]);
    
    end(n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&m);
     ^
./Main.c:37:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a,&b);
         ^