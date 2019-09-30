#include <stdio.h>
#include <stdlib.h>

#define PLANCNT 1000
#define PLANLEN (PLANCNT + 1)

char pl[PLANLEN];
int bh;

void read(void)
{
    if (scanf("%s", pl) != 1)
        exit(EXIT_FAILURE);
}

void exec(void)
{
    int dn, dw, ds, de, i;
    
    dn = dw = ds = de = 0;
    for (i = 0; pl[i] != '\0'; ++i) {
        dn += (pl[i] == 'N'), dw += (pl[i] == 'W');
        ds += (pl[i] == 'S'), de += (pl[i] == 'E');
    }
    bh = ((dn != 0 && ds != 0) || (dn == 0 && ds == 0)) &&
         ((dw != 0 && de != 0) || (dw == 0 && de == 0));
}

void print(void)
{
    printf("%s\n", bh ? "Yes" : "No");
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