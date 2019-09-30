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
    static Scanner cin;
    public Myon() { }
    public static int Main()
    {
        cin = new Scanner();
        new Myon().calc();
        return 0;
    }

    int N;
    long[] A;
    List<int>[] es;
    
    public bool calc2()
    {
        N = cin.nextInt();
        A = new long[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextLong();
        }
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


        max = new long[N];
        min = new long[N];
        if (!dfs(0, -1)) return false;
        if (max[0] >= 0 && min[0] <= 0) return true;
        return false;
    }

    long[] max, min;

    bool dfs(int now, int pre)
    {
        long T = A[now];

        foreach (var next in es[now])
        {
            if (next == pre) continue;
            if (!dfs(next, now)) break;
        }

        long minsum = 0;
        foreach (var next in es[now])
        {
            if (next == pre) continue;
            minsum += min[next];
            if (min[next] > T) return false;
        }
        if (minsum > 2 * T) return false;

        long maxsum = 0;
        foreach (var next in es[now])
        {
            maxsum += Math.Min(T, max[next]);
        }

        if(es[now].Count == 1)
        {
            min[now] = Math.Max(0, T - maxsum);
            max[now] = Math.Min(T, 2 * T - minsum);
        }
        else
        {
            min[now] = Math.Max(0, 2 * T - maxsum);
            max[now] = Math.Min(T, 2 * T - minsum);
        }

        if (min[now] > max[now]) return false;
        return true;
    }

    public void calc()
    {
        if (calc2()) Console.WriteLine("YES");
        else Console.WriteLine("NO");
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
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