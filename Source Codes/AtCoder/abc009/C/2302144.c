#include <stdio.h>
#include <string.h>

struct flag {
    char string[124];
    int used[124];
};

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void minsort(char *str, int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (str[i] > str[j]) {
                swap(&str[i], &str[j]);
            }
        }
    }
}

int wdiff(char *str1, char *str2, int len)
{
    int count = 0;
    int finded[124] = {0};
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (finded[j]) {
                continue;
            }
            if (str1[i] == str2[j]) {
                finded[j] = 1;
                count++;
                break;
            }
        }
    }
    return len - count;
}

int diff(char *str1, char *str2, int len)
{
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (str1[i] != str2[i]) {
            count++;
        }
    }
    return count;
}


int main(int argc, char **argv)
{
    int n, k;
    char s[124];
    scanf("%d %d %s", &n, &k, s);

    struct flag asc;
    strcpy(asc.string, s);
    minsort(asc.string, n);
    for (int i = 0; i < 124; ++i) {
        asc.used[i] = 0;
    }

    char result[124] = "";
    for (int index = 0; index < n; ++index) {
        // index ??????
        for (int tmp_i = 0; tmp_i < n; ++tmp_i) {
            if (asc.used[tmp_i]) {
                continue;
            }
            asc.used[tmp_i] = 1;
            sprintf(result, "%s%c", result, asc.string[tmp_i]);

            // ??????????????
            char tmp[124] = "";
            for (int i = 0; i < n; ++i) {
                if (asc.used[i]) {
                    continue;
                }
                sprintf(tmp, "%s%c", tmp, asc.string[i]);
            }
            int wd_tail = wdiff(&s[index+1], tmp, strlen(tmp));
            int wd_head = diff(s, result, index+1);

            // index ?????
            if (wd_head + wd_tail > k) {
                result[index] = '\0';
                asc.used[tmp_i] = 0;
            } else {
                break;
            }
        }
    }
    printf("%s\n", result);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:62:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %s", &n, &k, s);
     ^