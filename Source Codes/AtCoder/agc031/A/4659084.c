#include <stdio.h>
#include <math.h>

long count_char(const unsigned char target, const char* s)
{
    long count = 0;
    
    while(*s != 0){
        if(target == *s){
            count++;
        }
        s++;
    }
    return count;
}

int main()
{
    int n;
    char s[100001] = {0};

    if(scanf("%d", &n) < 1){
        return 0;
    }
    if(scanf("%s",s) < 1) {
        return 0;
    }

    long char_counts[26] = {0};
    for(unsigned char i = 0; i < sizeof(char_counts)/sizeof(char_counts[0]) ; i++){
        char_counts[i] = count_char(0x61 + i, s);
    }

    long patterns = 1;
    for(int i = 0; i < sizeof(char_counts)/sizeof(char_counts[0]) ; i++){
        patterns *= char_counts[i] + 1;
        patterns %= 1000000007L;
    }

    patterns--;

    printf("%ld\n", patterns);

    return 0;
}