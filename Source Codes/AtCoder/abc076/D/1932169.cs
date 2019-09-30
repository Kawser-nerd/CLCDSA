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
        int[] T = cin.ArrayInt(N);
        int[] V = cin.ArrayInt(N);
        int sumT = T.Sum() * 2;
        double[] v = new double[sumT + 1];
        for (int i = 0; i < v.Length; i++)
        {
            v[i] = 1e30;
        }
        v[0] = 0;
        v[sumT] = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < T[i] * 2; j++)
            {
                v[cnt] = Math.Min(v[cnt], V[i]);
                cnt++;
                v[cnt] = Math.Min(v[cnt], V[i]);
            }
        }

        for (int i = 1; i < v.Length - 1; i++)
        {
            v[i] = Math.Min(v[i], v[i - 1] + 0.5);
            v[i] = Math.Min(v[i], v[i + 1] + 0.5);
        }
        for (int i = v.Length - 2; i >= 1; i--)
        {
            v[i] = Math.Min(v[i], v[i - 1] + 0.5);
            v[i] = Math.Min(v[i], v[i + 1] + 0.5);
        }
        

        double ans = 0;
        for (int i = 0; i < sumT; i++)
        {
            ans += (v[i] + v[i + 1]) / 4;
        }
        Console.WriteLine("{0:0.000000000000000000}", ans);
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