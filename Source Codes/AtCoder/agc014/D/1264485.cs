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

    int N;
    int[] a, b;
    List<int>[] es;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        a = new int[N - 1];
        b = new int[N - 1];
        es = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
        }
        for (int i = 0; i < N - 1; i++)
        {
            a[i] = cin.nextInt() - 1;
            b[i] = cin.nextInt() - 1;
            es[a[i]].Add(b[i]);
            es[b[i]].Add(a[i]);
        }

        int start = 0;
        if(dfs(0,-1) == 2)
        {
            Console.WriteLine("First");
            return;
        }
        for (int t = 0; t < 2; t++)
        {
            Queue<int> q = new Queue<int>();
            bool[] used = new bool[N];
            used[start] = true;
            q.Enqueue(start);
            int last = start;
            while(q.Count > 0)
            {
                int now = q.Dequeue();
                foreach (var next in es[now])
                {
                    if (used[next]) continue;
                    used[next] = true;
                    q.Enqueue(next);
                }
            }
            if(dfs(last, -1) == 2)
            {
                Console.WriteLine("First");
                return;
            }
            foreach (var next in es[last])
            {
                if (dfs(next, -1) == 2)
                {
                    Console.WriteLine("First");
                    return;
                }
            }
            start = last;
        }
        Console.WriteLine("Second");
        return;

    }

    int dfs(int p, int pre)
    {
        int ans = 0;
        foreach (var next in es[p])
        {
            if (next == pre) continue;
            ans += dfs(next, p);
        }
        if (ans >= 2) return 2;
        return 1 - ans;
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