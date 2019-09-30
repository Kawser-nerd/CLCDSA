using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";

    struct Edge : IComparable<Edge>
    {
        public int a, b, min;
        public Edge(int a, int b, int min)
        {
            this.a = a;
            this.b = b;
            this.min = min;
        }
        public int CompareTo(Edge c)
        {
            return c.min.CompareTo(min);
        }
    }

    int N, n;
    int[] P, B;
    RMQ R, L;
    void Solve()
    {
        N = cin.Nextint;
        P = cin.Scanint;
        B = new int[200001];
        for (int i = 0; i < N; i++)
        {
            B[P[i]] = i;
        }
        n = 1;
        while (n < N) n *= 2;
        R = new RMQ(n);
        L = new RMQ(n);
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0) R.update(i, P[i]);
            else L.update(i, P[i]);
        }
        var G = new PriorityQueue<Edge>();
        G.Enqueue(new Edge(0, N, R.query(0, N, 0, 0, n)));
        while (G.Any())
        {
            var v = G.Dequeue();
            if (v.a == v.b) continue;
            int max = v.min;
            int s = B[max];
            int right = calc(s + 1, v.b);
            int t = B[right];
            Write($"{max} {right} ");
            G.Enqueue(new Edge(v.a, s, calc(v.a, s)));
            G.Enqueue(new Edge(s + 1, t, calc(s + 1, t)));
            G.Enqueue(new Edge(t + 1, v.b, calc(t + 1, v.b)));
        }
        WriteLine();
    }
    int calc(int a, int b)
    {
        return (a % 2 == 0) ? R.query(a, b, 0, 0, n) : L.query(a, b, 0, 0, n);
    }
}


class PriorityQueue<T> where T : IComparable<T>
{
    List<T> heap;
    int size;
    int Compare(T x, T y) { return y.CompareTo(x); }
    public PriorityQueue() { heap = new List<T>(); }

    public void Enqueue(T x)
    {
        heap.Add(x);
        int i = size++;

        while (i > 0)
        {
            int p = (i - 1) >> 1;

            if (Compare(heap[p], x) <= 0) break;

            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    public T Dequeue()
    {
        T ret = heap[0];
        T x = heap[--size];

        int i = 0;
        while ((i << 1) + 1 < size)
        {
            int a = (i << 1) + 1;
            int b = (i << 1) + 2;

            if (b < size && Compare(heap[b], heap[a]) < 0)
                a = b;
            if (Compare(heap[a], x) >= 0)
                break;

            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        heap.RemoveAt(size);
        return ret;
    }

    public int Count { get { return size; } }

    public bool Any() { return size > 0; }

    public T Peek() { return heap[0]; }
}
class RMQ
{
    internal int n;
    internal int[] dat;
    public RMQ(int t)
    {
        n = t;
        dat = new int[2 * n - 1];
        for (int i = 0; i < 2 * n - 1; i++)
        {
            dat[i] = int.MaxValue;
        }
    }

    public void update(int k, int a)
    {
        k += n - 1;
        dat[k] = a;
        while (k > 0)
        {
            k = (k - 1) / 2;
            dat[k] = Math.Min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    public int query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l) return int.MaxValue;

        if (a <= l && r <= b) return dat[k];
        else
        {
            int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return Math.Min(vl, vr);
        }
    }
}
class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] Scan { get { return ReadLine().Split(); } }
    public int[] Scanint { get { return Array.ConvertAll(Scan, int.Parse); } }
    public long[] Scanlong { get { return Array.ConvertAll(Scan, long.Parse); } }
    public double[] Scandouble { get { return Array.ConvertAll(Scan, double.Parse); } }
    public string Next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return Next;
        }
    }
    public int Nextint { get { return int.Parse(Next); } }
    public long Nextlong { get { return long.Parse(Next); } }
    public double Nextdouble { get { return double.Parse(Next); } }
}