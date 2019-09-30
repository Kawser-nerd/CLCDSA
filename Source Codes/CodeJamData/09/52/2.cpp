#include <stdio.h>
#include <string.h>
#define maxh 10009

char buf[10000];
int term[5][4], tp[5], tpp;
int data[100][26];
int n, k;
int ans[11], term_ans[11];

struct ansarray
{
    int data[11];
} a0, a1, a2, a3, a01, a02, a03, a12, a13, a23, a012, a013, a023, a123, a0123;

int np [48];

void calc_level1 (int a, ansarray& ans)
{
/*
    ans.data[0] = 0;
    ans.data[1] = 0;
    for (int i = 0; i < n; i ++)
        ans.data[1] = (ans.data[1] + data[i][a]) % maxh;
    
    for (int i = 2; i <= k; i ++)
        ans.data[i] = ans.data[i - 1] * n % maxh;

    for (int i = 2; i <= k; i ++)
        ans.data[i] = ans.data[i] * i % maxh;
*/
    ans.data[0] = 0;
    for (int i = 1; i <= k; i ++)
    {
        ans.data[i] = 0;
        for (int j = 0; j < n; j ++)
        {
            ans.data[i] = (ans.data[i] + data[j][a] * np[i - 1]) % maxh; 
            ans.data[i] = (ans.data[i] + ans.data[i-1]) % maxh; 
        }
    }
}

void calc_level2 (int a, int b, const ansarray& a0, const ansarray& a1, ansarray& ans)
{
    ans.data[0] = 0;
    for (int i = 1; i <= k; i ++)
    {
        ans.data[i] = 0;
        for (int j = 0; j < n; j ++)
        {
            ans.data[i] = (ans.data[i] + data[j][a] * data[j][b] % maxh * np[(i - 1) ] % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][a] * a1.data[i-1] % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + a0.data[i-1] * data[j][b] % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + ans.data[i-1]) % maxh; 
        }
    }
}

void calc_level3 (int a, int b, int c, const ansarray& a0, const ansarray& a1, const ansarray& a2
    , const ansarray& a01, const ansarray& a02, const ansarray& a12
    , ansarray& ans)
{
    ans.data[0] = 0;
    for (int i = 1; i <= k; i ++)
    {
        ans.data[i] = 0;
        for (int j = 0; j < n; j ++)
        {
            ans.data[i] = (ans.data[i] + data[j][a] * data[j][b] % maxh * data[j][c] % maxh * np[(i - 1) ] % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][a] * data[j][b] % maxh * a2.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][a] * a1.data[i-1] % maxh * data[j][c] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + a0.data[i-1] * data[j][b] % maxh * data[j][c] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][a] * a12.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][b] * a02.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][c] * a01.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + ans.data[i - 1]) % maxh; 
        }
    }
}

void calc_level4 (int a, int b, int c, int d
    , ansarray& ans)
{
    ans.data[0] = 0;
    for (int i = 1; i <= k; i ++)
    {
        ans.data[i] = 0;
        for (int j = 0; j < n; j ++)
        {
            ans.data[i] = (ans.data[i] + data[j][a] * data[j][b] % maxh * data[j][c] % maxh * data[j][d] % maxh * np[(i - 1) ] % maxh) % maxh; 

            ans.data[i] = (ans.data[i] + data[j][a] * data[j][b] % maxh * data[j][c] % maxh * a3.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][a] * data[j][b] % maxh * a2.data[i-1] % maxh * data[j][d] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][a] * a1.data[i-1] % maxh * data[j][c] % maxh * data[j][d] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + a0.data[i-1] * data[j][b] % maxh * data[j][c] % maxh * data[j][d] % maxh % maxh) % maxh; 

            ans.data[i] = (ans.data[i] + data[j][a] * data[j][b] % maxh * a23.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][a] * data[j][c] % maxh * a13.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][a] * data[j][d] % maxh * a12.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][b] * data[j][c] % maxh * a03.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][b] * data[j][d] % maxh * a02.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][c] * data[j][d] % maxh * a01.data[i-1] % maxh % maxh) % maxh; 

            ans.data[i] = (ans.data[i] + data[j][a] * a123.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][b] * a023.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][c] * a013.data[i-1] % maxh % maxh) % maxh; 
            ans.data[i] = (ans.data[i] + data[j][d] * a012.data[i-1] % maxh % maxh) % maxh; 
            
            ans.data[i] = (ans.data[i] + ans.data[i - 1]) % maxh;
        }
    }
}

