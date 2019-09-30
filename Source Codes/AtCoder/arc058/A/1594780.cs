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

    List<Tuple<int, int>>[] es;


    int MAX = 10;
    bool[] ngflag;

    int best = 9999999;

    int bestNG = 9999999;

    int N;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        int K = cin.nextInt();
        ngflag = new bool[MAX];
        for (int i = 0; i < K; i++)
        {
            ngflag[cin.nextInt()] = true;
        }

        dfs(0, 0);

        Console.WriteLine(best);
    }

    void dfs(int now, int ng)
    {
        if(now >= N)
        {
            if (bestNG > ng || (bestNG==ng && now < best))
            {
                best = now;
                bestNG = ng;
            }
            return;
        }
        for (int i = 0; i < MAX; i++)
        {
            if (now == 0 && i == 0) continue;
            int next = now * 10 + i;
            int nextNG = ng;
            if (ngflag[i]) nextNG++;
            dfs(next, nextNG);
        }
    }
}


class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' '};

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