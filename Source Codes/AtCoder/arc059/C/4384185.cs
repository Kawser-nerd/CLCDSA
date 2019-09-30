using System;

public class AtCoder
{
    public static void Main()
    {
        string[] s;
        s = NextS();

        int n = int.Parse(s[0]);
        int c = int.Parse(s[1]);
        const int p = 1000000007;

        int[] a = new int[n];
        int[] b = new int[n];
        s = NextS();
        for (int i = 0; i < n; i++) a[i] = int.Parse(s[i]);
        s = NextS();
        for (int i = 0; i < n; i++) b[i] = int.Parse(s[i]);

        Mod mod = new Mod(410);

        long[][] mp = new long[410][];
        for (int i = 0; i < 410; i++)
        {
            mp[i] = new long[410];
            for(int j=0; j< 410; j++)
            {
                mp[i][j] = mod.Pow(i, j);
            }
        }        

        long[][] x = new long[n][];
        for (int i = 0; i < n; i++) {
            x[i] = new long[c + 1];
            for (int j = 0; j <= c; j++)
            {
                for(int k=a[i]; k<=b[i]; k++)
                {
                    x[i][j] += mp[k][j];
                    x[i][j] %= p;
                } 
            }
        }

        long[][] dp = new long[n][];
        dp[0] = new long[c + 1];
        for (int j = 0; j <= c; j++)
        {
            dp[0][j] = x[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            dp[i] = new long[c + 1];
            for(int j=0; j<=c; j++)
            {
                for(int k=0; k<=j; k++)
                {
                    dp[i][j] += dp[i - 1][j - k] * x[i][k];
                    dp[i][j] %= p;
                }               
            }
        }

        Console.WriteLine(dp[n-1][c]);
    }

    public static void DebugWL(object x) { System.Diagnostics.Debug.WriteLine(x); }
    public static string[] NextS() { return Console.ReadLine().Trim().Split(' '); }
}

// Mod(int n)
// int[] fac: factors (1-indexed)
// int n: the length of fac

// int .Ncr(n,r): nCr
// int .Fac(n): n!%p
// int .Pow(n,m): n^m%p

public class Mod
{
    const int p = 1000000007;
    int[] fac;

    public Mod(int n)
    {
        fac = new int[n + 1];
        for (int i = 1; i <= n; i++) fac[i] = -1;
        fac[0] = 1;
    }

    public int Ncr(int n, int r)
    {
        if (n < r) return 0;
        if (r == 0 | n == r) return 1;
        long a = Fac(n);
        a = a * Pow(Fac(n - r), p - 2) % p;
        a = a * Pow(Fac(r), p - 2) % p;
        return (int)a;
    }

    public int Fac(int n)
    {
        if (fac[n] >= 0) return fac[n];
        long k = 1;
        for (long i = 1; i <= n; i++)
        {
            k = k * i % p;
        }
        fac[n] = (int)k;
        return fac[n];
    }

    public int Pow(int n, int m)
    {
        if (m == 0) return 1;
        if (m == 1) return n;
        long a = 1;
        if (m % 2 == 0)
        {
            a = Pow(n, m / 2);
            a = a * a % p;
        }
        else
        {
            a = Pow(n, m / 2);
            a = a * a % p;
            a = a * n % p;
        }
        return (int)a;
    }
}