using System;
class Program
{
    static int n;
    static int a;
    static int b;
    static long k;
    static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        n = int.Parse(s[0]);
        a = int.Parse(s[1]);
        b = int.Parse(s[2]);
        int at = a, bt = b;
        a = Math.Max(at, bt);
        b = Math.Min(at, bt);
        k = long.Parse(s[3]);
        int mod = 998244353;
        Comb c = new Comb(n, mod);
        long ans = 0;
        for (long r = 0; r <= Math.Min(k / a, n); r++)
        {
            if ((k - a * r) % b != 0)
                continue;
            long bl = (k - a * r) / b;
            if (bl > n)
                continue;
            ans += (c.comb((int)r) * c.comb((int)bl)) % mod;
            ans = ans % mod;
        }
        Console.WriteLine(ans);
    }
}
class Comb
{
    int n;
    int mod;
    int fac;
    int[] finv;
    int[] inv;
    public Comb(int n, int mod)
    {
        this.n = n;
        this.mod = mod;
        finv = new int[n + 1];
        inv = new int[n + 1];
        fac = 1;
        finv[0] = 1;
        finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            inv[i] = mod - (int)((long)inv[mod % i] * (mod / i) % mod);
            fac = (int)((long)fac * i % mod);
            finv[i] = (int)(((long)finv[i - 1] * inv[i]) % mod);
        }
    }
    public long comb(int i)
    {
        return fac * ((long)finv[i] * finv[n - i] % mod) % mod;
    }
}