#include <stdio.h>
#include <stdlib.h>

int pa, pb, pc;
long long df;

void read(void)
{
    if (scanf("%d %d %d", &pa, &pb, &pc) != 3)
        exit(EXIT_FAILURE);
}

void exec(void)
{
    int sa, sb, sc;
    
    if (pa % 2 == 0 || pb % 2 == 0 || pc % 2 == 0) {
        df = 0;
        return;
    }
    if (pa < pb) {
        if (pb < pc)
            sa = pa, sb = pb, sc = pc;
        else if (pc < pa)
            sa = pc, sb = pa, sc = pb;
        else
            sa = pa, sb = pc, sc = pb;
    } else {
        if (pa < pc)
            sa = pb, sb = pa, sc = pc;
        else if (pc < pb)
            sa = pc, sb = pb, sc = pa;
        else
            sa = pb, sb = pc, sc = pa;
    }
    df = 1LL * sa * sb;
}

void print(void)
{
    printf("%lld\n", df);
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