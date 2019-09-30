using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static Scanner cin = new Scanner();

    static void Main(string[] args) {
        const int INF = (int)1e9;
        int N = cin.Int();
        var h = cin.ArrayInt(N);

        var dp = new int[N];
        for (int i = 0; i < N; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;
        dp[1] = Math.Abs(h[1] - h[0]);
        for (int i = 2; i < N; i++) {
            dp[i] = Math.Min(dp[i - 2] + Math.Abs(h[i] - h[i - 2]), dp[i - 1] + Math.Abs(h[i] - h[i - 1]));
        }
        Console.WriteLine(dp[N - 1]);
        Console.ReadLine();
    }
}

class Scanner //????
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

    public int Int()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Int() + add;
        }
        return Array;
    }

    public long Long()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Long() + add;
        }
        return Array;
    }

    public double Double()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Double() + add;
        }
        return Array;
    }
}