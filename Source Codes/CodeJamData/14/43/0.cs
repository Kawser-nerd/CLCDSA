using System;
using System.Collections.Generic;
using System.Linq;

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
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);
            //Console.WriteLine("Case #{0}:", i + 1);

            run();
        }
    }



    void run()
    {
        int W = cin.nextInt();
        int H = cin.nextInt();
        int B = cin.nextInt();

        int[] x0 = new int[B];
        int[] y0 = new int[B];
        int[] x1 = new int[B];
        int[] y1 = new int[B];

        for (int i = 0; i < B; i++)
        {
            x0[i] = cin.nextInt();
            y0[i] = cin.nextInt();
            x1[i] = cin.nextInt() + 1;
            y1[i] = cin.nextInt() + 1;
        }

        Dictionary<int, int> xdic = new Dictionary<int, int>();
        Dictionary<int, int> ydic = new Dictionary<int, int>();
        for (int i = 0; i < B; i++)
        {
            xdic[x0[i]] = 1;
            xdic[x1[i]] = 1;
            ydic[y0[i]] = 1;
            ydic[y1[i]] = 1;
        }
        xdic[0] = xdic[W] = ydic[0] = ydic[H] = 1;


        //small test
        /*
        for (int i = 0; i < H; i++)
        {
            ydic[i] = 1;
        }
         */
        /*
        for (int j = 0; j < W; j++)
        {
            xdic[j] = 1;
        }
         */
        

        List<int> xl = new List<int>();
        List<int> yl = new List<int>();
        foreach (var item in xdic.Keys)
        {
            xl.Add(item);
        }
        foreach (var item in ydic.Keys)
        {
            yl.Add(item);
        }

        int[] xar = xl.ToArray();
        int[] yar = yl.ToArray();
        Array.Sort(xar);
        Array.Sort(yar);

        int X = xar.Length;
        int Y = yar.Length;
        for (int i = 0; i < X; i++)
        {
            xdic[xar[i]] = i;
        }
        for (int i = 0; i < Y; i++)
        {
            ydic[yar[i]] = i;
        }


        int[] wid = new int[X - 1];
        for (int i = 0; i < X - 1; i++)
        {
            wid[i] = xar[i + 1] - xar[i];
        }
        int[] hei = new int[Y - 1];
        for (int i = 0; i < Y - 1; i++)
        {
            hei[i] = yar[i + 1] - yar[i];
        }

        for (int i = 0; i < B; i++)
        {
            x0[i] = xdic[x0[i]];
            y0[i] = ydic[y0[i]];
            x1[i] = xdic[x1[i]];
            y1[i] = ydic[y1[i]];
        }

        bool[,] isblock = new bool[Y - 1, X - 1];
        for (int i = 0; i < B; i++)
        {
            for (int y = y0[i]; y < y1[i]; y++)
            {
                for (int x = x0[i]; x < x1[i]; x++)
                {
                    isblock[y, x] = true;   
                }
            }
        }


        V start = new V();
        V goal = new V();
        V[,] vin = new V[Y - 1, X - 1];
        V[,] vout = new V[Y - 1, X - 1];


        for (int i = 0; i < Y - 1; i++)
        {
            for (int j = 0; j < X - 1; j++)
            {
                vin[i, j] = new V();
                vout[i, j] = new V();
            }
        }

        for (int j = 0; j < X - 1; j++)
        {
            start.add(vin[0, j], wid[j]);
            vout[Y - 2, j].add(goal, wid[j]);
        }


        for (int i = 0; i < Y - 1; i++)
        {
            for (int j = 0; j < X - 1; j++)
            {
                if (isblock[i, j]) continue;
                vin[i, j].add(vout[i, j], Math.Max(hei[i], wid[j]));

                if (j != X - 2 && !isblock[i, j + 1])
                {
                    vout[i, j].add(vin[i, j + 1], hei[i]);
                    vout[i, j + 1].add(vin[i, j], hei[i]);
                }
                if (i != Y - 2 && !isblock[i + 1, j])
                {
                    vout[i, j].add(vin[i + 1, j], wid[j]);
                    vout[i + 1, j].add(vin[i, j], wid[j]);
                }
            }
        }

        Console.WriteLine(dinic(start, goal));
    }

    long INF = 1L << 62;
    long dinic(V s, V t)
    {
        long flow = 0;
        for (int p = 1; ; p++)
        {
            Queue<V> que = new Queue<V>();
            s.level = 0;
            s.p = p;
            que.Enqueue(s);
            while (que.Count != 0)
            {
                V v = que.Dequeue();
                v.iter = v.es.Count - 1;
                foreach (E e in v.es)
                {
                    if (e.to.p < p && e.cap > 0)
                    {
                        e.to.level = v.level + 1;
                        e.to.p = p;
                        que.Enqueue(e.to);
                    }
                }
            }
            if (t.p < p) return flow;
            for (long f = 0; (f = dfs(s, t, INF)) > 0; )
            {
                flow += f;
            }
        }
    }

    long dfs(V v, V t, long f)
    {
        if (v == t) return f;
        for (; v.iter >= 0; v.iter--)
        {
            E e = v.es[v.iter];
            if (v.level < e.to.level && e.cap > 0)
            {
                long d = dfs(e.to, t, Math.Min(f, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    e.rev.cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    class V
    {
        public V() { }
        public List<E> es = new List<E>();
        public int level, p, iter;


        public void add(V to, long cap)
        {
            E e = new E(to, cap);
            E rev = new E(this, 0);
            e.rev = rev;
            rev.rev = e;
            es.Add(e);
            to.es.Add(rev);
        }

    }

    class E
    {
        public V to;
        public E rev;
        public long cap;
        public E(V to, long cap)
        {
            this.to = to;
            this.cap = cap;
        }

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
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
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
