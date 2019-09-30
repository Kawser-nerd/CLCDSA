using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Threading;
using System.Threading.Tasks;


class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;

    public void run2()
    {
        XRand r = new XRand();

        cin = new Scanner();
        int T = cin.nextInt();
        init();

        for (int i = 1; i <= T; i++)
        {
            Console.Write("Case #{0}: ", i);
            calc();
        }
    }


    void init()
    {

    }

    int H, W;

    int gcd(int a, int b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void calc()
    {
        H = cin.nextInt();
        W = cin.nextInt();
        long[, ,] dp = new long[H + 1, 2, 13];
        dp[0, 0, 1] = 1;
        dp[0, 1, 1] = 1;
        long mod = (long)1e9 + 7;

        for (int i = 1; i <= H; i++)
        {
            if (i >= 1)
            {
                //normal 1
                for (int k = 1; k <= 12; k++)
                {
                    dp[i, 1, k] += dp[i - 1, 0, k];
                }
            }

            if (i >= 2)
            {
                //normal 2(all 3)
                for (int k = 1; k <= 12; k++)
                {
                    dp[i, 0, k] += dp[i - 2, 1, k];
                }

                //2-3
                if (W % 3 == 0)
                {
                    int mul = 3;
                    for (int k = 1; k <= 12; k++)
                    {
                        if (12 % k != 0) continue;
                        int g = gcd(mul, k);
                        int kake = mul / g;
                        int nextk = k * kake;
                        dp[i, 1, nextk] += dp[i - 2, 0, k] * g;
                    }
                }
                //2-6
                if (W % 6 == 0)
                {
                    int mul = 6;
                    for (int k = 1; k <= 12; k++)
                    {
                        if (12 % k != 0) continue;
                        int g = gcd(mul, k);
                        int kake = mul / g;
                        int nextk = k * kake;
                        dp[i, 1, nextk] += dp[i - 2, 0, k] * g;
                    }
                }
            }
            if (i >= 3)
            {
                //3-4
                if (W % 4 == 0)
                {
                    int mul = 4;
                    for (int k = 1; k <= 12; k++)
                    {
                        if (12 % k != 0) continue;
                        int g = gcd(mul, k);
                        int kake = mul / g;
                        int nextk = k * kake;
                        dp[i, 1, nextk] += dp[i - 3, 0, k] * g;
                    }
                }
            }

            for (int k = 1; k <= 12; k++)
            {
                dp[i, 0, k] %= mod;
                dp[i, 1, k] %= mod;
            }
        }

        long ans = 0;
        //(dp[H, 0, 0] + dp[H, 0, 1] + dp[H, 1, 0] + dp[H, 1, 1]) % mod;
        for (int i = 1; i <= 12; i++)
        {
            ans += dp[H, 0, i];
            ans += dp[H, 1, i];
            ans %= mod;
        }

        Console.WriteLine(ans);
    }



}

class XRand
{
    uint x, y, z, w;


    public XRand()
    {
        init();
    }

    public XRand(uint s)
    {
        init();
        init_xor128(s);
    }

    void init()
    {
        x = 314159265; y = 358979323; z = 846264338; w = 327950288;

    }

    public void init_xor128(uint s)
    {
        z ^= s;
        z ^= z >> 21; z ^= z << 35; z ^= z >> 4;
        z *= 736338717;
    }

    uint next()
    {
        uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
    }

    public long nextLong(long m)
    {
        return (long)((((ulong)next() << 32) + next()) % (ulong)m);
    }

    public int nextInt(int m)
    {
        return (int)(next() % m);
    }

    public int nextIntP(int a)
    {
        return (int)Math.Pow(a, nextDouble());
    }

    public int nextInt(int min, int max)
    {
        return min + nextInt(max - min + 1);
    }


    public double nextDouble()
    {
        return (double)next() / uint.MaxValue;
    }

    public double nextDoubleP(double a)
    {
        return Math.Pow(a, nextDouble());
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
        return s[i++];
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
