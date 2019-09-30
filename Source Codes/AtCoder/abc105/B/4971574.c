# include <stdio.h>

int dfs(int n){
    int m_1, m_2;

    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;

    m_1 = dfs(n-4);
    m_2 = dfs(n-7);

    if (m_1 == 1 || m_2 == 1)
        return 1;
    else
        return 0;
}

int main(){
    int N;

    scanf("%d", &N);

    if (dfs(N) == 1)
        printf("Yes");
    else
        printf("No");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^