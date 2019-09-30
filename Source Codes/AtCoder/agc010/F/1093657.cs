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
    static Scanner cin;
    public Myon() { }
    public static int Main()
    {
        cin = new Scanner();
        new Myon().calc();
        return 0;
    }

    int N;
    long[] A;
    List<int>[] es;

    public void calc()
    {
        N = cin.nextInt();
        A = new long[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextLong();
        }
        es = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
        }

        for (int i = 0; i < N - 1; i++)
        {
            int a = cin.nextInt() - 1;
            int b = cin.nextInt() - 1;
            es[a].Add(b);
            es[b].Add(a);
        }

        check = new bool[N];
        win = new bool[N];
        for (int i = 0; i < N; i++)
        {
            if (dfs(i)) Console.Write((i + 1) + " ");
        }
        Console.WriteLine();
    }

    bool[] check;
    bool[] win;

    bool dfs(int now)
    {
        long T = A[now];
        check[now] = true;
        foreach (var next in es[now])
        {
            if (A[now] <= A[next]) continue;
            if (!dfs(next))
            {
                win[now] = true;
                return true;
            }
        }
        return false;
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}