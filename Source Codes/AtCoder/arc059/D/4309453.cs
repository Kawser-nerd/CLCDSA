using System;
class Program
{
    static long mod = (long)1e9 + 7;
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int length = Console.ReadLine().Length;
        long[,] dp = new long[N + 1, N + 1];
        dp[0, 0] = 1;
        for (int n = 0; n < N; n++)
        {
            for (int l = 0; l <= n; l++)
            {
                dp[n + 1, Math.Max(l - 1, 0)] += dp[n, l];
                dp[n + 1, Math.Max(l - 1, 0)] %= mod;
                dp[n + 1, l + 1] += (2 * dp[n, l]) % mod;
                dp[n + 1, l + 1] %= mod;
            }
        }
        long ans = dp[N, length];
        long d = Pow(2, mod - 2);
        d = Pow(d, length);
        ans *= d;
        ans %= mod;
        Console.WriteLine(ans);
    }
    static long Pow(long a, long n) //a^n?mod???????
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return a % mod;
        long z = Pow(a, n / 2);
        if (n % 2 == 0)
            return z * z % mod;
        return z * z % mod * a % mod;
    }
}