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
        Tuple<int, int>[] tpy = new Tuple<int, int>[N];
        Tuple<int, int>[] tpx = new Tuple<int, int>[N];
        for (int i = 0; i < N; i++)
        {
            int x = cin.nextInt();
            int y = cin.nextInt();
            tpy[i] = Tuple.Create(y, i);
            tpx[i] = Tuple.Create(x, i);
        }
        Array.Sort(tpy);
        Array.Sort(tpx);

        List<Tuple<int, int, int>> l = new List<Tuple<int,int,int>>();
        for (int i = 0; i < N-1; i++)
        {
            l.Add(Tuple.Create(tpy[i + 1].Item1 - tpy[i].Item1, tpy[i + 1].Item2, tpy[i].Item2));
            l.Add(Tuple.Create(tpx[i + 1].Item1 - tpx[i].Item1, tpx[i + 1].Item2, tpx[i].Item2));
        }
        l.Sort();
        long ans = 0;
        init(N);
        foreach (var item in l)
        {
            int a = item.Item2;
            int b = item.Item3;
            if (connect(a, b))
            {
                ans += item.Item1;
            }
        }
        Console.WriteLine(ans);
    }

    int[] uni;
    void init(int N)
    {
        uni = new int[N];
        for (int i = 0; i < N; i++)
        {
            uni[i] = -1;
        }
    }

    int root(int a)
    {
        if (uni[a] < 0) return a;
        else return uni[a] = root(uni[a]);
    }

    bool connect(int a, int b)
    {
        a = root(a);
        b = root(b);
        if (a == b) return false;
        if (uni[a] > uni[b]) swap(ref a, ref b);
        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }

    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
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