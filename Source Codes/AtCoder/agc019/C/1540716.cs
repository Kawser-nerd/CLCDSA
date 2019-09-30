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
        int x1, y1, x2, y2;
        x1 = cin.nextInt();
        y1 = cin.nextInt();
        x2 = cin.nextInt();
        y2 = cin.nextInt();

        if(x1 > x2 || (x1 == x2 && y1 > y2))
        {
            swap(ref x1, ref x2);
            swap(ref y1, ref y2);
        }

        bool yflag = false;
        if(y1 > y2)
        {
            yflag = true;
            swap(ref y1, ref y2);
        }

        int N = cin.nextInt();
        List<long> l = new List<long>();

        for (int i = 0; i < N; i++)
        {
            int x = cin.nextInt();
            int y = cin.nextInt();
            if (yflag)
            {
                y = y1 + (y2 - y);
            }

            if (x < x1 || x > x2) continue;
            if (y < y1 || y > y2) continue;
            l.Add(((long)x << 32) + y);
        }

        long[] dp = new long[N + 1];
        long MAX = long.MaxValue / 2;
        for (int i = 0; i < N + 1; i++)
        {
            dp[i] = MAX;
        }
        dp[0] = -1;

        l.Sort();

        foreach (var now in l)
        {
            int y = (int)(now & 0xFFFFFFFF);
            int ok = 0;
            int ng = N + 1;
            while(ok + 1 < ng)
            {
                int mid = (ok + ng) / 2;
                if (dp[mid] <= y) ok = mid;
                else ng = mid;
            }
            dp[ng] = y;
        }

        int cnt = 0;
        for (int i = 0; i < N + 1; i++)
        {
            if (dp[i] != MAX) cnt = i;
        }

        double ans = 100L * ((x2 - x1) + (y2 - y1));
        ans -= 20 * cnt;
        ans += Math.PI * 5 * cnt;
        if (cnt == Math.Min(x2 - x1, y2 - y1) + 1) ans += Math.PI * 5 * 1;

        Console.WriteLine("{0:0.0000000000000000}", ans);
    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
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