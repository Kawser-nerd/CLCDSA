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

    int N, M;
    List<Tuple<int, int>>[] es;
    int S, T;
    int[] L;
    int[] R;
    int[] D;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        M = cin.nextInt();

        S = cin.nextInt() - 1;
        T = cin.nextInt() - 1;

        es = new List<Tuple<int, int>>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<Tuple<int, int>>();
        }
        L = new int[M];
        R = new int[M];
        D = new int[M];
        for (int i = 0; i < M; i++)
        {
            int l, r, d;
            l = cin.nextInt() - 1;
            r = cin.nextInt() - 1;
            d = cin.nextInt();
            L[i] = l;
            R[i] = r;
            D[i] = d;
            es[l].Add(Tuple.Create(r, d));
            es[r].Add(Tuple.Create(l, d));
        }

        long[] dpS = new long[N];
        long[] dpT = new long[N];
        long[] distS = dijkstra(S, dpS);
        long[] distT = dijkstra(T, dpT);
        bool[] ok = new bool[N];
        for (int i = 0; i < N; i++)
        {
            if (distS[i] + distT[i] == distS[T])
            {
                ok[i] = true;
                //Console.WriteLine("ok " + i + " " + dpS[i] + " " + dpT[i] + " " + distS[i]);
            }
        }

        long ans = dpS[T] * dpT[S] % mod;
        for (int i = 0; i < N; i++)
        {
            if(ok[i] && distS[i] == distT[i])
            {
                long tmp = dpS[i] * dpT[i] % mod;
                tmp = tmp * tmp % mod;
                ans -= tmp;
                if (ans < 0) ans += mod;
            }
        }

        for (int i = 0; i < M; i++)
        {
            //break;
            int a = L[i];
            int b = R[i];
            if (ok[a] && ok[b])
            {
                if (distS[a] > distS[b]) swap(ref a, ref b);
                if (distS[a] == distT[a]) continue;
                if (distS[b] == distT[b]) continue;
                if (distS[a] + D[i] != distS[b]) continue;
                if (distT[b] + D[i] != distT[a]) continue;
                if ((distS[a] < distT[a]) != (distS[b] < distT[b]))
                {
                    long tmp = dpS[a] * dpT[b] % mod;
                    tmp = tmp * tmp % mod;
                    ans -= tmp;
                    if (ans < 0) ans += mod;
                }
            }
        }
        //ans %= mod;
        //ans += mod;
        //ans %= mod;
        Console.WriteLine(ans);
    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
    } 

    long mod = 1000000007;


    long[] dijkstra(int start, long[] DP)
    {
        long[] dist = new long[N];
        long MAX = long.MaxValue / 2;
        for (int i = 0; i < N; i++)
        {
            dist[i] = MAX;
        }
        dist[start] = 0;
        DP[start] = 1;
        Heap<Tuple<long, int>> h = new Heap<Tuple<long, int>>(); //cost, pos
        h.push(Tuple.Create(0L, start));

        while (h.top != null)
        {
            var now = h.pop();
            int nowp = now.Item2;
            long nowcost = now.Item1;
            if (nowcost > dist[nowp]) continue;
            //Console.WriteLine(nowp + " " + nowcost);

            foreach (var next in es[nowp])
            {
                int nextp = next.Item1;
                long nextcost = nowcost + next.Item2;
                if(dist[nextp] > nextcost)
                {
                    dist[nextp] = nextcost;
                    DP[nextp] = DP[nowp];

                    h.push(Tuple.Create(nextcost, nextp));
                }
                else if(dist[nextp] == nextcost)
                {
                    DP[nextp] += DP[nowp];
                    if (DP[nextp] >= mod) DP[nextp] -= mod;
                }
            }
        }
        return dist;
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