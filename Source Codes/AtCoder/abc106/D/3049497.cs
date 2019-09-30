using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;

class Iroha
{
    public Iroha() { }
    public static int Main()
    {
        new Iroha().calc();
        return 0;
    }

    Scanner cin;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int M = cin.nextInt();
        int Q = cin.nextInt();
        int[] L = new int[M];
        int[] R = new int[M];
        for (int i = 0; i < M; i++)
        {
            L[i] = cin.nextInt();
            R[i] = cin.nextInt();
        }
        int[] p = new int[Q];
        int[] q = new int[Q];
        for (int i = 0; i < Q; i++)
        {
            p[i] = cin.nextInt();
            q[i] = cin.nextInt();
        }

        int[,] sum = new int[N + 1, N + 1];
        for (int i = 0; i < M; i++)
        {
            sum[L[i], R[i]]++;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                sum[i + 1, j + 1] += sum[i + 1, j];
                sum[i + 1, j + 1] += sum[i, j + 1];
                sum[i + 1, j + 1] -= sum[i, j];
            }
        }

        for (int i = 0; i < Q; i++)
        {
            Console.WriteLine(sum[q[i], q[i]] - sum[p[i] - 1, q[i]]);
        }
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