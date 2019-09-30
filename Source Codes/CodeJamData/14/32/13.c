#include <stdio.h>
#include <string.h>

char list[110][110];
int used[110];
char buf[11000];

int connect_before(const char *a, const char *b)
{
    //put b after a
    int i;
    char last=0;
    static int used[30];
    memset(used, 0, sizeof(used));
    for(i=0; a[i]; i++) {
        if(a[i]!=last && used[a[i]-'a']) return 0;
        last=a[i];
        used[last-'a']=1;
    }
    for(i=0; b[i]; i++) {
        if(b[i]!=last && used[b[i]-'a']) return 0;
        last=b[i];
        used[last-'a']=1;
    }
    return 1;
}

int ans;

void dfs(int cur, int N)
{
    int i;
    if(cur>=N) {
        ans++;
        return;
    }
    for(i=0; i<N; i++) {
        int j;
        if(used[i]) continue;
        if(connect_before(buf, list[i])) {
            j=1;
            strcat(buf, list[i]);
        } else {
            continue;
        }
        used[i]=1;
        dfs(cur+1, N);
        used[i]=0;
        if(j==1) {
            buf[strlen(buf)-strlen(list[i])]=0;
        } else {
            memmove(buf, buf+strlen(list[i]), strlen(buf+strlen(list[i]))+1);
        }
    }
}

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        int i;
        int N;
        scanf("%d\n", &N);
        for(i=0; i<N; i++) {
            scanf("%s", list[i]);
        }
        memset(used, 0, sizeof(used));
        memset(buf, 0, sizeof(buf));
        ans=0;
        dfs(0, N);
        printf("Case #%d: %d\n", ++Tcnt, ans);
        fprintf(stderr, "%d\n", Tcnt);
    }
    return 0;
}

