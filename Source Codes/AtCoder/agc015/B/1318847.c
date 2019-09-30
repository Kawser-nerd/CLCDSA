#include <stdio.h>

#define FLRMAX 100000

char fd[FLRMAX];
int fc;
long long fs;

void read(void)
{
    scanf("%*[^UD]");
    for (fc = 0; fc < FLRMAX; ++fc)
        if (scanf("%1[UD]", &fd[fc]) != 1)
            break;
}

void exec(void)
{
    int f;
    
    for (fs = 0, f = 0; f < fc; ++f)
        fs += (fd[f] == 'U') ? fc - f - 1 + 2 * f : f + 2 * (fc - f - 1);
}

void write(void)
{
    printf("%lld\n", fs);
}

int main(void)
{
    read();
    exec();
    write();
    return 0;
} ./Main.c: In function ‘read’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%*[^UD]");
     ^