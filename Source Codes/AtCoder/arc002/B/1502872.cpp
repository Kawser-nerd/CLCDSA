#include <iostream>

using namespace std;

bool is_leap(int y) {
    bool leap = false;
    if (y % 4 == 0) {
        leap = true;
        if (y % 100 == 0) {
            leap = !leap;
            if (y % 400 == 0) {
                leap = !leap;
            }
        }
    }
    return leap;
}

void next(int *y, int *m, int *d) {
    (*d)++;
    if (*m == 2) {
        if ((*d == 29 && !is_leap(*y)) || *d == 30) {
            *m = 3;
            *d = 1;
        }
    }
    if (*d == 31) {
        switch (*m) {
            case 4:
            case 6:
            case 9:
            case 11:
                (*m)++;
                *d = 1;
        }
    }
    if (*d == 32) {
        switch (*m) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                (*m)++;
                *d = 1;
        }
    }
    if (*m == 13) {
        (*y)++;
        *m = 1;
    }
}

int main() {

    int Y, M, D;

    scanf("%d/%02d/%02d", &Y, &M, &D);

    while (Y % (M * D)) { next(&Y, &M, &D); }

    printf("%d/%02d/%02d\n", Y, M, D);
}