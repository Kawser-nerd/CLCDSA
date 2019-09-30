using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using SB = System.Text.StringBuilder;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
using System.Numerics;
using static System.Math;
using pair = Pair<long, long>;

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
    readonly int dom = 998244353;
    bool chmax<T>(ref T a, T b) where T : IComparable<T> { if (a.CompareTo(b) < 0) { a = b; return true; } return false; }
    bool chmin<T>(ref T a, T b) where T : IComparable<T> { if (b.CompareTo(a) < 0) { a = b; return true; } return false; }

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

/// <summary>
/// Original Author: ??
/// </summary>
/// <typeparam name="T"></typeparam>
class PriorityQueue<T> where T : IComparable<T>
{
    List<T> heap;
    readonly int cmp = 1;
    public PriorityQueue() { heap = new List<T>(); }
    public PriorityQueue(int cmp) { heap = new List<T>(); this.cmp = cmp; }
    public void Enqueue(T x)
    {
        heap.Add(x);
        int i = Count++;
        while (i > 0)
        {
            int p = (i - 1) >> 1;
            if (x.CompareTo(heap[p]) * cmp <= 0) break;
            heap[i] = heap[p]; i = p;
        }
        heap[i] = x;
    }
    public T Dequeue()
    {
        T ret = heap[0]; T x = heap[--Count];
        int i = 0;
        while ((i << 1) + 1 < Count)
        {
            int a = (i << 1) + 1; int b = (i << 1) + 2;
            if (b < Count && heap[a].CompareTo(heap[b]) * cmp < 0) a = b;
            if (x.CompareTo(heap[a]) * cmp >= 0) break;
            heap[i] = heap[a]; i = a;
        }
        heap[i] = x; heap.RemoveAt(Count);
        return ret;
    }
    public int Count { get; private set; }
    public bool Any() => Count > 0;
    public T Peek() => heap[0];
}

static class Ex
{
    public static void join<T>(this IEnumerable<T> values) => WriteLine(string.Join(" ", values));
    public static string join<T>(this IEnumerable<T> values, string sep) => string.Join(sep, values);
    public static string concat<T>(this IEnumerable<T> values) => string.Concat(values);
    public static string reverse(this string s) => s.Reverse().concat();

    public static int lower_bound<T>(this IList<T> arr, T val) where T : IComparable<T>
    {
        int low = 0, high = arr.Count();
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid].CompareTo(val) < 0) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    public static int upper_bound<T>(this IList<T> arr, T val) where T : IComparable<T>
    {
        int low = 0, high = arr.Count();
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid].CompareTo(val) <= 0) low = mid + 1;
            else high = mid;
        }
        return low;
    }
}

class Pair<T, U> : IComparable<Pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T f; public U s;
    public Pair(T f, U s) { this.f = f; this.s = s; }
    public int CompareTo(Pair<T, U> a) => f.CompareTo(a.f) != 0 ? f.CompareTo(a.f) : s.CompareTo(a.s);
    public override string ToString() => $"{f} {s}";
}

class Scanner
{
    string[] s; int i;
    readonly char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] scan => ReadLine().Split();
    public int[] scanint => Array.ConvertAll(scan, int.Parse);
    public long[] scanlong => Array.ConvertAll(scan, long.Parse);
    public double[] scandouble => Array.ConvertAll(scan, double.Parse);
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
    public int nextint => int.Parse(next);
    public long nextlong => long.Parse(next);
    public double nextdouble => double.Parse(next);
}