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
        cin = new Scanner();
        int H, W, N;
        H = cin.nextInt();
        W = cin.nextInt();
        N = cin.nextInt();
        int[] Y = new int[N];
        int[] X = new int[N];

        long[] XY = new long[N];

        int[] p = new int[W];
        p[0] = 1;

        for (int i = 0; i < N; i++)
        {
            Y[i] = cin.nextInt() - 1;
            X[i] = cin.nextInt() - 1;
            XY[i] = ((long)X[i] << 32) + Y[i];
        }

        Array.Sort(XY);

        int ans = H;

        int nowx = 0;
        for (int i = 0; i < N; i++)
        {
            int x = (int)(XY[i] >> 32);
            int y = (int)(XY[i] & 0xFFFFFFFF);

            //Console.WriteLine(y + " " + x);
            while(x >= nowx + 2)
            {
                nowx++;
                p[nowx] = p[nowx - 1] + 1;
            }
            if (x == nowx + 1 && y == p[nowx]) p[nowx]++;
        }

        for (int i = 1; i < W; i++)
        {
            p[i] = Math.Max(p[i - 1] + 1, p[i]);
        }

        for (int i = 0; i < N; i++)
        {
            if (Y[i] >= p[X[i]]) ans = Math.Min(ans, Y[i]);

            //Console.WriteLine(X[i] + " " + Y[i] + " " + p[X[i]]);
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