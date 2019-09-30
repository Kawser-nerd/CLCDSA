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
        int H, W, D;
        H = cin.nextInt();
        W = cin.nextInt();
        D = cin.nextInt();

        int[,] A = new int[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                A[i, j] = cin.nextInt() - 1;
            }
        }

        int N = H * W;
        int[] sum = new int[N];
        int[] Y = new int[N];
        int[] X = new int[N];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                X[A[i, j]] = j;
                Y[A[i, j]] = i;
            }
        }

        for (int i = D; i < N; i++)
        {
            sum[i] = sum[i - D] + Math.Abs(X[i] - X[i - D]) + Math.Abs(Y[i] - Y[i - D]);
        }

        int Q = cin.nextInt();
        for (int i = 0; i < Q; i++)
        {
            int L = cin.nextInt() - 1;
            int R = cin.nextInt() - 1;

            Console.WriteLine(sum[R] - sum[L]);
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