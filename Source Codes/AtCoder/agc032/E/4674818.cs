using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
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


    int[] A;
    int N, M;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        M = cin.nextInt();

        N *= 2;
        A = cin.ArrayInt(N);
        Array.Sort(A);

        int MaxA = 0;
        int ok = 0;
        int ng = N / 2 + 1;
        while (Math.Abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;
            if (check(mid)) ok = mid;
            else ng = mid;
        }


        int ans = 0;
        for (int i = 0; i < N / 2 - ok; i++)
        {
            ans = Math.Max(ans, A[i] + A[N - ok * 2 - 1 - i]);
        }
        for (int i = 0; i < ok; i++)
        {
            ans = Math.Max(ans, A[N - 1 - i] + A[N - ok * 2 + i] - M);
        }

        Console.WriteLine(ans);
    }

    bool check(int p)
    {
        for (int i = 0; i < p; i++)
        {
            if (A[N - 1 - i] + A[N - 2 * p + i] < M) return false;
        }
        return true;
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