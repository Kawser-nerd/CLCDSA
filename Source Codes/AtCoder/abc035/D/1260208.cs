using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

class Edge : IComparable
{
    public int to;
    public long cost;
    public Edge(int to, long cost)
    {
        this.to = to;
        this.cost = cost;
    }
    public int CompareTo(object obj)
    {
        long d = cost - ((Edge)obj).cost;
        if (d < 0)
        {
            return -1;
        }
        else if (0 < d)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

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


    long INF = long.MaxValue / 3;
    int N, M, T;
    void Solve()
    {
        N = cin.Nextint;
        M = cin.Nextint;
        T = cin.Nextint;
        var A = cin.Scanlong;
        var G = Enumerable.Range(0, N).Select(i => new List<Edge>()).ToArray();
        var H = Enumerable.Range(0, N).Select(i => new List<Edge>()).ToArray();
        var D = Enumerable.Repeat(INF, N).ToArray();
        D[0] = 0;
        var E = Enumerable.Repeat(INF, N).ToArray();
        E[0] = 0;
        for (int i = 0; i < M; i++)
        {
            int a = cin.Nextint - 1;
            int b = cin.Nextint - 1;
            int c = cin.Nextint;
            G[a].Add(new Edge(b, c));
            H[b].Add(new Edge(a, c));
        }
        var Q = new PriorityQueue<Edge>();
        Q.Enqueue(new Edge(0, 0));

        while (Q.Any())
        {
            var e = Q.Dequeue();
            var v = e.to;

            if (D[v] < -e.cost) continue;

            foreach (var gv in G[v])
            {
                if (D[gv.to] > D[v] + gv.cost)
                {
                    D[gv.to] = D[v] + gv.cost;
                    Q.Enqueue(new Edge(gv.to, -D[gv.to]));
                }
            }

        }
        var R = new PriorityQueue<Edge>();
        R.Enqueue(new Edge(0, 0));
        while (R.Any())
        {
            var e = R.Dequeue();
            var v = e.to;

            if (E[v] < -e.cost) continue;

            foreach (var gv in H[v])
            {
                if (E[gv.to] > E[v] + gv.cost)
                {
                    E[gv.to] = E[v] + gv.cost;
                    R.Enqueue(new Edge(gv.to, -E[gv.to]));
                }
            }

        }

        long ans = 0;
        //WriteLine(string.Join(" ", D));
        //WriteLine(string.Join(" ", E));
        for (int i = 0; i < N; i++)
        {
            if (D[i] == INF || E[i] == INF) continue;
            long time = T - (D[i] + E[i]);
            if (time <= 0) continue;
            ans = Math.Max(A[i] * time, ans);
        }
        WriteLine(ans);


    }

}

class PriorityQueue<T> where T : IComparable
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
/*class PriorityQueue<T> where T : IComparable
{
    const int MAX_SIZE = 100010;
    private T[] heap;
    public int Size { get; protected set; }

    public PriorityQueue()
    {
        heap = new T[MAX_SIZE];
    }

    public void Enqueue(T x)
    {
        int i = Size++;

        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (heap[p].CompareTo(x) <= 0)
            {
                break;
            }
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    public T Peek()
    {
        return heap[0];
    }
    public bool Any() { return Size > 0; }
    public int Count { get { return Size; } }

    public T Dequeue()
    {
        T ret = heap[0];
        T x = heap[--Size];

        int i = 0;
        while (i * 2 + 1 < Size)
        {
            int a = i * 2 + 1, b = i * 2 + 2;
            if (b < Size && heap[b].CompareTo(heap[a]) < 0)
            {
                a = b;
            }

            if (heap[a].CompareTo(x) >= 0)
            {
                break;
            }
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        return ret;
    }
}
*/
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