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

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int K = cin.nextInt();
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

        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            List<int> over = new List<int>();
            List<int> under = new List<int>();
            foreach (var item in es[i])
            {
                over.Add(dfs(item, i, (K + 1) / 2));
                under.Add(dfs(item, i, (K) / 2));
            }

            int sum = under.Sum();
            for (int j = 0; j < over.Count; j++)
            {
                ans = Math.Max(ans, sum - under[j] + over[j] + 1);
            }
        }

        ans = N - ans;

        Console.WriteLine(ans);
    }
    
    int dfs(int a, int pre, int dep)
    {
        if (dep <= 0) return 0;
        int ans = 1;
        foreach (var next in es[a])
        {
            if (next == pre) continue;
            ans += dfs(next, a, dep - 1);
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