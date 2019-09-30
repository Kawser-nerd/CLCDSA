#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct stack {
    long long n;
    int sign;
};

int
my_add(long long t, char *s, struct stack *stack)
{
    struct stack tmp;
    int n = 0;
    if (s[0] == '\0') {
        if (stack->sign == 1) {
            t += stack->n;
        }
        if (stack->sign == 2) {
            t -= stack->n;
        }
        if (((t / 2) * 2) == t) return 1;
        if (((t / 3) * 3) == t) return 1;
        if (((t / 5) * 5) == t) return 1;
        if (((t / 7) * 7) == t) return 1;
        if (t == 0) return 1;
        return 0;
    }

    stack->n = stack->n * 10 + s[0] - '0';
    // +
    if (s[1] != '\0') {
        if (stack->sign == 1) {
            memcpy(&tmp, stack, sizeof(tmp));
            tmp.n = 0;
            tmp.sign = 1;
            n += my_add(t + stack->n, s + 1, &tmp);
        }
        if (stack->sign == 2) {
            memcpy(&tmp, stack, sizeof(tmp));
            tmp.n = 0;
            tmp.sign = 1;
            n += my_add(t - stack->n, s + 1, &tmp);
        }
        // -
        if (stack->sign == 1) {
            memcpy(&tmp, stack, sizeof(tmp));
            tmp.n = 0;
            tmp.sign = 2;

            n += my_add(t + stack->n, s + 1, &tmp);
        }
        if (stack->sign == 2) {
            memcpy(&tmp, stack, sizeof(tmp));
            tmp.n = 0;
            tmp.sign = 2;

            n += my_add(t - stack->n, s + 1, &tmp);
        }
    }
    // XX
    memcpy(&tmp, stack, sizeof(tmp));
    //tmp.n = tmp.n * 10 + s[0] - '0';
    n += my_add(t, s + 1, &tmp);
    return n;
}

int
main()
{
    int line, l;
    int i, j, k;

    struct stack stack;
    int total;
    char s[41];
    int len;

    scanf("%d", &line);

    for (l = 0; l < line; l++) {
        scanf("%s", s);
        fprintf(stderr, "calc #%d\n", l + 1);
        len = strlen(s);

        stack.n = 0;
        stack.sign = 1;
        total = 0;
        total = my_add(0LL, s, &stack);
        printf("Case #%d: %d\n", l + 1, total, s);
    }









    return 0;

}

