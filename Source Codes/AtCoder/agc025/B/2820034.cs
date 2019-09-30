using System.Linq;
using System.Collections.Generic;
using System;

public class P
{
    public int r { get; set; }
    public int b { get; set; }
}

public class Hello
{
    const int MOD = 998244353;
    const int FMAX = 510000;

    public static void Main()
    {
        var fac = new long[FMAX];
        var finv = new long[FMAX];
        var inv = new long[FMAX];
        COMinit(fac, finv, inv);
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var a = long.Parse(line[1]);
        var b = long.Parse(line[2]);
        var k = long.Parse(line[3]);
        var ps = new List<P>();
        var rmax = k / a;
        var bmax = k / b;
        for (long i = 1; i <= rmax; i++)
        {
            var w = k - a * i;
            if (w % b == 0 && w / b >= 1 && w / b <= bmax)
                ps.Add(new P { r = (int)i, b = (int)(w / b) });
        }
        if (ps.Count() == 0) { Console.WriteLine(1); goto end; }
        var ret = 0L;
        foreach (var x in ps)
        {
            var w1 = (COM(fac, finv, inv, n, x.r) * COM(fac, finv, inv, n, x.b)) % MOD;
            ret += w1;
            ret %= MOD;
        }
        Console.WriteLine(ret);
        end:;
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