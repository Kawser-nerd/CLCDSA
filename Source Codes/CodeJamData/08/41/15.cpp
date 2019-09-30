#include <stdio.h>

#define INF (1000000000)

int N;
int M;

int Goal;

int Table[10000][2]; // [index][0/1]

struct Node_t {
    int andgate; // 0: or, 1: and
    int value;
    int changable;
} Node[10000];

inline int min(int a, int b, int c) { return a<b? a<c? a: c: b<c? b: c; }

int main() {
    scanf("%d", &N);
    for(int n=1; n<=N; ++n) {
        scanf("%d%d", &M, &Goal);
        for(int i=0; i<M/2; ++i)
            scanf("%d%d", &Node[i].andgate, &Node[i].changable);
        for(int i=M/2; i<M; ++i) {
            scanf("%d", &Node[i].value);
            Table[i][Node[i].value] = 0;
            Table[i][1-Node[i].value] = INF;
        }
        for(int i=M/2-1; i>=0; --i) {
            int a = i*2+1;
            int b = i*2+2;
            if( Node[i].andgate ) {
                Table[i][0] = min( Table[a][0]+Table[b][0], Table[a][0]+Table[b][1], Table[a][1]+Table[b][0] );
                if( Node[i].changable )
                    Table[i][1] = min( Table[a][1]+Table[b][1], 1+Table[a][1]+Table[b][0], 1+Table[a][0]+Table[b][1] );
                else
                    Table[i][1] = Table[a][1]+Table[b][1];
            }
            else {
                if( Node[i].changable )
                    Table[i][0] = min( Table[a][0]+Table[b][0], 1+Table[a][0]+Table[b][1], 1+Table[a][1]+Table[b][0] );
                else
                    Table[i][0] = Table[a][0]+Table[b][0];
                Table[i][1] = min( Table[a][1]+Table[b][1], Table[a][1]+Table[b][0], Table[a][0]+Table[b][1] );
            }
            if( Table[i][0]>INF ) Table[i][0] = INF;
            if( Table[i][1]>INF ) Table[i][1] = INF;
        }
        if( Table[0][Goal]==INF )
            printf("Case #%d: IMPOSSIBLE\n", n);
        else
            printf("Case #%d: %d\n", n, Table[0][Goal]);
    }
    return 0;
}
