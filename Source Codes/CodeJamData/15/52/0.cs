using System;
using System.Collections.Generic;
using System.Linq;

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

    XRand rnd;
    void init()
    {
        rnd = new XRand();
    }


    void calc()
    {
        int N = cin.nextInt();
        int K = cin.nextInt();
        long[] sum = new long[N - K + 1];
        for (int i = 0; i < N - K + 1; i++)
        {
            sum[i] = cin.nextInt();
        }
        long[] ar = new long[N];
        long[] mi = new long[K];
        long[] ma = new long[K];

        for (int i = K; i < N; i++)
        {
            ar[i] = ar[i - K] + sum[i - K + 1] - sum[i - K];
            mi[i % K] = Math.Min(mi[i % K], ar[i]);
            ma[i % K] = Math.Max(ma[i % K], ar[i]);
        }

        long add = 0;
        for (int i = 0; i < K; i++)
        {
            if (mi[i] < 0)
            {
                add -= mi[i];
                ma[i] -= mi[i];
                mi[i] = 0;
            }
        }

        add = sum[0] - add;
        add %= K;
        if (add < 0) add += K;

        long ret = 0;
        for (int i = 0; i < K; i++)
        {
            ret = Math.Max(ma[i], ret);
        }

        long ok = 0;
        for (int i = 0; i < K; i++)
        {
            ok += ret - ma[i];
        }
        if (ok < add) ret++;
        Console.WriteLine(ret);
    }

    //配列のランダム並び替え
    void randomshuffle<T>(T[] a)
    {
        int len = a.Length;
        for (int i = 0; i < len - 1; i++)
        {
            swap(ref a[i], ref a[i + rnd.nextInt(len - i)]);
        }
    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
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
