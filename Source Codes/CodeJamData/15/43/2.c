#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
int compare(char *t, char *s) {
    return strcmp(t, s);
}

int N;
char buf[10000];

int rest[18][1000];

char words[20000][11];
int wn;
int eng_flag[20][20000];
int fre_flag[20][20000];

int min;

void set_eng(int x, int *list) {
    int i;
    for(i = 0; list[i] >= 0; ++i) {
        eng_flag[x][list[i]] = 1;
    }
}

void set_fre(int x, int *list) {
    int i;
    for(i = 0; list[i] >= 0; ++i) {
        fre_flag[x][list[i]] = 1;
    }
}

int calc_both(int x) {
    int i;
    int res = 0;
    for(i = 0; i < wn; ++i) {
        if(eng_flag[x][i] && fre_flag[x][i]) res++;
    }
    return res;
}

void flag_copy(int x) {
    int i;
    for(i = 0; i < wn; ++i) {
        eng_flag[x+1][i] = eng_flag[x][i];
        fre_flag[x+1][i] = fre_flag[x][i];
    }
}

void solve(int x) {
    int t;
    t = calc_both(x);
    if(t >= min) return;
    if(x == N) {
        if(t < min) min = t;
        return;
    }
    flag_copy(x);
    set_eng(x+1, rest[x]);
    solve(x+1);
    flag_copy(x);
    set_fre(x+1, rest[x]);
    solve(x+1);
    return;
}

void spliting(int *list) {
    int i;
    int left = 0;
    int right;
    int t;
    int len = strlen(buf);
    
    for(i = 0; left < len; ++i) {
        for(right = left; buf[right] != '\0' && buf[right] != ' '; ++right) {
        }
        buf[right] = '\0';
        for(t = 0; t < wn; ++t) {
            if(!strcmp(buf+left, words[t])) {
                break;
            }
        }
        list[i] = t;
        if(t == wn) {
            strcpy(words[wn], buf+left);
            eng_flag[0][wn] = 0;
            fre_flag[0][wn] = 0;
            ++wn;
        }
        left = right + 1;
    }
    list[i] = -1;
}

void solve_and_print(void) {
    int i;

    wn = 0;
    min = 9999999;

    scanf("%d", &N);
    N-=2;
    gets(buf); // to avoid newline
    gets(buf);
    spliting(rest[0]);
    set_eng(0, rest[0]);

    gets(buf);
    spliting(rest[0]);
    set_fre(0, rest[0]);

    for(i = 0; i < N; ++i) {
        gets(buf);
        spliting(rest[i]);
    }
    solve(0);

    printf("%d\n", min);
    /*
    for(i = 0; i < wn; ++i) {
        printf("%s\n", words[i]);
    }
    */
}


int main(void) {
    int dataset_num, case_num;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        printf("Case #%d: ", case_num);

        solve_and_print();
    }

    return 0;
}
