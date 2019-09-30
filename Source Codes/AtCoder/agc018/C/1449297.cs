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
        int X, Y, Z;
        X = cin.nextInt();
        Y = cin.nextInt();
        Z = cin.nextInt();
        int N = X + Y + Z;
        int[] A, B, C;
        long ans = 0;
        A = new int[N];
        B = new int[N];
        C = new int[N];

        int MAX = (int)2e9 + 1;

        Heap<Tuple<int, int>> HX = new Heap<Tuple<int, int>>();
        Heap<Tuple<int, int>> HY = new Heap<Tuple<int, int>>();

        bool[] used = new bool[N + 1];

        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextInt();
            B[i] = cin.nextInt();
            C[i] = cin.nextInt();
            ans += C[i];
            A[i] -= C[i];
            B[i] -= C[i];
            HX.push(Tuple.Create(A[i], i));
            HY.push(Tuple.Create(B[i], i));
        }

        Heap<Tuple<int, int>> HXtoY = new Heap<Tuple<int, int>>();
        Heap<Tuple<int, int>> HYtoX = new Heap<Tuple<int, int>>();
        HX.push(Tuple.Create(-MAX, N));
        HY.push(Tuple.Create(-MAX, N));
        HXtoY.push(Tuple.Create(-MAX, N));
        HYtoX.push(Tuple.Create(-MAX, N));

        int cntX = 0;
        int cntY = 0;

        while(cntX != X || cntY != Y)
        {
            while (HX.top != null && used[HX.top.val.Item2]) HX.pop();
            while (HY.top != null && used[HY.top.val.Item2]) HY.pop();
            long x = HX.top.val.Item1;
            long y = HY.top.val.Item1;
            long xy = (long)HXtoY.top.val.Item1 + x;
            long yx = (long)HYtoX.top.val.Item1 + y;
            if (cntX == X)
            {
                x = -MAX;
                yx = -MAX;
            }
            else xy = -MAX;
            if (cntY == Y)
            {
                y = -MAX;
                xy = -MAX;
            }
            else yx = -MAX;

            long max = Math.Max(Math.Max(x, y), Math.Max(xy, yx));

            if(x == max)
            {
                int id = HX.pop().Item2;
                used[id] = true;
                ans += A[id];
                HXtoY.push(Tuple.Create(B[id] - A[id], id));
                cntX++;
                continue;
            }
            if(y == max)
            {
                int id = HY.pop().Item2;
                used[id] = true;
                ans += B[id];
                HYtoX.push(Tuple.Create(A[id] - B[id], id));
                cntY++;
                continue;
            }
            if(xy == max)
            {
                int id = HXtoY.pop().Item2;
                ans -= A[id];
                ans += B[id];
                cntX--;
                cntY++;
                HYtoX.push(Tuple.Create(A[id] - B[id], id));
                continue;
            }
            if(yx == max)
            {
                int id = HYtoX.pop().Item2;
                ans -= B[id];
                ans += A[id];
                cntY--;
                cntX++;
                HXtoY.push(Tuple.Create(B[id] - A[id], id));
                continue;
            }
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
                if (a.val.CompareTo(b.val) < 0)
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
        i = 0;
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