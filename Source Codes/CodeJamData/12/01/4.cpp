#include <iostream>
using namespace std;
char map1[1000] = "y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char map2[1000] = "a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char real[26];
char input[1000];
int main() {
    for (int i=0; map1[i]; i++) {
        if (map1[i]!=' ') {
            real[map1[i]-'a'] = map2[i];
        }
    }
    real[25]='q';
    gets(input);
    int T = atoi(input);
    for (int t=1; t<=T; t++) {
        gets(input);
        printf("Case #%d: ",t);
        for (int i=0; input[i]; i++) if (input[i]==' ') printf(" "); else printf("%c",real[input[i]-'a']);
        printf("\n");
    }
}
