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

    List<int>[] es;
    int N;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        es = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
        }

        for (int i = 0; i < N - 1; i++)
        {
            int a = cin.nextInt() - 1;
            int b = cin.nextInt() - 1;
            es[a].Add(b);
            es[b].Add(a);
        }
        int[] firstD = getDist(new int[] { 0 });
        int PosA = 0;
        int Len = -1;
        for (int i = 0; i < N; i++)
        {
            if(firstD[i] > Len)
            {
                Len = firstD[i];
                PosA = i;
            }
        }
        int[] secondD = getDist(new int[] { PosA });
        int PosB = 0;
        Len = -1;

        for (int i = 0; i < N; i++)
        {
            if (secondD[i] > Len)
            {
                Len = secondD[i];
                PosB = i;
            }
        }
        int[] ThirdD = getDist(new int[] { PosB });

        List<int> ps = new List<int>();
        for (int i = 0; i < N; i++)
        {
            if(ThirdD[i] + secondD[i] == Len && Math.Abs(ThirdD[i] - secondD[i]) <= 1)
            {
                ps.Add(i);
            }
        }

        int[] depth = getDist(ps.ToArray());

        int maxD = 0;
        foreach (var d in depth)
        {
            maxD = Math.Max(maxD, d);
        }

        int[] edge = new int[maxD + 1];
        for (int i = 0; i < N; i++)
        {
            int cnt = 0;
            foreach (var next in es[i])
            {
                if (depth[next] == depth[i] + 1)
                {
                    cnt++;
                }
            }
            edge[depth[i]] = Math.Max(edge[depth[i]], cnt);
        }

        long ans = ps.Count;
        foreach (var mul in edge)
        {
            ans *= Math.Max(1, mul);
        }

        if(ps.Count == 1)
        {
            for (int t = 0; t < N; t++)
            {
                if (depth[t] != 1) continue;
                List<int> ps2 = new List<int>();
                ps2.Add(ps[0]);
                ps2.Add(t);
                int[] d2 = getDist(ps2.ToArray());


                int[] edge2 = new int[maxD + 1];
                for (int i = 0; i < N; i++)
                {
                    int cnt = 0;
                    foreach (var next in es[i])
                    {
                        if (d2[next] == d2[i] + 1)
                        {
                            cnt++;
                        }
                    }
                    edge2[d2[i]] = Math.Max(edge2[d2[i]], cnt);
                }

                long ans2 = ps2.Count;
                foreach (var mul in edge2)
                {
                    ans2 *= Math.Max(1, mul);
                }
                ans = Math.Min(ans, ans2);
            }
        }

        Console.WriteLine($"{maxD + 1} {ans}");


    }

    int[] getDist(int[] start)
    {
        int[] ans = new int[N];
        int MAX = 999999;
        for (int i = 0; i < N; i++)
        {
            ans[i] = MAX;
        }

        Queue<int> q = new Queue<int>();
        foreach (var i in start)
        {
            ans[i] = 0;
            q.Enqueue(i);
        }
        while(q.Count != 0)
        {
            int now = q.Dequeue();
            foreach (var next in es[now])
            {
                if (ans[next] != MAX) continue;
                ans[next] = ans[now] + 1;
                q.Enqueue(next);
            }
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