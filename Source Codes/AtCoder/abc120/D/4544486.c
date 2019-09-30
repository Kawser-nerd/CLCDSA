#include <stdio.h>

typedef struct TreeNode_t {
    int parent;
    int size;
} TreeNode;

void TreeUnion(TreeNode node[], int a, int b)
{
    node[b].parent = a;
    node[a].size += node[b].size;
}

int TreeRoot(TreeNode node[], int a)
{
    if (node[a].parent == a) {
        return a;
    }

    int root = TreeRoot(node, node[a].parent);
    node[a].parent = root;
    return root;
}

int TreeSize(TreeNode node[], int a)
{
    return node[TreeRoot(node, a)].size;
}

int main(int argc, char *argv[])
{
    int n, m;
    int a[100000], b[100000];
    TreeNode node[100000];
    int i;
    int ans[100000];
    long long ans_sum;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        // to 0-origin
        a[i]--;
        b[i]--;
    }

    // initialize node-list
    for (i = 0; i < n; i++) {
        node[i].parent = i;
        node[i].size = 1;
    }

    for (i = m - 1; i >= 0; i--) {
        int root_a = TreeRoot(node, a[i]);
        int root_b = TreeRoot(node, b[i]);

        if (root_a == root_b) {
            // ??????????????
            ans[i] = 0;
        } else {
            // ??
            ans[i] = TreeSize(node, root_a) * TreeSize(node, root_b);
            TreeUnion(node, root_a, root_b);
        }
    }

    ans_sum = 0;
    for (i = 0; i < m; i++) {
        ans_sum += ans[i];
        printf("%lld\n", ans_sum);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:42:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a[i], &b[i]);
         ^