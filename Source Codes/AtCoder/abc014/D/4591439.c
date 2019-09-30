#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Log 18
#define swap(a, b) (a+=b, b=a-b, a-=b)
// list
typedef struct list_t {
    int size;   // ???????????
    int node;   // ???????????
    struct list_t *previous;    // 1?????????
    struct list_t *latest;
} list_t;
// ???????
typedef struct tree_t {
    int parent[Log];  // ????, ? = 0
    int value;  // ???????
    int depth;  // ????????
} tree_t;

// ???????
void InitNode (int N, list_t node[]) {
    for (size_t i = 0; i < N; i++) {
        node[i].size = 0;
        node[i].previous = NULL;
        node[i].latest = &node[i];
    }
}
// ???????????????
// ????????? ????
void conectNode (int i, int newnode, list_t node[]) {
    list_t *nnew;
    nnew = (list_t*)malloc(sizeof(list_t));  // ????????
    nnew->size = (node[i].latest) -> size + 1 ;
    nnew->node = newnode;
    nnew->previous = node[i].latest;
    node[i].latest = nnew;
}
// ????????????????
void  strructEdge (int node1, int node2, list_t node[]) {
    // vector???????????
    conectNode(node1, node2, node);
    conectNode(node2, node1, node);
}

// ?????????? ?????? logn???????
void DFS (int v, int p ,int d, list_t node[], tree_t tree[]) {
    tree[v].value = v;
    //???v?? = p 2^i??????????
    tree[v].parent[0] = p;  // ?????
    //????????v????? = d
    tree[v].depth = d;
    list_t *nodev = node[v].latest; // ???????????????
    int size = nodev->size;
    for (size_t i = 0; i < size; i++) {
        while (nodev->previous != '\0' ) {
            if (nodev->node != p) {
                int newv = nodev->node;
                DFS(newv, v, d+1, node, tree);
            }
            nodev = nodev->previous;
        }
    }
}
// ???????????O(log n) ver
void MakeTree (int N, int log, int v, int p ,int d, list_t node[], tree_t tree[]) {
    DFS(0, -1, 0, node, tree);  // root = 0
    for (size_t i = 0; i < log; i++) {
        for (size_t v = 0; v < N; v++) {
            // ?????
            if (tree[v].parent[i] < 0) {
                //???v?2^i??????????????????????
                tree[v].parent[i+1] = -1;
            } else {
                // ?????
                tree[v].parent[i+1] = tree[tree[v].parent[i]].parent[i];
            }
        }
    }
}

//u?v?LCA????
int LCA (int log, int u, int v, tree_t tree[]) {
    //printf("u:%d v:%d \n", u, v);
    if (tree[u].depth > tree[v].depth) { swap(u, v); }
    //??????depth[v] >= depth[u]?????
    //printf("u:%d v:%d \n", u, v);

    //u?v?????????????????
    for(int i = 0;i < log; i++){
        if( ((tree[v].depth - tree[u].depth) >> i & 1) == 1){
            v = tree[v].parent[i];
        }
    }
    // u????????
    if (u == v) {
        return u;
    }
    //u?v???????????
    for(int i = log - 1;i >= 0;i--){
        if(tree[u].parent[i] != tree[v].parent[i]){
            u = tree[u].parent[i];
            v = tree[v].parent[i];
        }
    }
    int lca = tree[u].parent[0];    // ??????
    return lca;
}

// Main
int main(int argc, char const *argv[]) {
    int N;
    int log = 0;
    scanf("%d", &N);
    // ???
    while((1 << log) < N){
        log++;
    }
    // ?????????????
    list_t *node = (list_t*)malloc(sizeof(list_t)*N);
    InitNode(N, node);
    for (size_t i = 0; i < N-1; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        node1--; node2--;
        strructEdge(node1, node2, node);
    }
    // ????
    tree_t *tree = (tree_t*)malloc(sizeof(tree_t)*N);
    MakeTree(N, log, 0, -1, 0, node, tree);
    int Q;
    scanf("%d", &Q);
    for (size_t i = 0; i < Q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a --; b --;
        int lca = LCA(log, a, b, tree);  // LCA
        int ans = tree[a].depth + tree[b].depth - 2*tree[lca].depth +1;
        printf("%d\n", ans);
    }
    // ??????
    free(node);
    free(tree);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:113:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:123:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &node1, &node2);
         ^
./Main.c:131:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &Q);
     ^
./Main.c:134:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a, &b);
         ^