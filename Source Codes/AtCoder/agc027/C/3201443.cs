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

    int N, M;
    string s;
    List<int>[] es;

    Queue<long> q;
    long[] hash;
    XRand rnd;

    Dictionary<long, bool[]> dic;

    int[] acnt, bcnt;
    bool[] active;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        M = cin.nextInt();
        s = cin.next();
        es = new List<int>[N];
        active = new bool[N];
        acnt = new int[N];
        bcnt = new int[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
            active[i] = true;
        }

        for (int i = 0; i < M; i++)
        {
            int a = cin.nextInt() - 1;
            int b = cin.nextInt() - 1;
            es[a].Add(b);
            es[b].Add(a);

            if (s[a] == 'A') acnt[b]++;
            else bcnt[b]++;

            if (s[b] == 'A') acnt[a]++;
            else bcnt[a]++;
        }

        Queue<int> q = new Queue<int>();
        for (int i = 0; i < N; i++)
        {
            if(acnt[i] == 0 || bcnt[i] == 0)
            {
                active[i] = false;
                q.Enqueue(i);
            }
        }

        while(q.Count != 0)
        {
            int now = q.Dequeue();
            if(s[now] == 'A')
            {
                foreach (var next in es[now])
                {
                    acnt[next]--;
                    if(active[next] && acnt[next] == 0)
                    {
                        active[next] = false;
                        q.Enqueue(next);
                    }
                }
            }
            else
            {
                foreach (var next in es[now])
                {
                    bcnt[next]--;
                    if (active[next] && bcnt[next] == 0)
                    {
                        active[next] = false;
                        q.Enqueue(next);
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (active[i])
            {
                Console.WriteLine("Yes");
                return;
            }
        }

        Console.WriteLine("No");
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