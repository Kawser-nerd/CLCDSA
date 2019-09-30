#include <stdio.h>
#include <stdlib.h>

char s1[200][50],s2[200][50],ts1[200][50];

int comp1(const void *a,const void *b){
    char *aa,*bb;
    aa=(char *)a;
    bb=(char *)b;
    for (;*aa&&*aa==*bb;aa++,bb++);
    if (*aa==0&&*bb==0)
        return 0;
    else if (*aa>*bb)
        return 1;
    else
        return -1;
}

int main(){
    long t,tt,n,l,i,j,min,j1,j2,tmp,an;
    
    freopen("A-large.in.txt", "r",stdin);
    freopen("A-large.out.txt", "w",stdout);
    
    scanf("%ld",&tt);
    for (t=1;t<=tt;t++){
        scanf("%ld%ld",&n,&l);
        for (i=0;i<n;i++){
            scanf("%s",s1[i]);
        }
        for (i=0;i<n;i++){
            scanf("%s",s2[i]);
        }
        min=100000;
        qsort(s2, n, sizeof(char)*50, comp1);
        for (i=0;i<n;i++){
            for (j1=0;j1<n;j1++){
                for (j2=0;j2<50;j2++){
                    ts1[j1][j2]=s1[j1][j2];
                }
            }
            for (j1=0,an=0;j1<l;j1++){
                tmp=s1[i][j1]^s2[0][j1];
                an+=tmp;
                for (j2=0;j2<n;j2++){
                    ts1[j2][j1]^=tmp;
                }
            }
            qsort(ts1, n, sizeof(char)*50, comp1);
            for (j=0;j<n;j++){
                if (comp1(ts1[j], s2[j]))
                    break;
            }
            if (j==n){
                if (an<min)
                    min=an;
            }
        }
        printf("Case #%ld: ",t);
        if (min<100000)
            printf("%ld\n",min);
        else
            printf("NOT POSSIBLE\n");
    }
    return 0;
}

