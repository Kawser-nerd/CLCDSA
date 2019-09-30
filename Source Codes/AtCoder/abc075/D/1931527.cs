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
        int K = cin.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextInt();
            y[i] = cin.nextInt();
        }

        long ans = long.MaxValue;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    for (int l = 0; l < N; l++)
                    {
                        int minx = x[i];
                        int miny = y[j];
                        int maxx = x[k];
                        int maxy = y[l];
                        if (minx > maxx) continue;
                        if (miny > maxy) continue;
                        long S = (long)(maxx - minx) * (long)(maxy - miny);
                        if (ans <= S) continue;

                        int tmp = 0;
                        for (int p = 0; p < N; p++)
                        {
                            if (x[p] <= maxx && x[p] >= minx && y[p] <= maxy && y[p] >= miny) tmp++;
                        }
                        if (tmp >= K) ans = S;
                    }
                }
            }
        }
        Console.WriteLine(ans);
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