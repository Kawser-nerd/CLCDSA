using System;

public class Hello
{
    const int MOD = 1000000007;
    const int FMAX = 510000;

    public static void Main()
    {
        var fac = new long[FMAX];
        var finv = new long[FMAX];
        var inv = new long[FMAX];
        COMinit(fac, finv, inv);
        string[] line = Console.ReadLine().Trim().Split(' ');
        var w = int.Parse(line[0]);
        var h = int.Parse(line[1]);
        var ret = COM(fac, finv, inv, w + h -2, w -1);
        Console.WriteLine(ret);
    }
    public static long COM(long[] fac, long[] finv, long[] inv, int n, int k)
    {
        if (n < k) return 0;
        if (n < 0 | k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
    public static void COMinit(long[] fac, long[] finv, long[] inv)
    {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < FMAX; i++)
        {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
}