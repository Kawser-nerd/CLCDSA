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

    int[] A, B, C;
    int N;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        A = cin.ArrayInt(N);
        B = cin.ArrayInt(N);
        C = cin.ArrayInt(N);
        dicB = new long[N];
        dicB2 = new int[N];
        dicC = new long[N];
        Array.Sort(A);
        Array.Sort(B);
        Array.Sort(C);
        Array.Reverse(A);
        Array.Reverse(B);
        Array.Reverse(C);
        for (int i = 0; i < N; i++)
        {
            dicB[i] = dicC[i] = -1;
        }
        long ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans += dfsB(i);
        }
        Console.WriteLine(ans);
    }

    long[] dicB;
    int[] dicB2;
    long[] dicC;

    long dfsB(int aid)
    {
        if (dicB[aid] != -1) return dicB[aid];
        long ans = 0;
        int cnt = 0;
        if (aid != 0)
        {
            ans = dfsB(aid - 1);
            cnt = dicB2[aid - 1];
        }

        while (cnt < N)
        {
            if (B[cnt] <= A[aid]) break;
            ans += dfsC(cnt);
            cnt++;
        }
        
        dicB2[aid] = cnt;
        return dicB[aid] = ans;
    }

    long dfsC(int bid)
    {
        if (dicC[bid] != -1) return dicC[bid];
        int cnt = 0;
        if (bid != 0)
        {
            cnt = (int)dfsC(bid - 1);
        }
        while (cnt < N)
        {
            if (C[cnt] <= B[bid]) break;
            cnt++;
        }
        return dicC[bid] = cnt;
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