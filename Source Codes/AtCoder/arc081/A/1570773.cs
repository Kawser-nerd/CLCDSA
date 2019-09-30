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
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int N = cin.nextInt();
        int[] A = cin.ArrayInt(N);

        for (int i = 0; i < N; i++)
        {
            if (!dic.ContainsKey(A[i])) dic[A[i]] = 0;
            dic[A[i]]++;
        }

        long ans = 0;
        List<int> l = new List<int>();
        foreach (var item in dic)
        {
            if (item.Value < 2) continue;
            l.Add(item.Key);
        }
        l.Sort();
        l.Reverse();
        if(l.Count >= 2)
        {
            ans = (long)l[0] * l[1];
        }

        foreach (var item in dic)
        {
            if (item.Value < 4) continue;
            ans = Math.Max(ans, item.Key * (long)item.Key);
        }

        Console.WriteLine(ans);
    }


    class Heap<T> where T : IComparable
    {
        public HeapNode<T> top;

        public Heap() { }

        public void push(T val)
        {
            top = HeapNode<T>.meld(top, new HeapNode<T>(val));
        }

        public T pop()
        {
            T ret = top.val;
            top = HeapNode<T>.meld(top.r, top.l);
            return ret;
        }

        public void merge(Heap<T> h2)
        {
            top = HeapNode<T>.meld(top, h2.top);
        }

        public class HeapNode<NT> where NT : IComparable
        {
            public HeapNode<NT> l, r;
            public NT val;

            public HeapNode(NT _val)
            {
                val = _val;
            }

            public static HeapNode<NT> meld(HeapNode<NT> a, HeapNode<NT> b)
            {
                if (a == null) return b;
                if (b == null) return a;
                if (a.val.CompareTo(b.val) > 0)
                {
                    HeapNode<NT> temp = a;
                    a = b;
                    b = temp;
                }
                a.r = meld(a.r, b);
                HeapNode<NT> temph = a.l;
                a.l = a.r;
                a.r = temph;
                return a;
            }
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