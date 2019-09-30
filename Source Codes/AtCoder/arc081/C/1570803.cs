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

    long mod = 1000000007;


    void calc()
    {
        cin = new Scanner();

        string S = cin.next();
        int N = S.Length;
        int CMAX = 26;
        
        int[,] next = new int[N + 2, CMAX];

        int[] last = new int[CMAX];
        for (int i = 0; i < last.Length; i++)
        {
            last[i] = N + 1;
        }

        for (int i = N - 1; i >= 0; i--)
        {
            int cnum = (int)(S[i] - 'a');
            for (int j = i + 1; j <= last[cnum]; j++)
            {
                if (j != last[cnum]) next[j, cnum] = last[cnum];
            }
            next[i, cnum] = last[cnum];
            last[cnum] = i + 1;
        }

        for (int c = 0; c < CMAX; c++)
        {
            int cnum = c;
            for (int j = 0; j <= last[cnum]; j++)
            {
                if (j != last[cnum]) next[j, cnum] = last[cnum];
            }
        }


        int[] dist = new int[N + 2];
        for (int i = 0; i < N + 1; i++)
        {
            dist[i] = 9999999;
        }

        for (int i = N; i >= 0; i--)
        {
            for (int j = 0; j < CMAX; j++)
            {
                dist[i] = Math.Min(dist[next[i, j]] + 1, dist[i]);
            }
        }

        int pos = 0;
        StringBuilder sb = new StringBuilder();

        while(pos < N + 1)
        {
            for (int c = 0; c < CMAX; c++)
            {
                char C = (char)('a' + c);

                if (dist[pos] - 1 == dist[next[pos, c]])
                {
                    pos = next[pos, c];
                    sb.Append(C);
                    break;
                }
            }
        }

        Console.WriteLine(sb.ToString());



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