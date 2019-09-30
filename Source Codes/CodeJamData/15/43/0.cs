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


    void init()
    {
        
    }


    void calc()
    {
        int N = cin.nextInt();
        int ans = 99999999;

        List<int>[] words = new List<int>[N];
        Dictionary<string, int> dic = new Dictionary<string, int>();
        for (int i = 0; i < N; i++)
        {
            words[i] = new List<int>();
            string[] st = Console.ReadLine().Split(' ');
            foreach (var w in st)
            {
                if (!dic.ContainsKey(w)) dic[w] = dic.Count;
                words[i].Add(dic[w]);
            }
        }

        for (int i = 0; i < (1 << N); i++)
        {
            if ((i & 3) != 2) continue;

            int[] flag = new int[dic.Count];
            for (int j = 0; j < N; j++)
            {
                int or = 1;
                if ((i >> j) % 2 == 1) or = 2;
                foreach (var item in words[j])
                {
                    flag[item] |= or;
                }
            }

            int temp = 0;
            foreach (var item in flag)
            {
                if (item == 3) temp++;
            }
            ans = Math.Min(ans, temp);

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
