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

    List<int>[] es;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int A = cin.nextInt();

        long[] dp = new long[10000];
        dp[5000] = 1;
        for (int i = 0; i < N; i++)
        {
            int diff = cin.nextInt() - A;
            long[] nextdp = (long[])dp.Clone();
            for (int j = 0; j < 10000; j++)
            {
                if (dp[j] == 0) continue;
                nextdp[j + diff] += dp[j];
            }
            dp = nextdp;
        }
        Console.WriteLine(dp[5000] - 1);
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