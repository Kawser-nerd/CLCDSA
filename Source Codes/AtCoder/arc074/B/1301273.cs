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

    //???????????
    void Solve()
    {
        int N = cin.Nextint;
        var A = cin.Scanint;
        var P = new PriorityQueue<int>();
        var Q = new PriorityQueue<int>();
        var R = new long[2 * N + 1];
        var S = new long[2 * N + 1];
        for (int i = 0; i < N; i++)
        {
            R[N - 1] += A[i];
            P.Enqueue(-A[i]);
        }
        for (int i = N; i < 2 * N; i++)
        {
            R[i] = R[i - 1];
            R[i] += A[i];
            P.Enqueue(-A[i]);
            R[i] -= -P.Dequeue();
        }

        for (int i = 2 * N; i < 3 * N; i++)
        {
            S[2 * N] += A[i];
            Q.Enqueue(A[i]);
        }
        for (int i = 2 * N - 1; i >= N; i--)
        {
            S[i] = S[i + 1];
            S[i] += A[i];
            Q.Enqueue(A[i]);
            S[i] -= Q.Dequeue(); 
        }

        long ans = long.MinValue;
        for (int i = N - 1; i < 2 * N; i++)
        {
            ans = Math.Max(ans, R[i] - S[i + 1]);
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