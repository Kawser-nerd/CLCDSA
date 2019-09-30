#include <stdio.h>
#include <string.h>

int main(){
    int p1,p2, p3, l, cas, T;
    int i;
    char c, s[1024], s1[1024], s2[1024],s3[1024];
    scanf("%d", &T);
    for (cas=1;cas<=T;cas++){
        scanf("%s", s);
        p1=0; p2=0;
        l = strlen(s);
        c = s1[p1++] = s[0];
        for (i=1;i<l;i++){
            if (s[i]>=c) c = s2[p2++] = s[i];
            else s1[p1++] = s[i];
        }
        p3 = 0;
        for (i=p2-1;i>=0;i--) s3[p3++] = s2[i];
        s3[p3]='\0';
        s1[p1]='\0';
        printf("Case #%d: %s%s\n", cas,s3,s1);
    }
    return 0;
}
