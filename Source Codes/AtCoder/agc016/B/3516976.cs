using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



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
        if (calc2()) Console.WriteLine("Yes");
        else Console.WriteLine("No");
    }

    bool calc2()
    {

        cin = new Scanner();
        int N = cin.nextInt();
        int[] a = cin.ArrayInt(N);
        Array.Sort(a);
        int min = a[0];
        int max = a[N - 1];

        if (max - min >= 2) return false;

        if(min == max)
        {
            if (max == N - 1) return true; //????
            else min--;  //???????2??
        }

        int mincnt = 0;
        int maxcnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (a[i] == min) mincnt++;
            else maxcnt++;
        }

        if (maxcnt == 1) return false; //2????????1????????

        int minPattern = mincnt + 1; //mincnt, maxcnt??????????????????????
        int maxPattern = mincnt + maxcnt / 2;   //???????

        if (max >= minPattern && max <= maxPattern) return true;
        else return false;
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