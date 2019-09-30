#include <stdio.h>
#include <limits.h>
#include <string.h>

int vowel[256];

int main()
{
    int T, Tcnt=0;
    vowel['a'] = vowel['e'] = vowel['i'] = 
        vowel['o'] = vowel['u'] = 1;
    for(scanf("%d\n", &T); T; T--) {
        static char name[1100000];
        int N;
        static int begin[1100000];
        static int left[1100000];
        static int right[1100000];
        int i;
        long long ans=0;
        int len;
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        memset(begin, 0, sizeof(begin));
        scanf("%s%d\n", name, &N);
        for(i=0; name[i]; i++) {
            if(!vowel[(int)name[i]]) {
                left[i] = i?left[i-1]+1:1;
            } else {
                left[i] = 0;
            }
            if(left[i]>=N) {
                begin[i-N+1]=1;
            }
        }
        for(i=len=strlen(name)-1, right[i+1]=INT_MAX; i>=0; i--) {
            if(begin[i]) {
                right[i]=i;
            } else {
                right[i]=right[i+1];
            }
        }
        len++;  /* real length gets here. */
        ans=0;
        for(i=0; name[i]; i++) {
            if(right[i]<INT_MAX) {
                ans += len-(right[i]+N)+1;
            }
        }
        printf("Case #%d: %lld\n", ++Tcnt, ans);
    }
    return 0;
}
