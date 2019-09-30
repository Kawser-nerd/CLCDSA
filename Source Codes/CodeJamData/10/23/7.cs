using System;
using System.Collections.Generic;

public class C : BaseProblem {

    private static long[,] matr;
    private static int[,] comb;
    protected override string solveCase() {
        int n=reader.RowToInt();
        matr = new long[n + 1, n + 1];
        comb = new int[n + 1, n + 1];

        comb[0, 0] = 1;
        comb[1, 0] = 1;
        comb[1, 1] = 1;
        matr[2, 1] = 1;

        for (int i = 2; i <= n; i++){
            for (int j = 0; j <= i; j++){
                comb[i, j] = comb[i - 1, j];
                if (j > 0) comb[i, j] += comb[i - 1, j - 1];
                comb[i, j] %= 100003;
            }
        }

        


        long q = calc(n);

        
        return q.ToString();
    }

    long calc(int n)
    {
        long res = 0;
        for (int i = 1; i < n; i++)
        {
            res += calc(n, i);
            res %= 100003;
        }
        return res;
    }

    long calc(int n,int p)
    {
        if (p == 1) return 1;
        if (matr[n, p] != 0) return matr[n, p];
        long res = 0;
        int dn = n - p - 1;

        for (int i = 1; i < p; i++)
        {
            int k = p - i - 1;
            if (k>dn) continue;
            long s = calc(p,i);
            res += s*comb[dn, k];
            res %= 100003;
        }

        res %= 100003;
        matr[n, p] = res;

        return res;
    }

    
}

