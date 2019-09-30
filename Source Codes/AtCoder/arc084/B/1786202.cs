using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
//using System.Numerics;
//using static System.Math;
 
class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
 
 
    void solve()
    {
        int K = cin.nextint;
        G = Enumerable.Range(0, K).Select(i => new List<Edge>()).ToArray();
        for (int i = 0; i < K; i++)
        {
            G[i].Add(new Edge((i + 1) % K, 1));
            G[i].Add(new Edge((i * 10) % K, 0));
        }
        dijkstra(1);
 
        WriteLine(D[0] + 1);
    }
    // ref: http://abc070.contest.atcoder.jp/submissions/1505233
    struct Edge : IComparable<Edge>
    {
        public int to; public long cost;
        public Edge(int to, long cost)
        {
            this.to = to;
            this.cost = cost;
        }
        public int CompareTo(Edge e)
        {
            return cost.CompareTo(e.cost);
        }
    }
    List<Edge>[] G;
    long[] D;
    const long inf = long.MaxValue / 3;
    void input(int n, int m)
    {
        G = Enumerable.Range(0, n).Select(i => new List<Edge>()).ToArray();
        for (int i = 0; i < m; i++)
        {
            int a = cin.nextint - 1;
            int b = cin.nextint - 1;
            long c = cin.nextlong;
            G[a].Add(new Edge(b, c));
            G[b].Add(new Edge(a, c));
        }
    }
    void dijkstra(int s)
    {
        int n = G.Length;
        D = Enumerable.Repeat(inf, n).ToArray();
        var Q = new PriorityQueue<Edge>();//??????????????-1????
        D[s] = 0;
        Q.Enqueue(new Edge(s, D[s]));
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
}
 
class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] scan { get { return ReadLine().Split(); } }
    public int[] scanint { get { return Array.ConvertAll(scan, int.Parse); } }
    public long[] scanlong { get { return Array.ConvertAll(scan, long.Parse); } }
    public double[] scandouble { get { return Array.ConvertAll(scan, double.Parse); } }
    public string next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return next;
        }
    }
    public int nextint { get { return int.Parse(next); } }
    public long nextlong { get { return long.Parse(next); } }
    public double nextdouble { get { return double.Parse(next); } }
}