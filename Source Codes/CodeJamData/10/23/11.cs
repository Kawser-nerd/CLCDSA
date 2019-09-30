using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class C : Solution
{
    int n;
    const int mod = 100003;

    int[,] table, c;

    public override void Init(System.IO.TextReader r)
    {
        n = int.Parse(r.ReadLine());
        table = new int[n + 1, n + 1];
        c = new int[n + 1, n + 1];

        c[0, 0] = 1;
        for(int i = 1; i<=n; i++)
            for (int j = 0; j <= i; j++)
            {
                c[i, j] = ((j>0?c[i - 1, j-1]:0) + c[i-1, j]) % mod;
            }
    }


    public override string Solve()
    {
        int ret = 0;
        
        table[0, 1] = 1;
        
        for(int i = 0; i<n; i++)
            for (int j = i+1; j <= n; j++)
                for(int k = j+1; k<=n; k++)
                {
                    table[j, k] = (table[j,k] + table[i, j] * c[k - j - 1, j - i - 1])%mod;
                }

        for (int i = 0; i <= n; i++)
        {
            ret = (ret + table[i, n]) % mod;
        }
        return ret.ToString();        
    }
}