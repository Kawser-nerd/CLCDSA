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
        int X = cin.nextInt();
        int K = cin.nextInt();
        int[] r = new int[K + 1];
        for (int i = 0; i < K; i++)
        {
            r[i] = cin.nextInt();
        }
        r[K] = int.MaxValue / 2;
        int Q = cin.nextInt();
        int[] t = new int[Q];
        int[] a = new int[Q];
        for (int i = 0; i < Q; i++)
        {
            t[i] = cin.nextInt();
            a[i] = cin.nextInt();
        }

        int now = 0;

        int leftPoint = 0;
        int leftValue = 0;
        int rightPoint = X;
        int rightValue = X;

        int tp = 0;

        for (int i = 0; i < K + 1; i++)
        {
            while(tp < t.Length && t[tp] <= r[i])
            {
                int nowA;
                if (a[tp] <= leftPoint) nowA = leftValue;
                else if (a[tp] >= rightPoint) nowA = rightValue;
                else nowA = leftValue + (a[tp] - leftPoint);

                if (i % 2 == 0) nowA -= (t[tp] - now);
                else nowA += (t[tp] - now);

                if (nowA < 0) nowA = 0;
                if (nowA > X) nowA = X;

                Console.WriteLine(nowA);
                tp++;
            }

            int move = r[i] - now;

            if (i % 2 == 0) {
                leftValue -= move;
                if (leftValue < 0)
                {
                    leftPoint -= leftValue;
                    leftValue = 0;
                }
                rightValue -= move;
                if (rightValue < 0) rightValue = 0;
            }
            else
            {
                leftValue += move;
                if (leftValue > X)
                {
                    leftValue = X;
                }
                rightValue += move;
                if (rightValue >= X)
                {
                    rightPoint -= (rightValue - X);
                    rightValue = X;
                }
            }
            now = r[i];
            
        }
    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
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