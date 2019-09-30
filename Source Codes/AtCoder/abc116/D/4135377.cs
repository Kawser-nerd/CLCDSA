using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
//using System.Text;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
//using System.Numerics;
//using static System.Math;
using pair = Pair<long, int>;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    readonly Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    void solve()
    {
        int N = cin.nextint;
        int K = cin.nextint;

        var used = new bool[N];
        var gomi = new PriorityQueue<long>(-1);
        var ans = 0L;

        var tmp = 0L;
        var net = 0L;

        var P = new pair[N];
        for (int i = 0; i < N; i++)
        {
            var t = cin.nextint - 1;
            var d = cin.nextlong;
            P[i] = new pair(d, t);
        }
        Array.Sort(P);
        Array.Reverse(P);

        for (int i = 0; i < N; i++)
        {
            var v = P[i].f;
            var u = P[i].s;
            if (i < K)
            {
                tmp += v;
                if (used[u])
                {
                    gomi.Enqueue(v);
                }
                else
                {
                    used[u] = true;
                    net++;
                }
            }
            else
            {
                if (!gomi.Any())
                {
                    break;
                }
                if (used[u])
                {
                    continue;
                }

                var e = gomi.Dequeue();
                tmp = tmp - e + v;
                used[u] = true;
                net++;
            }
            chmax(ref ans, net * net + tmp);
        }
        WriteLine(ans);
    }

}


class Pair<T, U> : IComparable<Pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T f;
    public U s;
    public Pair(T f, U s)
    {
        this.f = f;
        this.s = s;
    }
    public int CompareTo(Pair<T, U> a)
    {
        return f.CompareTo(a.f) != 0 ? f.CompareTo(a.f) : s.CompareTo(a.s);
    }
    public override string ToString()
    {
        return f + " " + s;
    }
}
class PriorityQueue<T> where T : IComparable<T>
{
    List<T> heap; int size;
    readonly int cmp = 1;
    int Compare(T x, T y) { return y.CompareTo(x); }
    public PriorityQueue() { heap = new List<T>(); }
    public PriorityQueue(int k) { heap = new List<T>(); cmp = k; }
    public void Enqueue(T x)
    {
        heap.Add(x);
        int i = size++;
        while (i > 0)
        {
            int p = (i - 1) >> 1;
            if (Compare(heap[p], x) * cmp <= 0) break;
            heap[i] = heap[p]; i = p;
        }
        heap[i] = x;
    }
    public T Dequeue()
    {
        T ret = heap[0]; T x = heap[--size];
        int i = 0;
        while ((i << 1) + 1 < size)
        {
            int a = (i << 1) + 1; int b = (i << 1) + 2;
            if (b < size && Compare(heap[b], heap[a]) * cmp < 0) a = b;
            if (Compare(heap[a], x) * cmp >= 0) break;
            heap[i] = heap[a]; i = a;
        }
        heap[i] = x; heap.RemoveAt(size);
        return ret;
    }
    public int Count { get { return size; } }
    public bool Any() { return size > 0; }
    public T Peek() { return heap[0]; }
}
class Scanner
{
    string[] s; int i;
    readonly char[] cs = new char[] { ' ' };
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
    public void join<T>(IEnumerable<T> values) { WriteLine(string.Join(" ", values)); }
}