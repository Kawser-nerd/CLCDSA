#include <stdio.h>

int check0(int n, char *s) {
    for (int i = 0; i < n; i++) {
        switch (i % 3) {
        case 0:
            if (s[i] != 'b') return -1; break;
        case 1:
            if (s[i] != 'c') return -1; break;
        case 2:
            if (s[i] != 'a') return -1; break;
        }
    }
    return 1;
}

int check1(int n, char *s) {
    for (int i = 0; i < n; i++) {
        switch (i % 3) {
        case 0:
            if (s[i] != 'a') return -1; break;
        case 1:
            if (s[i] != 'b') return -1; break;
        case 2:
            if (s[i] != 'c') return -1; break;
        }
    }
    return 1;
}

int check2(int n, char *s) {
    for (int i = 0; i < n; i++) {
        switch (i % 3) {
        case 0:
            if (s[i] != 'c') return -1; break;
        case 1:
            if (s[i] != 'a') return -1; break;
        case 2:
            if (s[i] != 'b') return -1; break;
        }
    }
    return 1;
}

int main() {
    int n;
    char s[101] = { 0 };
    int num, flag = 1;

    scanf("%d", &n);
    scanf("%s", s);

    if (n % 2 == 0) {
        flag = -1;
    } else {
        num = (n - 1) / 2;
        switch (num % 3) {
        case 0: flag = check0(n, s); break;
        case 1: flag = check1(n, s); break;
        case 2: flag = check2(n, s); break;
        }
    }

    if (flag == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", num);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:51:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^