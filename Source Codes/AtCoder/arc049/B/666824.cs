using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;

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
        int[] c = new int[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextInt();
            y[i] = cin.nextInt();
            c[i] = cin.nextInt();
        }

        double ok = 1e15; 
        // ???? 100000 - (-100,000) = 200000
        // ???? 1?????1000
        //????????????
        double ng = 0;
        for (int loop = 0; loop < 100; loop++)
        {
            double mid = (ok + ng) / 2;

            double R = double.MaxValue;
            double L = double.MinValue;
            double U = double.MaxValue;
            double D = double.MinValue;
            for (int i = 0; i < N; i++)
            {
                R = Math.Min(R, x[i] + mid / c[i]);
                L = Math.Max(L, x[i] - mid / c[i]);
                U = Math.Min(U, y[i] + mid / c[i]);
                D = Math.Max(D, y[i] - mid / c[i]);
            }

            if (R >= L && U >= D)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        Console.WriteLine("{0:0.000000000000}", ok);
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
        i = 0;
        return next();
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}