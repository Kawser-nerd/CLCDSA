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
    

    string pos = "Possible";
    string imp = "Impossible";

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[] A = cin.ArrayInt(N);
        long best = long.MaxValue;
        for (int i = 0; i < 2; i++)
        {
            long tmp = 0;
            long sum = 0;
            for (int j = 0; j < N; j++)
            {
                sum += A[j];
                if (j % 2 == i)
                {
                    if(sum < 1)
                    {
                        tmp += 1 - sum;
                        sum = 1;
                    }
                }
                else
                {
                    if(sum > -1)
                    {
                        tmp += sum - (-1);
                        sum = -1;
                    }
                }
            }
            best = Math.Min(best, tmp);
        }
        Console.WriteLine(best);
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