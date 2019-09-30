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
        long[] P = new long[N];
        long[] cnt = new long[N];
        for (int i = 0; i < N; i++)
        {
            P[i] = cin.nextLong();
        }
        for (int i = 0; i < N; i++)
        {
            cnt[i] = cin.nextLong();
        }

        int zerocnt = 0;
        long myon = cnt[0];
        List<long> ret = new List<long>();
        while (myon > 1)
        {
            myon /= 2;
            zerocnt++;
            ret.Add(0);
        }

        while (P.Length > 1)
        {
            Dictionary<long, int> dic = new Dictionary<long, int>();
            for (int i = 0; i < P.Length; i++)
            {
                dic[P[i]] = i;
            }
            for (int i = 0; i < P.Length; i++)
            {
                long target = P[i];
                if (target == 0) continue;
                bool flag = true;
                for (int j = 0; j < P.Length; j++)
                {
                    if (!dic.ContainsKey(P[j] - target) && !dic.ContainsKey(P[j] + target))
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;

                long[] tempP = (long[])P.Clone();
                long[] tempcnt = (long[])cnt.Clone();
                long[] myoncnt = new long[P.Length];

                if (target > 0)
                {
                    for (int j = 0; j < P.Length; j++)
                    {
                        if (tempcnt[j] == 0) continue;
                        if (tempcnt[j] < 0)
                        {
                            flag = false;
                            break;
                        }
                        if (!dic.ContainsKey(P[j] + target))
                        {
                            flag = false;
                            break;
                        }
                        int ne = dic[P[j] + target];
                        tempcnt[ne] -= tempcnt[j];
                        myoncnt[j] = tempcnt[j];
                        tempcnt[j] = 0;
                    }
                }
                else
                {
                    for (int j = P.Length - 1; j >= 0; j--)
                    {
                        if (tempcnt[j] == 0) continue;
                        if (tempcnt[j] < 0)
                        {
                            flag = false;
                            break;
                        }
                        if (!dic.ContainsKey(P[j] + target))
                        {
                            flag = false;
                            break;
                        }
                        int ne = dic[P[j] + target];
                        tempcnt[ne] -= tempcnt[j];
                        myoncnt[j] = tempcnt[j];
                        tempcnt[j] = 0;

                    }
                }
                if (flag)
                {
                    //ok
                    ret.Add(target);
                    List<long> nextP = new List<long>();
                    List<long> nextcnt = new List<long>();
                    for (int j = 0; j < P.Length; j++)
                    {
                        if (myoncnt[j] > 0)
                        {
                            nextP.Add(P[j]);
                            nextcnt.Add(myoncnt[j]);
                        }
                    }
                    P = nextP.ToArray();
                    cnt = nextcnt.ToArray();
                }
                break;
            }
        }
        long[] retar = ret.ToArray();
        Array.Sort(retar);
        Console.WriteLine(string.Join(" ", retar));

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
