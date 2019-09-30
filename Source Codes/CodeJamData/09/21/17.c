#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree_st tree;

struct tree_st {
    double w;
    char *feature;
    tree *tree1;
    tree *tree2;
};

double traverse(char **features, int fcount, tree *root) {
    double p = root->w;

    if (root->feature == NULL) {
        return p;
    }
    int i;
    int found = 0;
    for (i = 0; i < fcount; i++) {
        char *feature = features[i];
        if (!strcmp(feature, root->feature)) {
            found = 1;
        }
    }
    tree *tree;
    if (found) {
        tree = root->tree1;
    }
    else {
        tree = root->tree2;
    }
    return p * traverse(features, fcount, tree);
}

tree *createTree(char *str, int len, int *l) {
    tree *root;
    int i = *l;
    while((str[i] == '\n' || str[i] == ' ') && i < len) {
        i ++;
    }
    if (str[i] == '(') {

        root = (tree*)malloc(sizeof(tree));
        i ++;

        while((str[i] == '\n' || str[i] == ' ') && i < len) {
            i ++;
        }

        char *c = str + i;
        while (str[i] != '\n' && str[i] != ' ' && str[i] != ')' && i < len) {
            i ++;
        }
        char temp = str[i];
        str[i] = '\0';
        root->w = atof(c);
        str[i] = temp;

        if (temp == '\n' || temp == ' ') {
            while((str[i] == '\n' || str[i] == ' ') && i < len) {
                i ++;
            }
            temp = str[i];
        }
        
        if (temp == ')') {
            // no sub trees
            root->feature = NULL;
            root->tree1 = NULL;
            root->tree2 = NULL;
        }
        else {
            // should be an english character
            char *c = str + i;
            while (str[i] != '\n' && str[i] != ' ' && str[i] != '(' && i < len) {
                i ++;
            }
            char temp = str[i];
            str[i] = '\0';
            root->feature = strdup(c);
            str[i] = temp;

            // for the first tree
            *l = i;
            tree *tree1 = createTree(str, len, l);
            tree *tree2 = createTree(str, len, l);

            i = *l;

            root->tree1 = tree1;
            root->tree2 = tree2;
        }

        // now loop until the finish until the ')'
        while((str[i] != ')') && i < len) {
            i ++;
        }
        i ++;
    }
    *l = i;
    return root;
}
void print_tree(tree *tree, int tab) {
    if (tree == NULL) {
        return;
    }
    int i;
    for (i = 0; i < tab * 4; i ++) {
        printf(" ");
    }
    printf("%f", tree->w);
    if (tree->feature) {
        printf(" %s", tree->feature);
    }

    printf("\n");
    
    print_tree(tree->tree1, tab + 1);
    print_tree(tree->tree2, tab + 1);
}

int main() {
    int N;
    scanf("%d", &N);
    scanf("\n");

    int i;
    for (i = 0; i < N; i ++) {

        int L;
        scanf("%d", &L);
        scanf("\n");

        char str[100000];
        memset(str, 0, 100000);
        int j;
        str[0] = '\0';
        for(j = 0; j < L; j ++) {
            char line[1000];

            scanf("%[^\n]", line);
            scanf("\n");


            int size = strlen(str);
            memcpy(str + size, line, strlen(line));
        }
        // creating the tree..
        int k = 0;
        int size = strlen(str);

        tree *root = createTree(str, size, &k);
        
        //print_tree(root, 0);
        int A; 
        scanf("%d", &A);
        scanf("\n");

        printf("Case #%d:\n", i + 1);
        for(j = 0; j < A; j ++) {
            char line[1000];

            char *features[100];

            scanf("%[^\n]", line);
            scanf("\n");

            int len = strlen(line);
            
            int k = 0;
            char *c = line;

            while(!(line[k] == '\n' || line[k] == ' ') && k < len) {
                k ++;
            }
            line[k] = '\0';
            char *animal = c;
            k ++;

            c = line + k;
            while(!(line[k] == '\n' || line[k] == ' ') && k < len) {
                k ++;
            }
            line[k] = '\0';
            k ++;

            int count = atoi(c);
            
            int l;
            for(l = 0; l < count; l ++) {
                char *c = line + k;
                while(!(line[k] == '\0' || line[k] == '\n' || line[k] == ' ') && k < len) {
                    k ++;
                }
                line[k] = '\0';
                k ++;

                features[l] = c; 
            }
            
            // now traverse the stuff

            double p = traverse(features, count, root);
            printf("%0.6lf\n", p);
        }
    }
}
