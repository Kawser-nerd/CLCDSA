using System;
using System.Collections.Generic;
using System.Linq;

public class Combination
{
    private readonly long[] Fact;
    private readonly long[] InvFact;  // ??????
    private readonly long Mod;

    public Combination(long n, long mod)
    {
        Mod = mod;
        Fact = new long[n + 1];
        InvFact = new long[n + 1];

        long f = 1;
        Fact[0] = f;
        for (long i = 1; i <= n; i++)
        {
            f *= i;
            f %= mod;
            Fact[i] = f;
        }

        // ????????? a^(-1) = a^(mod-2)
        long inv = Power(f, mod - 2, mod);

        InvFact[n] = inv;
        for (long i = n - 1; i >= 0; i--)
        {
            InvFact[i] = (InvFact[i + 1] * (i + 1)) % mod;
        }
    }

    public long GetCombination(long n, long r)
    {
        var comb = (Fact[n] * InvFact[r]) % Mod;
        comb = (comb * InvFact[n - r]) % Mod;
        return comb;
    }

    // x^n
    static long Power(long x, long n, long mod)
    {
        long pow = 1;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                x *= x;
                x %= mod;
                n /= 2;
            }
            else
            {
                pow *= x;
                pow %= mod;
                n--;
            }
        }

        return pow;
    }
}

class Solution
{

    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var n = vals[0];
        var a = vals[1];
        var b = vals[2];
        var k = vals[3];

        const long mod = 998244353;
        var comb = new Combination(n, mod);

        long pattern = 0;
        for (int an = 0; an <= n; an++)
        {
            var bk = k - a * an;
            if (bk < 0)
            {
                break;
            }
            if (bk % b == 0)
            {
                var bn = bk / b;
                if (bn <= n)
                {
                    pattern += (comb.GetCombination(n, an) * comb.GetCombination(n, bn)) % mod;
                    pattern %= mod;
                }
            }
        }

        Console.WriteLine(pattern);
    }
}