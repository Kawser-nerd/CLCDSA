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

    bool isPrime(long a)
    {
        if (a < 2) return false;
        long i;
        for (i = 2; i * i <= a; i++)
        {
            if (a % i == 0) return false;
        }
        return true;
    }


    List<int>[] es;
    int[] A;
    int[] d;
    int[] dp;
    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int K = cin.nextInt();
        A = cin.ArrayInt(N, -1);
        d = new int[N];
        for (int i = 0; i < N; i++)
        {
            d[i] = -1;
        }
        es = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
        }
        for (int i = 0; i < N; i++)
        {
            es[A[i]].Add(i);
        }

        dfs(0, 0);

        int ans = 0;
        long[] ar = new long[N];
        for (int i = 0; i < N; i++)
        {
            ar[i] = ((long)d[i] << 20) + i;
        }
        Array.Sort(ar);
        Array.Reverse(ar);

        dp = new int[N];

        foreach (var item in ar)
        {
            int now = (int)(item & ((1 << 20) - 1));

            if (dp[now] >= K - 1)
            {
                if (A[now] != 0)
                {
                    ans++;
                    A[now] = 0;
                }
            }
            else
            {
                dp[A[now]] = Math.Max(dp[A[now]], dp[now] + 1);
            }
        }

        if (A[0] != 0) ans++;

        Console.WriteLine(ans);
    }

    void dfs(int now, int depth)
    {
        if (d[now] != -1) return;
        d[now] = depth;
        foreach (var next in es[now])
        {
            dfs(next, depth + 1);
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