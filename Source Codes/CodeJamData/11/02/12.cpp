#include <iostream>
using namespace std;
int combine[26][26];
bool oppose[26][26];
char tmp[10];
char input[101];
char output[10000];
int outct;
int main() {
    int tt = 0;
    int T; scanf("%d",&T); while (T--) {tt++;
        memset(combine,-1,26*26*sizeof(int));
        memset(oppose,0,26*26*sizeof(bool));
        int C; scanf("%d",&C);
        for (int i=0; i<C; i++) {
            scanf("%s",tmp);
            combine[tmp[0]-'A'][tmp[1]-'A'] = tmp[2]-'A';
            combine[tmp[1]-'A'][tmp[0]-'A'] = tmp[2]-'A';
        }
        int D; scanf("%d",&D);
        for (int i=0; i<D; i++) {
            scanf("%s",tmp);
            oppose[tmp[0]-'A'][tmp[1]-'A'] = true;
            oppose[tmp[1]-'A'][tmp[0]-'A'] = true;            
        }
        int N; scanf("%d",&N); scanf("%s",input);
        outct=0;
        for (int i=0; i<N; i++) {
            if (outct==0) {
                output[outct++]=input[i];
                continue;
            }
            // does this combine with previous letter
            int com = combine[input[i]-'A'][output[outct-1]-'A'];
            if (com!=-1) {
                output[outct-1]=(char)(com+'A');
            } else {
                // does this oppose anything
                bool op = false;
                for (int j=0; j<outct; j++) {
                    if (oppose[input[i]-'A'][output[j]-'A']) {
                        op = true;
                    }
                }
                if (op) outct=0;
                else output[outct++]=input[i];
            }
        }
        printf("Case #%d: [",tt);
        for (int i=0; i<outct; i++) {
            if (i>0) printf(", ");
            printf("%c",output[i]);
        }
        printf("]\n");
    }
}
