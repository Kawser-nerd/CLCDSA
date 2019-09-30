#include <stdio.h>

/******************************************************************************
Compiler + OS: gcc 3.4.4 + (Cygwin + Windows XP SP3)
Editor: Notepad++ v5.3.1

to compile: gcc a.c
to run: ./a.exe file_name.in > file_name.out
******************************************************************************/

/*================================================================== SYMB ===*/
#define T_MAX    100
#define BUF_MAX 1024

#define ERR_ARGS    -1
#define ERR_NOFILE  -2
#define ERR_BADPAR  -3


#define INI_PARAMS  1


/*================================================================== DECL ===*/


/*================================================================== MAIN ===*/
int main(int argc, char* argv[])
{
    FILE* f_in;
    
    int   T;
    int   i, j, k, l;
    long long int x, p;
    
    char buf[BUF_MAX+1];
    char digits[BUF_MAX + 1];
    
    int  values[256];


    if(argc != 2) {
        return ERR_ARGS;
    }
    
    f_in = fopen(argv[1], "rb");
    if(f_in == NULL) {
        return ERR_NOFILE;
    }

    /* Read parameters */
    fgets(buf, BUF_MAX, f_in);
    if(INI_PARAMS != sscanf(buf, "%d", &T)  ||  1>T  ||  T>T_MAX) {
        return ERR_BADPAR;
    }


    
    
    /* Scan for strings */
    for(i=1; i<=T; ++i) {
        fgets(buf, BUF_MAX, f_in);

        
        /* Reset values */
        for(j=0; j<255; ++j) {
            values[j] = -1;
        }
        
        /* First digit must be 1 */
        values[buf[0]] = 1;
        
        /* Second appearing digit digit must be 0 */
        for(j=1; buf[j]==buf[0]; ++j);
        if(!(buf[j]>='a' && buf[j]<='z') && !(buf[j]>='0' && buf[j]<='9')) {
            buf[j] = '\0';
            k = 2;
            goto set_val;
        }
        values[buf[j]] = 0;

        
        /* Assign growing values to digits */
        k = 2;
        for(
            ++j;
            (buf[j]>='a' && buf[j]<='z') || (buf[j]>='0' && buf[j]<='9');
            ++j
        ) {
            if(values[buf[j]]==-1) {
                values[buf[j]]=k;
                ++k;
            }
        }
        buf[j] = '\0';
        
        
  
        
set_val:
        /* Compute value */
        for(--j, p=1, x=0; j>=0; --j, p*=k) {
            x += values[buf[j]]*p;
        }
        
        /* Print value */
        j = BUF_MAX;
        digits[j] = '\0';
        for(--j; x>0; --j) {
            digits[j] = x%10 + '0';
            x         /= 10;
        }
        ++j;
        
        fprintf(stdout, "Case #%d: %s\n", i, digits + j);
    }
    
    return 0;
}


/*================================================================== IMPL ===*/
