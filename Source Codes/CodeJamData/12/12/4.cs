using System;
using System.Collections.Generic;


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
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

}


class Myon
{
    Scanner cin;
    Myon() { }

    public static void Main()
    {
        new Myon().multi();
    }

    void multi()
    {
        int c;
        cin = new Scanner();
        int T = cin.nextInt();
        for (c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }


    void calc()
    {
        Scanner cin = new Scanner();
        int N = cin.nextInt();
        int[,] lev = new int[N, 2];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                lev[i, j] = cin.nextInt();
            }
        }
        int[] memo = new int[N];
        
        int ret = 0;
        int point = 0;
        while (point != N * 2)
        {
            bool flag = false;
            for (int i = 0; i < N; i++)
            {
                if (memo[i] == 2) continue;
                if (lev[i, 1] > point) continue;
                flag = true;
                point += 2 - memo[i];
                memo[i] = 2;
                ret++;
            }
            if (flag) continue;
            int maxlev2 = int.MinValue;
            int maxnum = -1;
            for (int i = 0; i < N; i++)
            {
                if (memo[i] >= 1) continue;
                if (lev[i, 0] > point) continue;
                if (lev[i, 1] > maxlev2)
                {
                    maxlev2 = lev[i, 1];
                    maxnum = i;
                }
            }
            if (maxnum != -1)
            {
                ret++;
                memo[maxnum] = 1;
                point++;
            }
            else
            {
                Console.WriteLine("Too Bad");
                return;
            }
        }
        Console.WriteLine(ret);
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

