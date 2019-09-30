using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;

class Iroha
{
    public Iroha() { }
    public static int Main()
    {
        new Iroha().calc();
        return 0;
    }

    Scanner cin;
    
    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int K = cin.nextInt();
        long[] dp = new long[N + 1];
        long INF = long.MaxValue / 4;
        for (int i = 0; i < dp.Length; i++)
        {
            dp[i] = INF;
        }
        long[] a = new long[N];
        long asum = 0;
        for (int i = 0; i < N; i++)
        {
            a[i] = cin.nextLong();
            asum += a[i];
        }
        dp[0] = 0;
        dp[1] = 1;
        long sum = a[0];
        long minimum = K - asum;
        minimum += a[0];

        for (int j = 0; j < dp.Length; j++)
        {
            dp[j] = Math.Max(dp[j], minimum);
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = dp.Length - 1; j >= 0; j--)
            {
                if (dp[j] > K) continue;

                long need = dp[j] * (sum + a[i]) / sum;
                while (need * sum <= (sum + a[i]) * dp[j]) need++;
                need -= dp[j];
                if (need > a[i]) continue;
                dp[j + 1] = Math.Min(dp[j] + need, dp[j + 1]);
                
            }
            sum += a[i];
            minimum += a[i];
            for (int j = 0; j < dp.Length; j++)
            {
                dp[j] = Math.Max(dp[j], minimum);
            }
            //Console.WriteLine(minimum);
        }

        for (int i = dp.Length - 1; i >= 0; i--)
        {
            if(dp[i] <= K)
            {
                Console.WriteLine(i);
                return;
            }
        }
        
    }
    
}

class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return next();
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}