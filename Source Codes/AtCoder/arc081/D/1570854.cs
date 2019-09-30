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


    int H, W;

    void calc()
    {
        cin = new Scanner();
        H = cin.nextInt();
        W = cin.nextInt();

        int ans = 0;
        string[] S = new string[H];
        for (int i = 0; i < H; i++)
        {
            S[i] = cin.next();
        }
        ans = Math.Max(ans, calc2(S));

        for (int i = 0; i < H; i++)
        {
            S[i] = rev(S[i]);
        }
        ans = Math.Max(ans, calc2(S));
        
        for (int i = 0; i < H / 2; i++)
        {
            swap(ref S[i], ref S[H - 1 - i]);
        }
        ans = Math.Max(ans, calc2(S));
        
        for (int i = 0; i < H; i++)
        {
            S[i] = rev(S[i]);
        }
        ans = Math.Max(ans, calc2(S));

        Console.WriteLine(ans);
    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
    } 

    string rev(string S)
    {
        StringBuilder sb = new StringBuilder();
        for (int i = S.Length - 1; i >= 0; i--)
        {
            sb.Append(S[i]);
        }
        return sb.ToString();
    }

    int calc2(string[] S)
    {
        int[,] board = new int[H, W];

        for (int y = 1; y < H; y++)
        {
            for (int x = 1; x < W; x++)
            {
                if ((S[y - 1][x - 1] == S[y - 1][x]) != (S[y][x - 1] == S[y][x]))
                {
                    board[y, x] = 1;
                }
            }
        }

        int[,] dist = new int[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (i == 0) dist[i, j] = 1;
                else
                {
                    if (board[i, j] == 1) dist[i, j] = 0;
                    else
                    {
                        dist[i, j] = dist[i - 1, j] + 1;
                    }
                }
            }
        }

        /*
        for (int i = 0; i < H; i++)
        {
            Console.WriteLine(S[i]);
        }

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (dist[i, j] == 0) Console.Write('-');
                else Console.Write(dist[i, j] % 10);
            }
            Console.WriteLine();
        }
        */

        int ans = Math.Max(H, W);

        for (int i = 0; i < H; i++)
        {
            //pos, num
            Stack<Tuple<int, int>> t = new Stack<Tuple<int, int>>();
            for (int j = 0; j < W; j++)
            {
                int num = dist[i, j] + 1;
                if (num > i + 1) num = i + 1;

                int left = j - 1;
                while (t.Count != 0 && t.Peek().Item2 > num)
                {
                    var now = t.Pop();
                    //Console.WriteLine(i + " " + j + " " + ((j + 1 - now.Item1) * now.Item2));
                    ans = Math.Max(ans, (j - now.Item1) * now.Item2);
                    left = Math.Min(now.Item1, left);
                }
                if (t.Count == 0 || t.Peek().Item2 != num)
                {
                    t.Push(Tuple.Create(Math.Max(0, left), num));
                }
            }

            while (t.Count != 0)
            {
                var now = t.Pop();
                ans = Math.Max(ans, (W - now.Item1) * now.Item2);
            }
        }
        //Console.WriteLine(ans);
        return ans;
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