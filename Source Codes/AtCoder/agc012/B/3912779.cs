using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



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
        int M = cin.nextInt();
        es = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
        }

        for (int i = 0; i < M; i++)
        {
            int A = cin.nextInt() - 1;
            int B = cin.nextInt() - 1;
            es[A].Add(B);
            es[B].Add(A);
        }

        int Q = cin.nextInt();
        int[] v = new int[Q];
        int[] d = new int[Q];
        int[] c = new int[Q];
        for (int i = 0; i < Q; i++)
        {
            v[i] = cin.nextInt() - 1;
            d[i] = cin.nextInt();
            c[i] = cin.nextInt();
        }

        int MAXD = 11;
        int[,] dp = new int[N, MAXD];

        for (int i = 0; i < Q; i++)
        {
            dp[v[i], d[i]] = i + 1;
        }

        for (int i = MAXD - 1; i >= 1; i--)
        {
            for (int j = 0; j < N; j++)
            {
                if (dp[j, i] == 0) continue;
                foreach (var next in es[j])
                {
                    dp[next, i - 1] = Math.Max(dp[j, i], dp[next, i - 1]);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            int MAXID = 0;
            for (int j = 0; j < MAXD; j++)
            {
                MAXID = Math.Max(MAXID, dp[i, j]);
            }
            if (MAXID == 0) Console.WriteLine(0);
            else Console.WriteLine(c[MAXID - 1]);
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