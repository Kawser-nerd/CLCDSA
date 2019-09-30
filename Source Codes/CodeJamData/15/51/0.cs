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
        int D = cin.nextInt();
        int S0 = cin.nextInt();
        int As = cin.nextInt();
        int Cs = cin.nextInt();
        int Rs = cin.nextInt();
        int M0 = cin.nextInt();
        int Am = cin.nextInt();
        int Cm = cin.nextInt();
        int Rm = cin.nextInt();
        int[] S = new int[N];
        int[] M = new int[N];
        S[0] = S0;
        M[0] = M0;
        for (int i = 1; i < N; i++)
        {
            S[i] = (int)(((long)S[i - 1] * As + Cs) % Rs);
            M[i] = (int)(((long)M[i - 1] * Am + Cm) % Rm);
        }
        for (int i = 1; i < N; i++)
        {
            M[i] %= i;
        }
        for (int i = 0; i < N; i++)
        {
        }

        int[] mi = new int[N];
        int[] ma = new int[N];
        mi[0] = S[0];
        ma[0] = S[0];
        for (int i = 1; i < N; i++)
        {
            mi[i] = Math.Min(mi[M[i]], S[i]);
            ma[i] = Math.Max(ma[M[i]], S[i]);
        }
        List<int> l = new List<int>();
        for (int i = 0; i < N; i++)
        {
            if (mi[i] >= ma[i] - D)
            {
                l.Add((ma[i] - D) * 2);
                l.Add(mi[i] * 2 + 1);
            }
        }
        int[] ar = l.ToArray();
        int ret = 0;
        int cnt = 0;
        Array.Sort(ar);
        foreach (var item in ar)
        {
            if (item % 2 == 0) cnt++;
            else cnt--;
            ret = Math.Max(ret, cnt);
        }
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
