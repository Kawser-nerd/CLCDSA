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

    int C = 52;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[] A = cin.ArrayInt(N);
        int[] B = cin.ArrayInt(N);


        long result = (1L << C) - 1;
        for (int i = 0; i < N; i++)
        {
            if(!check(result, A[i], B[i]))
            {
                Console.WriteLine(-1);
                return;
            }
        }

        for (int i = C - 1; i >= 0; i--)
        {
            long next = result - (1L << i);
            bool flag = true;
            for (int j = 0; j < N; j++)
            {
                if (!check(next, A[j], B[j]))
                {
                    flag = false;
                    break;
                }
            }

            if (flag) result = next;
        }

        Console.WriteLine(result * 2);
    }

    bool check(long flag, int a, int b)
    {
        bool[] ok = new bool[C];
        ok[a] = true;
        for (int i = C - 1; i >= 0; i--)
        {
            if ((flag >> i) % 2 == 0) continue;
            for (int j = i; j < C; j++)
            {
                if(ok[j]) ok[j % (i + 1)] = true;
            }
            if (ok[b]) return true;
        }
        if (ok[b]) return true;
        return false;
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