using System;

public class AtCoder
{
    public static void Main()
    {
        string[] s;
        s = NextS();
        int n = int.Parse(s[0]);
        s = NextS();
        int c = s[0].Length;
        const int p = 1000000007;

        if (c > n)
        {
            Console.WriteLine(0);
            return;
        }

        Mod mod = new Mod(5010);

        long[][] dp = new long[n+1][];
        dp[0] = new long[n + 2];
        dp[0][0] = 1;
        for(int i=1; i<=n; i++)
        {
            dp[i] = new long[n+2];
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] %= p;
            for(int j = 1; j<=i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] * 2 + dp[i - 1][j + 1];
                dp[i][j] %= p;
            }         
        }

        long bin = 1;
        for (int i = 0; i < c; i++) bin = bin * 2 % p;
        Console.WriteLine(dp[n][c] * mod.Pow((int)bin, p - 2) % p);

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