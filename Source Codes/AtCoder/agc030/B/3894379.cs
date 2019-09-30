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

    long L;
    int N;

    void calc()
    {
        cin = new Scanner();
        L = cin.nextLong();
        N = cin.nextInt();
        long[] X = new long[N + 1];
        for (int i = 0; i < N; i++)
        {
            X[i] = cin.nextLong();
        }
        X[N] = L;

        long[] Llen = new long[N + 1];
        long[] Rlen = new long[N + 1];
        for (int i = 0; i < N; i++)
        {
            Llen[i + 1] = X[i];
            Rlen[i + 1] = L - X[N - i - 1];
        }

        long Lans = calc2(Llen, Rlen);
        long Rans = calc2(Rlen, Llen);
        Console.WriteLine(Math.Max(Lans, Rans));

    }

    long calc2(long[] L, long[] R)
    {

        long now = 0;
        for (int i = 0; i < N; i++)
        {
            now += (L[i + 1] - L[i]) * Math.Max((N) - i * 2, 0);
            now += (R[i + 1] - R[i]) * Math.Max((N) - i * 2 - 1, 0);
        }
        
        long ans = now;

        for (int i = 0; i < N; i++)
        {
            now += L[(N + i + 2) / 2];
            now -= L[i + 1] * 2;
            now -= R[(N - i) / 2];

            ans = Math.Max(ans, now);
            
        }
        

        return ans;
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