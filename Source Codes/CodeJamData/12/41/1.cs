using System;
using System.Collections.Generic;


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
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

}


class Myon
{
    Scanner cin;
    Myon() { }

    public static void Main()
    {
        new Myon().multi();
    }

    void multi()
    {
        int c;
        cin = new Scanner();
        int T = cin.nextInt();
        for (c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }

    void calc()
    {
        int n = cin.nextInt();
        int[] dp = new int[n];
        int[] x = new int[n];
        int[] d = new int[n];
        for (int i = 0; i < n; i++)
        {
            x[i] = cin.nextInt();
            d[i] = cin.nextInt();
        }
        int D = cin.nextInt();
        dp[0] = x[0];
        if (dp[0] + x[0] >= D)
        {
            Console.WriteLine("YES");
            return;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (x[i] - x[j] > dp[j]) continue;
                dp[i] = Math.Min(x[i] - x[j], d[i]);
            }
            //Console.WriteLine(i + ":  " + dp[i]);
            if (dp[i] + x[i] >= D)
            {
                Console.WriteLine("YES");
                return;
            }
        }
        Console.WriteLine("NO");

    }


}
