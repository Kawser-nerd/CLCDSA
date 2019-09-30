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
        long mod = cin.nextLong();
        long[,] mulDP = new long[N + 2, N + 1]; //exist-1, add
        long[,] dp = new long[K + 1, N + 1]; //color, num

        mulDP[0, 0] = 1;
        for (int i = 1; i <= N + 1; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                long mul = 1;
                for (int k = 0; k <= j; k++)
                {
                    mulDP[i, j] += mulDP[i - 1, j - k] * mul;
                    mulDP[i, j] %= mod;
                    mul *= i;
                    mul %= mod;
                }
            }
        }
        /*
        for (int i = 0; i < N + 2; i++)
        {
            for (int j = 0; j < N + 1; j++)
            {
                Console.Write(mulDP[i,j] + " ");
            }
            Console.WriteLine();
        }
        */

        dp[0, 0] = 1;
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                for (int k = 0; j + k <= N; k++)
                {
                    dp[i + 1, j + k] += dp[i, j] * mulDP[j + 1, k];
                    dp[i + 1, j + k] %= mod;
                }
            }
        }

        /*
        for (int i = 0; i < K + 1; i++)
        {
            for (int j = 0; j < N + 1; j++)
            {
                Console.Write(dp[i,j] + " ");
            }
            Console.WriteLine();
        }
        */

        Console.WriteLine(dp[K, N]);
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