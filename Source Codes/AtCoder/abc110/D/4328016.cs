using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static long Mod = 1000000007;

    static Dictionary<int,int> Factorize(int M)
    {
        Dictionary<int, int> r = new Dictionary<int, int>();
        while (M % 2 == 0)
        {
            M = (M - (M % 2)) / 2;
            if (r.ContainsKey(2))
                r[2]++;
            else
                r.Add(2, 1);
        }
        for(int i = 3; i <= M; i += 2)
        {
            while (M % i == 0)
            {
                M = (M - (M % i)) / i;
                if (r.ContainsKey(i))
                    r[i]++;
                else
                    r.Add(i, 1);
            }
        }
        return r;
    }
        
    public static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        int N = int.Parse(s[0]);
        int M = int.Parse(s[1]);

        var r = Factorize(M);


        int maxduality;
        if (r.Count > 0)
            maxduality = r.Max(x => x.Value);
        else
            maxduality = 1;

        long[][] dp = new long[maxduality + 1][];
        for (int i = 0; i <= maxduality; i++)
            dp[i] = new long[N + 1];

        for (int i = 0; i <= N; i++)
        {
            dp[1][i] = i;
            dp[0][i] = i;
        }
        for (int i = 0; i <= maxduality; i++)
        {
            dp[i][1] = 1;
            dp[i][0] = 1;
        }
        for(int i = 2; i <= maxduality; i++)
        {
            for (int j = 2; j <= N; j++)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % Mod;
            }
        }
        long q = 1;
        if (r.Count > 0)
            foreach (var i in r)
            q = (q * dp[i.Value][N]) % Mod;
        Console.WriteLine(q);
    }
}