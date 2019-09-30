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
        int W = 300000;
        int C = W / 2;

        int[] Lsum = new int[W];
        int[] Rsum = new int[W];
        Lsum[C] = Rsum[C] = 1;

        int[] L = new int[N];
        int[] R = new int[N];
        for (int i = 0; i < N; i++)
        {
            L[i] = cin.nextInt() + C;
            R[i] = cin.nextInt() + C;
            Lsum[L[i]]++; Rsum[R[i]]++;
        }

        for (int i = 1; i < W - 1; i++)
        {
            Rsum[i] += Rsum[i - 1];
            Lsum[W - i - 1] += Lsum[W - i];
        }

        long ans = 0;
        for (int i = 1; i < W - 2; i++)
        {
            ans += Math.Min(Lsum[i + 1], Rsum[i]);
        }

        Console.WriteLine(ans * 2);
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