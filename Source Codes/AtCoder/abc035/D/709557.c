#include<stdio.h>
#include<limits.h>

typedef struct{
    long long key;
    int no;
}binheapnode;

typedef struct{
    binheapnode node[1000000];
    int p;
}binheap;

typedef struct{
    int no;
    long long dis;
    int next;
}listgraphedge;

typedef struct{
    listgraphedge edge[100000];
    int node[100000];
    int p;
}listgraph;

binheap heap;
listgraph graph,graphrev;

long long a[100000],sum[100000],sumrev[100000];


void binheapformat(binheap *a){
    a->p = 0;
}

void binheapadd(binheap *a,long long inkey,int inno){
    int i,j,k;
    long long l;

    a->node[a->p].key = inkey;
    a->node[a->p].no = inno;

    i = a->p;
    a->p++;

    while(i != 0){
        j = (i - 1) / 2;
        if(a->node[i].key < a->node[j].key){
            l = a->node[i].key;
            a->node[i].key = a->node[j].key;
            a->node[j].key = l;
            k = a->node[i].no;
            a->node[i].no = a->node[j].no;
            a->node[j].no = k;
        }else
            break;
        i = j;
    }
}

void binheapout(binheap *a,long long *outkeyp,int *outnop){
    int i,j,k;
    long long l;
    if(a->p == 0){
        a->p--;
        return;
    }

    *outkeyp = a->node[0].key;
    *outnop = a->node[0].no;

    a->p--;
    a->node[0].key = a->node[a->p].key;
    a->node[0].no = a->node[a->p].no;

    i = 0;
    while(i * 2 + 1 < a->p){
        j = i * 2 + 1;
        if(a->node[j].key > a->node[j + 1].key && j + 1 < a->p)
            j++;
        if(a->node[i].key > a->node[j].key){
            l = a->node[i].key;
            a->node[i].key = a->node[j].key;
            a->node[j].key = l;
            k = a->node[i].no;
            a->node[i].no = a->node[j].no;
            a->node[j].no = k;
        }else
            break;
        i = j;
    }
}

void listgraphformat(listgraph *a,int numofnode){
    int i;
    a->p = 0;
    for(i = 0;i < numofnode;i++){
        a->node[i] = (-1);
    }
}

void listgraphin(listgraph *aa,int a,int b,long long dis){
    aa->edge[aa->p].next = aa->node[a];
    aa->edge[aa->p].no = b;
    aa->edge[aa->p].dis = dis;
    aa->node[a] = aa->p;
    aa->p++;
}

void listgraphmindis(listgraph *graph,long long sum[],int numofnode){
    int i,j,k,pre;
    long long dis;

    binheapformat(&heap);
    sum[0] = 0;
    for(i = 1;i < numofnode;i++)
        sum[i] = (-1);
    pre = 0;
    for(i = 1;i < numofnode;i++){
        j = graph->node[pre];
        while(j != (-1)){
            k = graph->edge[j].no;
            if(sum[k] == (-1))
                binheapadd(&heap,graph->edge[j].dis + sum[pre],k);
            j = graph->edge[j].next;
        }

        do{
            binheapout(&heap,&dis,&pre);
            if(heap.p < 0)
                return;
        }while(sum[pre] != (-1));
        sum[pre] = dis;
    }
}

int main(void){
    int i,j,k,n,m;
    long long x,max,t;

    scanf("%d %d %lld",&n,&m,&t);

    listgraphformat(&graph,n);
    listgraphformat(&graphrev,n);

    for(i = 0;i < n;i++)
        scanf("%lld",&a[i]);
    for(i = 0;i < m;i++){
        scanf("%d %d %lld",&j,&k,&max);
        listgraphin(&graph,j - 1,k - 1,max);
        listgraphin(&graphrev,k - 1,j - 1,max);
    }

    listgraphmindis(&graph,sum,n);
    listgraphmindis(&graphrev,sumrev,n);
    
    max = 0;

    for(i = 0;i < n;i++){
        if(sum[i] > (-1) && sumrev[i] > (-1)){
            x = (t - sum[i] - sumrev[i]) * a[i];
            if(x> max)
                max = x;
        }
    }
    printf("%lld\n",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:141:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %lld",&n,&m,&t);
     ^
./Main.c:147:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^
./Main.c:149:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %lld",&j,&k,&max);
         ^