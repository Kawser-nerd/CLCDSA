#include <stdio.h>
#include <string.h>

char s[10][10];

int check_ok(int k, int N){
    int i,j, kk, tmpr, tmpc;
    char r[10][10];
    memset(r,0,sizeof(r));
    kk = k;
    for (i=N-1;i>=0;i--) for (j=N-1;j>=0;j--){
        if (kk&1) r[i][j]='1';
        else r[i][j]='0';
        kk/=2;
    }
    int row[10], rowc[10];
    int col[10], colc[10];
    for (i=0;i<N;i++){
        row[i]=rowc[i]=0;
        col[i]=colc[i]=0;
        for (j=0;j<N;j++){
            row[i] = row[i]*2 + (r[i][j]-'0');
            rowc[i]+=(r[i][j]-'0');
            col[i] = col[i]*2 + (r[j][i]-'0');
            colc[i]+=(r[j][i]-'0');
        }
        if (rowc[i]==0 || colc[i]==0) return 0;
    }
    // check row and rowc
    for (i=0;i<N;i++){
        tmpr = 0; tmpc=0;
        for (j=0;j<N;j++){
            if (row[j]==row[i]) tmpr++;
            if (col[j]==col[i]) tmpc++;
        }
        if (tmpr!=rowc[i]) return 0;
        if (tmpc!=colc[i]) return 0;
    }
//    for (i=0;i<N;i++) printf("%s\n", r[i]);
//    printf("\n");
    return 1;
}

int count_me(int k){
    int c=0;
    while (k>0){
        c += (k&1);
        k>>=1;
    }
    return c;
}

int main(){
    int i, j, k,cas, T, N, r,c, res, nres;
    scanf("%d", &T);
    for (cas=1;cas<=T;cas++){
        scanf("%d", &N);
        for (i=0;i<N;i++) scanf("%s", s[i]);
        r = 0; c= 0;
        for (i=0;i<N;i++) for (j=0;j<N;j++){
            r*=2;
            if (s[i][j]=='1'){
                r++;
                c++;
            }
        }
        res = N*N-c;
        //printf("r=%d\n", r);
        for (k=(2<<(N*N))-1;k>=0;k--){
            //printf("k=%d\n", k);
            if ((k&r) !=r) continue;
            if (check_ok(k, N)){
                nres = count_me(k) - c;
                if (nres<res) res=nres;
            }
        }
        printf("Case #%d: %d\n", cas, res);
    }
    return 0;
}
