#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int calc(const char *buf, char al);

int main(int argc, char *argv[])
{
    char buf[512];
    int al[32] = {0};
    int i, j, min = 100;

    fgets(buf, sizeof(buf), stdin);
    for ( i = 0; buf[i] != '\0'; i++ ){
        if ( buf[i] == '\r' || buf[i] == '\n' ){
            buf[i] = '\0';
            break;
        }
        for ( j = 0; j < 26; j++ ){
            if ( buf[i] == (j+'a') ){
                al[j]++;
            }
        }
    }

    for ( i = 0; i < 26; i++ ){
        if ( al[i] == 0 ){
            continue;
        }
        j = calc(buf, i+'a');
        if ( min > j ){
            min = j;
        }
    }

    printf("%d\n", min);
    return 0;
}
static int calc(const char *buf, char al)
{
    char from[512], to[512];
    int i, len = strlen(buf), c = 0;

    strcpy(from, buf);
    do{
        for ( i = 0; i < len; i++ ){
            if ( from[i] != al ){
                break;
            }
        }
        if ( i == len ){
            return c;
        }
        c++;
        for (i = 0; i < len-1; i++ ){
            if (from[i]==al){
                to[i] = al;
            } else {
                to[i] = from[i+1];
            }
        }
        strcpy(from, to);
        len -= 1;
        from[len] = '\0';
    } while(len>0);
    return 100;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf, sizeof(buf), stdin);
     ^