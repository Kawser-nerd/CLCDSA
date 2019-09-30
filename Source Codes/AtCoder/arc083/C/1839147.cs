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


    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[] parent = new int[N];
        for (int i = 1; i < N; i++)
        {
            parent[i] = cin.nextInt() - 1;
        }
        int[] weight = new int[N];
        for (int i = 0; i < N; i++)
        {
            weight[i] = cin.nextInt();
        }
        List<int>[] child = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            child[i] = new List<int>();
        }
        for (int i = 1; i < N; i++)
        {
            child[parent[i]].Add(i);
        }

        int MAX = int.MaxValue / 2;

        int[] ans = new int[N];
        for (int i = 0; i < N; i++)
        {
            ans[i] = MAX;
        }


        for (int i = N - 1; i >= 0; i--)
        {
            int[] dp = new int[weight[i] + 1];
            for (int j = 1; j < dp.Length; j++)
            {
                dp[j] = MAX;
            }

            foreach (var c in child[i])
            {
                int[] nextdp = new int[weight[i] + 1];

                for (int j = 0; j < dp.Length; j++)
                {
                    nextdp[j] = MAX;
                }

                for (int j = 0; j < dp.Length; j++)
                {
                    if(j + weight[c] < dp.Length)
                    {
                        nextdp[j + weight[c]] = Math.Min(nextdp[j + weight[c]], dp[j] + ans[c]);
                    }
                    if(j + ans[c] < dp.Length)
                    {
                        nextdp[j + ans[c]] = Math.Min(nextdp[j + ans[c]], dp[j] + weight[c]);
                    }
                }


                dp = nextdp;
            }
            
            for (int j = 0; j < dp.Length; j++)
            {
                ans[i] = Math.Min(ans[i], dp[j]);
            }

            if(ans[i] == MAX)
            {
                Console.WriteLine("IMPOSSIBLE");
                return;
            }
        }

        Console.WriteLine("POSSIBLE");
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