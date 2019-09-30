#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void get_next_str(char* s){
    int i;
    bool a[30];
    for(i = 0; i < 30; i++){
        a[i] = false;
    }
    
    i = 0;
    char last_c;
    while(s[i]){
        a[s[i] - 'a'] = true;
        last_c = s[i];
        i++;
    }

    int len = strlen(s);

    int j;
    for(j = 0; j < 30; j++){
        if(a[j] == false){
            break;
        }
    }

    s[len] = char(j + int('a'));
    s[len + 1] = '\0';

    return;
}

int main(void){
    char s[30];

    scanf("%s", s);

    if(strlen(s) != 26){
        get_next_str(s);
        printf("%s\n", s);
        return 0;
    }

    int i = 24;
    while(i + 1){
        if(s[i] > s[i + 1]){
            i--;
            continue;
        }
        s[i + 1] = '\0';
        break;
    }
    
    if(i == -1){
        printf("%d\n", -1);
        return 0;
    }

    int len = strlen(s);
    bool b[30];
    for(i = 0; i < 30; i++){
        b[i] = false;
    }

    i = 0;
    while(s[i + 1]){
        b[s[i] - 'a'] = true;
        i++;
    }
    char last_word = s[len - 1];
    int k = 1;

    while(1){
        if(b[last_word - 'a' + k]){
            k++;
            continue; 
        }
        s[len - 1] = char(int(last_word) + k);
        break;
    }

    printf("%s\n", s);

    return 0;

}