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
        int A, B, C, D, E, F;
        A = cin.nextInt();
        B = cin.nextInt();
        C = cin.nextInt();
        D = cin.nextInt();
        E = cin.nextInt();
        F = cin.nextInt();
        
        int[] dp = new int[F + 1];
        for (int i = 0; i < F + 1; i++)
        {
            if (dp[i] != i) continue;
            if (dp[i] + C <= F) dp[i + C] = i + C;
            if (dp[i] + D <= F) dp[i + D] = i + D;
        }

        for (int i = 1; i < F + 1; i++)
        {
            dp[i] = Math.Max(dp[i], dp[i - 1]);
        }

        long AnsAll = A * 100;
        long AnsSalt = 0;

        for (int i = 0; i < 31; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                int Water = A * 100 * i + B * 100 * j;
                if (Water > F) continue;
                int MaxSalt = Math.Min(F - Water, Water / 100 * E);
                int Salt = dp[MaxSalt];
                int Sum = Water + Salt;
                if(AnsSalt * Sum < Salt * AnsAll)
                {
                    AnsAll = Sum;
                    AnsSalt = Salt;
                }
            }
        }
        Console.WriteLine(AnsAll + " " + AnsSalt);
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