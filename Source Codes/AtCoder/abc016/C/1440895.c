#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dlln {           // doubly linked list node
    int id;
    struct dll *list;
    struct dlln *pred;  // predecessor
    struct dlln *succ;  // successor
    char value[1];
};
struct dll {            // doubly linked list
    int id;
    size_t elem_size;
    int length;
    struct dlln *left;  // left sentinel
    struct dlln *right; // right sentinel
};
int dll_is_empty(struct dll *);

int dlln_next_id = 0;
struct dlln *dlln_alloc(struct dll *list) {
    struct dlln *node;
    
    node = malloc(sizeof(struct dlln) + list->elem_size - 1);
    node->id = dlln_next_id++;
    node->list = list;
    node->pred = node->succ = NULL;
    return node;
}
void dlln_free(struct dlln *node) {
    free(node);
}
void dlln_insert(struct dlln* before, void *value) {
    struct dlln *node;
    
    node = dlln_alloc(before->list);
    node->pred = before->pred;
    node->succ = before;
    before->pred->succ = node;
    before->pred = node;
    memcpy(node->value, value, before->list->elem_size);
    before->list->length++;
}
void dlln_remove(struct dlln *node) {
    node->pred->succ = node->succ;
    node->succ->pred = node->pred;
    node->list->length--;
    dlln_free(node);
}

int dll_next_id = 0;
struct dll *dll_alloc(size_t elem_size) {
    struct dll *list;
    
    list = malloc(sizeof(struct dll));
    list->id = dll_next_id++;
    list->elem_size = elem_size;
    list->length = 0;
    list->left = dlln_alloc(list);
    list->right = dlln_alloc(list);
    list->left->succ = list->right;
    list->right->pred = list->left;
    return list;
}
void dll_free(struct dll *list) {
    while (!dll_is_empty(list)) {
        dlln_remove(list->left->succ);
    }
    
    dlln_free(list->right);
    dlln_free(list->left);
    free(list);
}
int dll_is_empty(struct dll *list) {
    return list->left->succ == list->right;
}
void dll_print_status(struct dll *list) {
    struct dlln *node;
    
    printf("list=%d (len=%d) elems=", list->id, list->length);
    node = list->left->succ;
    
    while (node != list->right) {
        printf("%d", node->id);
        
        if (node->succ == list->right) {
            printf("\n");
        } else {
            printf(", ");
        }
        
        node = node->succ;
    }
}
void dll_map(struct dll *list, void fn(void *)) {
    struct dlln *node;
    
    node = list->left->succ;
    while (node != list->right) {
        fn(&node->value);
        node = node->succ;
    }
}

#define N_MAX 10

void print(void *x) {
    printf("%d, ", *(int *)x);
}

int n, m;
int bfs_dist[N_MAX];        // breadth-first search distance
struct dll *edges[N_MAX];

void bfs(int start_node) {
    int i, node, dst_node;
    struct dll *queue;
    struct dlln *edge;
    
    queue = dll_alloc(sizeof(int));
    
    for (i = 0; i < N_MAX; ++i) {
        bfs_dist[i] = -1;
    }
    
    bfs_dist[start_node] = 0;
    dlln_insert(queue->right, &start_node);
    
    while (!dll_is_empty(queue)) {
        node = *(int *)queue->left->succ->value;
        dlln_remove(queue->left->succ);
        edge = edges[node]->left->succ;
        
        while (edge != edges[node]->right) {
            dst_node = *(int *)edge->value;
            
            if (bfs_dist[dst_node] == -1) {
                bfs_dist[dst_node] = bfs_dist[node] + 1;
                dlln_insert(queue->right, &dst_node);
            }
            
            edge = edge->succ;
        }
    }
    
    dll_free(queue);
}

int main(void) {
    int i, j, a, b, n_friends;
    
    for (i = 0; i < N_MAX; ++i) {
        edges[i] = dll_alloc(sizeof(int));
    }
    
    scanf("%d%d", &n, &m);
    
    for (i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        dlln_insert(edges[a]->right, &b);
        dlln_insert(edges[b]->right, &a);
    }
    
    for (i = 0; i < n; ++i) {
        bfs(i);
        n_friends = 0;
        
        for (j = 0; j < n; ++j) {
            if (bfs_dist[j] == 2) {
                ++n_friends;
            }
        }
        
        printf("%d\n", n_friends);
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:157:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &m);
     ^
./Main.c:160:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &a, &b);
         ^