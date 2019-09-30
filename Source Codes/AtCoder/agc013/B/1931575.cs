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


    List<int>[] es;
    bool[] used;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int M = cin.nextInt();
        es = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
        }
        int[] A = new int[M];
        int[] B = new int[M];
        for (int i = 0; i < M; i++)
        {
            A[i] = cin.nextInt() - 1;
            B[i] = cin.nextInt() - 1;
            es[A[i]].Add(B[i]);
            es[B[i]].Add(A[i]);
        }
        l = new List<int>();
        used = new bool[N];

        l = new List<int>();
        bfs(0);
        l.Reverse();
        List<int> L2 = new List<int>(l);
        L2.RemoveAt(L2.Count - 1);
        l = new List<int>();

        bfs(0);
        Console.WriteLine(L2.Count + l.Count);
        foreach (var item in L2)
        {
            Console.Write(item + " ");
        }
        foreach (var item in l)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }

    void bfs(int a)
    {
        while (true)
        {
            int NE = -1;
            used[a] = true;
            l.Add(a + 1);
            foreach (var next in es[a])
            {
                if (used[next]) continue;
                NE = next;
                break;
            }
            if (NE == -1) break;
            a = NE;
        }
    }

    List<int> l;
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