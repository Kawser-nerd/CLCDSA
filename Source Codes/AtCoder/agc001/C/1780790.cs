using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;


class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }

    Scanner cin;


    int ans;
    int N, K;
    List<int>[] es;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        K = cin.nextInt();
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

        ans = 99999;

        for (int i = 0; i < N; i++)
        {
            if (K % 2 == 0) calc(i, i);
            else
            {
                foreach (int j in es[i])
                {
                    if(i < j) calc(i, j);
                }
            }
        }
        
        Console.WriteLine(ans);
    }

    void calc(int a, int b)
    {
        int[] dist;
        Queue<int> q;

        int MAX = 99999;

        dist = new int[N];
        for (int i = 0; i < N; i++)
        {
            dist[i] = MAX;
        }
        dist[a] = 0;
        dist[b] = 0;
        q = new Queue<int>();
        q.Enqueue(a);
        if(a != b) q.Enqueue(b);
        int cnt = 0;

        while (q.Count != 0)
        {
            int now = q.Dequeue();
            if (dist[now] > K / 2) break;
            cnt++;
            foreach (var next in es[now])
            {
                if (dist[next] != MAX) continue;
                dist[next] = dist[now] + 1;
                q.Enqueue(next);
            }
        }
        
        ans = Math.Min(ans, N - cnt);
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