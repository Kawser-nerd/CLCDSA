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
        long A = cin.nextLong();
        long B = cin.nextLong();
        if (Math.Abs(A - B) <= 1) Console.WriteLine("Brown");
        else Console.WriteLine("Alice");

    }
    /*
    int[,] check = new int[30, 30];

    int dfs(int a, int b)
    {
        if (check[a, b] != 0) return check[a, b] - 1;
        check[a, b] = 1;
        for (int A = 2; A <= a; A += 2)
        {
            if(dfs(a - A, b + A / 2) == 0)
            {
                check[a, b] = 2;
                return 1;
            }
        }


        for (int B = 2; B <= b; B += 2)
        {
            if (dfs(a + B / 2, b - B) == 0)
            {
                check[a, b] = 2;
                return 1;
            }
        }
        return 0;
    }
    */
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