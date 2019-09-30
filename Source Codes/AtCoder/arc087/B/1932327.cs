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
        string S = cin.next();
        List<int>[] l = new List<int>[2];
        l[0] = new List<int>();
        l[1] = new List<int>();
        int id = 0;
        int cnt = 0;
        foreach (var c in S)
        {
            if (c == 'T')
            {
                l[id].Add(cnt);
                cnt = 0; id = 1 - id;
            }
            else cnt++;
        }
        l[id].Add(cnt);
        int x = cin.nextInt();
        int y = cin.nextInt();
        x -= l[0][0];
        List<int> l0 = new List<int>();
        for (int i = 1; i < l[0].Count; i++)
        {
            l0.Add(l[0][i]);
        }
        l[0] = l0;

        if (check(l[0], x) && check(l[1], y)) Console.WriteLine("Yes");
        else Console.WriteLine("No");
    }

    bool check(List<int> l, int target)
    {
        target = Math.Abs(target);
        bool[] check = new bool[target + 1];
        check[0] = true;
        foreach (var item in l)
        {
            if (item == 0) continue;
            bool[] nextcheck = new bool[target + 1];
            for (int i = 0; i < check.Length; i++)
            {
                if (!check[i]) continue;
                int A = i + item;
                int B = Math.Abs(i - item);
                if (A < nextcheck.Length) nextcheck[A] = true;
                if (B < nextcheck.Length) nextcheck[B] = true;
            }
            check = nextcheck;
        }
;
        return check[target];
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