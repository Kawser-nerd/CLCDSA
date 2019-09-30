#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const char *onkai[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
    const char ken[] = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
    const char idx[] = "102034050607102034050607102034050607";
    char buf[32];
    int i;
    fgets(buf, sizeof(buf), stdin);
    for ( i = 0; i < 20; i++ ){
        if ( strncmp(ken+i, buf, 20) == 0 ){
            printf("%s\n", onkai[idx[i]-'1']);
            break;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf, sizeof(buf), stdin);
     ^