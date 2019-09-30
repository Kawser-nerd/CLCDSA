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
        int[] t = cin.ArrayInt(N);
        int[] v = cin.ArrayInt(N);
        int sumT = t.Sum() * 2;
        double[] V = new double[sumT + 1];
        int now = 0;
        for (int i = 1; i < sumT; i++)
        {
            V[i] = 99999999;
        }
        for (int i = 0; i < N; i++)
        {
            int next = now + t[i] * 2;
            for (int j = now; j <= next; j++)
            {
                V[j] = Math.Min(V[j], v[i]);
            }
            now = next;
        }

        for (int i = 1; i <= sumT; i++)
        {
            V[i] = Math.Min(V[i - 1] + 0.5, V[i]);
        }

        for (int i = sumT - 1; i >= 0; i--)
        {
            V[i] = Math.Min(V[i + 1] + 0.5, V[i]);
        }
        double ans = 0;
        for (int i = 0; i < sumT; i++)
        {
            ans += (V[i] + V[i + 1]) / 2;
        }
        Console.WriteLine(ans / 2);
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