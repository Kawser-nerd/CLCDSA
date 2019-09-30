#include <stdio.h>

typedef struct dir_t_ {
    struct dir_t_ *child;
    struct dir_t_ *next;
    char name[128];
} dir_t;

void *my_alloc (size_t size)
{
    void *ptr;

    if ((ptr = malloc (size)) == NULL) {
        printf("Failed to allocate\n");
        exit(0);
    }

    return ptr;
}

int first_call = 0;

int create_dir (dir_t *root, char *path)
{
    char *dir_name;
    dir_t *node, *prev;

    if (first_call) {
        dir_name = strtok(path, "/");
        first_call = 0;
    } else {
        dir_name = strtok(NULL, "/");
    }

    if (!dir_name) {
        return 0;
    }

    prev = root->child;
    for (node=root->child; node != NULL; node=node->next) {
        if (!strcmp(dir_name, node->name)) {
            return create_dir(node, path);
        }
        prev = node;
    }

    node = (dir_t *) my_alloc(sizeof(dir_t));
    node->next = NULL;
    strcpy(node->name, dir_name);
    node->child = NULL;
    if (prev)
        prev->next = node;
    else 
        root->child = node;

    return create_dir(node, path)+1;
}


void free_all (dir_t *root)
{
    if (root->next) {
        free_all(root->next);
        root->next = NULL;
    }

    if (root->child) {
        free_all(root->child);
        root->child = NULL;
    }

    free(root);
}

int main()
{
    dir_t *root;
    int T, N, M;
    char *path;
    int mkdir_cnt;
    int i, j;

    root = (dir_t *) my_alloc (sizeof(dir_t));
    path = (char *) my_alloc(100000);

    root->child = NULL;
    strcpy(root->name, "/");
    root->next = NULL;

    scanf("%d", &T);

    for (i=0; i<T; i++) {
        scanf("%d %d", &N, &M);
        for (j=0; j<N; j++) {
            int tmp;

            scanf("%s", path);
            tmp = strlen(path);
            path[tmp] = '/';
            path[tmp+1] = '\0';
            first_call = 1;
            (void) create_dir(root, path);
        }
        mkdir_cnt = 0;
        for (j=0; j<M; j++) {
            int tmp;

            scanf("%s", path);
            tmp = strlen(path);
            path[tmp] = '/';
            path[tmp+1] = '\0';
            first_call = 1;
            tmp = create_dir(root, path);
            mkdir_cnt += tmp;
        }
        printf("Case #%d: %d\n", i+1, mkdir_cnt);
        free_all(root->child);
        root->child = root->next = NULL;
    }

    printf("Done\n");
}
