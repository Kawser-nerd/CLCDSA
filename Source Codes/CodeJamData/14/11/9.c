#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int L, N;
char inputs[7000];
char *l;
char lr[41];

struct tree {
    struct tree *left;
    struct tree *right;
} *outlets, *devices;

void add(struct tree *t) {
    char c = *(l++);
    if(c != '0' && c != '1') {
    }
    else {
        if(c == '0') {
            if(t->left) {
                add(t->left);
            }
            else {
                t->left = (struct tree*)malloc(sizeof(struct tree));
                t->left->left = t->left->right = NULL;
                add(t->left);
            }
        }
        else {
            if(t->right) {
                add(t->right);
            }
            else {
                t->right = (struct tree*)malloc(sizeof(struct tree));
                t->right->left = t->right->right = NULL;
                add(t->right);
            }
        }
    }
}

void init(struct tree *t) {
    if(t->left) init(t->left);
    if(t->right) init(t->right);
    free(t);
}

int search(struct tree *l, struct tree *r, int i) {
    int t;
    //if(i >= L) return 0;
    if(l == NULL) {
        if(r == NULL) {
            return 0;
        }
        else {
            return 10000;
        }
    }
    if(r == NULL) {
        return 10000;
    }

    if(lr[i++] == 0) {
        if((t = search(l->left, r->left, i)) > 1000) return 10000;
        return t + search(l->right, r->right, i);
    }
    else {
        if((t = search(l->left, r->right, i)) > 1000) return 10000;
        return t + search(l->right, r->left, i);
    }
}

int search_result(int i) {
    int t1, t2;
    if(i == L) return search(outlets, devices, 0);
    lr[i] = 0;
    t1 = search_result(i+1);
    lr[i] = 1;
    t2 = search_result(i+1) + 1;
    return (t1 < t2) ? t1 : t2;
}


int main(void) {
    int num, try_num;
    int i, j, k;

    scanf("%d", &num);
    for(try_num = 1; try_num <= num; ++try_num) {
        outlets = (struct tree *)malloc(sizeof(struct tree));
        devices = (struct tree *)malloc(sizeof(struct tree));
        outlets->left = outlets->right = devices->left = devices->right = NULL;

        scanf("%d %d", &N, &L);
        gets(inputs); // to skip first line
        gets(inputs);
        l = inputs;
        for(i = 0; i < N; ++i) {
            add(outlets);
            //++l;
        }

        gets(inputs);
        l = inputs;
        for(i = 0; i < N; ++i) {
            add(devices);
            //++l;
        }


        printf("Case #%d: ", try_num);
        i = search_result(0);
        if(i > 1000) {
            printf("NOT POSSIBLE\n");
        }
        else {
            printf("%d\n", i);
        }

        init(outlets);
        init(devices);
    }

    return 0;
}
