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
    List<Tuple<int, int>>[] es;
    long[] pos;
    bool[] check;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        M = cin.nextInt();
        es = new List<Tuple<int, int>>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<Tuple<int, int>>();
        }
        for (int i = 0; i < M; i++)
        {
            int l, r, d;
            l = cin.nextInt() - 1;
            r = cin.nextInt() - 1;
            d = cin.nextInt();
            es[l].Add(Tuple.Create(r, d));
            es[r].Add(Tuple.Create(l, -d));
        }

        pos = new long[N];
        check = new bool[N];
        for (int i = 0; i < N; i++)
        {
            if (check[i]) continue;
            pos[i] = 0;
            if (!dfs(i))
            {
                Console.WriteLine("No");
                return;
            }
        }

        Console.WriteLine("Yes");
    }
    
    bool dfs(int a)
    {
        check[a] = true;
        foreach (var next in es[a])
        {
            int p = next.Item1;
            long npos = next.Item2 + pos[a];
            if (check[p])
            {
                if (npos != pos[p]) return false;
                continue;
            }
            else
            {
                pos[p] = npos;
                if (!dfs(p)) return false;
            }
        }
        return true;
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