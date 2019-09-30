using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }

    Scanner cin;


    long mod = 1000000007;


    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int Q = cin.nextInt();
        int[] A = cin.ArrayInt(N);
        int[] X = new int[Q];
        int[] Y = new int[Q];
        for (int i = 0; i < Q; i++)
        {
            X[i] = cin.nextInt() - 1;
            Y[i] = cin.nextInt() - 1;
        }

        long[,] dp = new long[N, N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (A[i] > A[j]) dp[i, j] = 1;
            }
        }

        long m2 = (mod + 1) / 2;

        long mul = 1;

        for (int t = 0; t < Q; t++)
        {
            int a = X[t];
            int b = Y[t];
            for (int i = 0; i < N; i++)
            {
                if (i == a || i == b) continue;

                long IA = dp[i, a];
                long IB = dp[i, b];
                long AI = dp[a, i];
                long BI = dp[b, i];

                dp[i, a] += IB;
                dp[i, b] += IA;
                dp[a, i] += BI;
                dp[b, i] += AI;

                dp[i, a] %= mod;
                dp[i, b] %= mod;
                dp[a, i] %= mod;
                dp[b, i] %= mod;

                dp[i, a] *= m2;
                dp[i, b] *= m2;
                dp[a, i] *= m2;
                dp[b, i] *= m2;

                dp[i, a] %= mod;
                dp[i, b] %= mod;
                dp[a, i] %= mod;
                dp[b, i] %= mod;
            }

            dp[a, b] += dp[b, a];
            dp[a, b] %= mod;
            dp[a, b] *= m2;
            dp[a, b] %= mod;
            dp[b, a] = dp[a, b];

            mul *= 2;
            mul %= mod;
        }

        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                sum += dp[i, j];
            }
        }
        sum %= mod;
        sum *= mul;
        sum %= mod;
        Console.WriteLine(sum);
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
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
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