void calc_term (int ind)
{
    if (tp[ind] == 1)
    {
        calc_level1 (term[ind][0], a0);
        for (int i = 0; i <= k; i ++)
            term_ans[i] = a0.data[i];
    }
    if (tp[ind] == 2)
    {
        calc_level1 (term[ind][0], a0);
        calc_level1 (term[ind][1], a1);
        calc_level2 (term[ind][0], term[ind][1], a0, a1, a01);
        for (int i = 0; i <= k; i ++)
            term_ans[i] = a01.data[i];
    }
    if (tp[ind] == 3)
    {
        calc_level1 (term[ind][0], a0);
        calc_level1 (term[ind][1], a1);
        calc_level1 (term[ind][2], a2);
        calc_level2 (term[ind][0], term[ind][1], a0, a1, a01);
        calc_level2 (term[ind][0], term[ind][2], a0, a2, a02);
        calc_level2 (term[ind][1], term[ind][2], a1, a2, a12);
        calc_level3 (term[ind][0], term[ind][1], term[ind][2], a0, a1, a2, a01, a02, a12, a012);
        for (int i = 0; i <= k; i ++)
            term_ans[i] = a012.data[i];
    }
    if (tp[ind] == 4)
    {
        calc_level1 (term[ind][0], a0);
        calc_level1 (term[ind][1], a1);
        calc_level1 (term[ind][2], a2);
        calc_level1 (term[ind][3], a3);
        calc_level2 (term[ind][0], term[ind][1], a0, a1, a01);
        calc_level2 (term[ind][0], term[ind][2], a0, a2, a02);
        calc_level2 (term[ind][1], term[ind][2], a1, a2, a12);
        calc_level2 (term[ind][0], term[ind][3], a0, a3, a03);
        calc_level2 (term[ind][1], term[ind][3], a1, a3, a13);
        calc_level2 (term[ind][2], term[ind][3], a2, a3, a23);
        calc_level3 (term[ind][0], term[ind][1], term[ind][2], a0, a1, a2, a01, a02, a12, a012);
        calc_level3 (term[ind][0], term[ind][1], term[ind][3], a0, a1, a3, a01, a03, a13, a013);
        calc_level3 (term[ind][0], term[ind][2], term[ind][3], a0, a2, a3, a02, a03, a23, a023);
        calc_level3 (term[ind][1], term[ind][2], term[ind][3], a1, a2, a3, a12, a13, a23, a123);
        calc_level4 (term[ind][0], term[ind][1], term[ind][2], term[ind][3], a0123);
        for (int i = 0; i <= k; i ++)
            term_ans[i] = a0123.data[i];
    }
}

void add_term (char* s)
{
    tp[tpp] = 0;
    for (int i = 0; s[i]; i ++)
        term[tpp][tp[tpp] ++] = s[i] - 'a';
    tpp ++;
}

int main ()
{
    int t, ct = 0;
    
    for (scanf ("%d", &t); t > 0; t --)
    {
        scanf("%s", buf);
        tpp = 0;
        
        for (int i = 0; buf[i];)
        {
            int j;
            for (j = i; buf[j]; j ++)
                if (buf[j] == '+')
                    break;
            if (buf[j] == '+')
            {
                buf[j] = 0;
                add_term (buf + i);
                i = j + 1;
            }
            else
            {
                add_term (buf + i);
                i = j;
            }
        }
        
        scanf ("%d%d", &k, &n);
        for (int i = 0; i < n; i ++)
        {
            scanf ("%s", buf);
            for (int j = 0; j < 26; j ++)
                data[i][j] = 0;
            for (int j = 0; buf[j]; j ++)
                data[i][buf[j] - 'a'] ++;
        }
        
        np[0] = 1;
        for (int i = 1; i <= k * 4 ; i ++)
            np[i] = np[i - 1] * n % maxh;
        
        for (int i = 1; i <= k; i ++)
            ans[i] = 0;

        for (int i = 0; i < tpp; i ++)
        {
            calc_term (i);
            for (int i = 1; i <= k; i ++)
                ans[i] = (ans[i] + term_ans[i]) % maxh;
        }
        
        printf("Case #%d:", ++ ct);
        for (int i = 1; i <= k; i ++)
            printf(" %d", ans[i] % maxh);
        printf("\n");
    }
    
    return 0;
}
/*
2
ab 10
3
aab
abbb
ab
*/
