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
        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextInt();
            y[i] = cin.nextInt();
        }

        long ans = 0;
        long mod = 998244353;

        int MAX2 = 300;
        long[] pow2 = new long[MAX2];
        pow2[0] = 0;
        pow2[1] = 1;
        for (int i = 2; i < MAX2; i++)
        {
            pow2[i] = (pow2[i - 1] * 2 + 1) % mod;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                long cnt = 0;
                long cnt2 = 0;
                for (int k = j + 1; k < N; k++)
                {
                    cnt++;
                    if (calcT(x[i] - x[k], y[i] - y[k], x[j] - x[k], y[j] - y[k]) == 0)
                    {
                        cnt2++;
                    }
                }

                ans += pow2[cnt];
                ans -= pow2[cnt2];
                ans %= mod;
                ans += mod;
                ans %= mod;
            }
        }
        Console.WriteLine(ans);
    }

    long calcT(long ax, long ay, long bx, long by)
    {
        return (ax * by) - (bx * ay);
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