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
        int[] x = new int[N];
        int[] y = new int[N];
        double[] ans = new double[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextInt();
            y[i] = cin.nextInt();
        }
        const int MAX = 250000;
        for (int i = 0; i < MAX; i++)
        {
            double best = -1e300;
            int p = 0;
            double r = Math.PI * 2 / MAX * i;
            for (int j = 0; j < N; j++)
            {
                double dist = Math.Sin(r) * x[j] + Math.Cos(r) * y[j];
                if(best < dist)
                {
                    p = j;
                    best = dist;
                }
            }
            ans[p] += 1.0 / MAX;
        }

        for (int i = 0; i < N; i++)
        {
            Console.WriteLine("{0:0.00000000000}", ans[i]);
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