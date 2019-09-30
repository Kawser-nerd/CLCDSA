int printf();
int scanf();
void *malloc ();

int main ()
{
    int n;
    int x;
    int *ans;
    int i;
    int j;
    scanf("%d %d", &n, &x);
    if (x == 1 || x == n * 2 - 1) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    if (n == 2) {
        printf("1\n2\n3\n");
        return 0;
    }
    ans = malloc(n * 2 * 4);
    if (x == 2) {
        *(ans + n - 3) = x + 1;
        *(ans + n - 2) = x - 1;
        *(ans + n - 1) = x;
        *(ans + n) = x + 2;
        i = 0;
        j = 1;
        while (i < n * 2 - 1) {
            if (j == x - 1)
                j = x + 3;
            if (i == n - 3)
                i = n + 1;

            *(ans + i) = j;
            i = i + 1;
            j = j + 1;
        }
    }
    else {
        *(ans + n - 3) = x - 1;
        *(ans + n - 2) = x + 1;
        *(ans + n - 1) = x;
        *(ans + n) = x - 2;
        i = 0;
        j = 1;
        while (i < n * 2 - 1) {
            if (j == x - 2)
                j = x + 2;
            if (i == n - 3)
                i = n + 1;

            *(ans + i) = j;
            i = i + 1;
            j = j + 1;
        }
    }
    i = 0;
    while (i < n * 2 - 1) {
        printf("%d\n", *(ans + i));
        i = i + 1;
    }
    return 0;
} ./Main.c:1:5: warning: conflicting types for built-in function ‘printf’
 int printf();
     ^
./Main.c:2:5: warning: conflicting types for built-in function ‘scanf’
 int scanf();
     ^