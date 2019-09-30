#include <stdio.h>
#include <stdlib.h>

int ia, ib, ps;

void read(void)
{
    if (scanf("%d %d", &ia, &ib) != 2)
        exit(EXIT_FAILURE);
}

void exec(void)
{
    ps = (ia > 0) ? 1 : ((ib < 0) ? 2 * ((ib - ia) % 2) - 1 : 0);
}

void print(void)
{
    printf("%s\n", ps < 0 ? "Negative" : (ps > 0 ? "Positive" : "Zero"));
}

void repl(void)
{
    read();
    exec();
    print();
}

int main(void)
{
    repl();
    return 0;
}