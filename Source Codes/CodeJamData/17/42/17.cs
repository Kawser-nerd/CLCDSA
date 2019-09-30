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
        SetIn(new StreamReader("B-small-attempt2.in"));
        SetOut(new StreamWriter("b_out_2.txt"));
        //SetOut(new StreamWriter(OpenStandardOutput()));
        int T = int.Parse(ReadLine());
        for (int i = 0; i < T; i++)
        {
            Write("Case #" + (i + 1) + ": ");
            new Program().Solve();
        }
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";


    void Solve()
    {
        int N = cin.Nextint;
        int C = cin.Nextint;
        int M = cin.Nextint;


        var D = new int[N, C]; //i番目の席をjが持っている枚数
        var E = new int[C]; //jが持っている枚数
        var F = new int[N]; //i番目の席の枚数
        for (int i = 0; i < M; i++)
        {
            int a = cin.Nextint - 1;
            int b = cin.Nextint - 1;
            D[a, b]++;
            E[b]++;
            F[a]++;
        }
        int zero = F[0];
        int max = E.Max();
        int dx = F.Max();

        if (zero >= max)
        {
            WriteLine(zero + " " + (dx - zero));
        }
        else
        {
            WriteLine(max + " " + Math.Max(dx - max, 0));
        }


        /*
        var P = new PriorityQueue<int>();
        var Q = new PriorityQueue<int>();
        var R = new PriorityQueue<int>();
        var S = new PriorityQueue<int>();

        var D = new int[N, C]; //i番目の席をjが持っている枚数
        var E = new int[C]; //jが持っている枚数
        for (int i = 0; i < M; i++)
        {
            int a = cin.Nextint;
            int b = cin.Nextint - 1;
            if (b == 0)
            {
                P.Enqueue(a);
                R.Enqueue(-a);
            }
            else
            {
                Q.Enqueue(-a);
                S.Enqueue(a);
            }

        }
        int ans = 0;
        int cnt = 0;

        while (P.Any() && Q.Any())
        {
            var u = P.Dequeue();
            var v = -Q.Dequeue();
            //WriteLine(u + " " + v);
            if (u == v)
            {
                if (u == 1)
                {
                    ans++;
                    P.Enqueue(1);
                }
                else
                {
                    ans++;
                    cnt++;
                }
            }
            else
            {
                ans++;
            }
        }


        int nans = 0;
        int ncnt = 0;

        while (R.Any() && S.Any())
        {
            var u = -R.Dequeue();
            var v = S.Dequeue();
            //WriteLine(u + " " + v);
            if (u == v)
            {
                if (u == 1)
                {
                    nans++;
                    S.Enqueue(1);
                }
                else
                {
                    nans++;
                    ncnt++;
                }
            }
            else
            {
                nans++;
            }
        }
        ans += P.Count + Q.Count;
        nans += R.Count + S.Count;

        if (ans == nans)
        {
            WriteLine(ans + " " + Math.Min(cnt, ncnt));
        }
        else if (ans < nans)
        {
            WriteLine(ans + " " + cnt);
        }
        else
        {
            WriteLine(nans + " " + ncnt);
        }
        */
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