using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

class Program
{
    static void Main()
    {
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";

    int MAX = (int)1e5;

    void Solve()
    {
        int N = cin.Nextint;
        var A = new Pair[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = new Pair(cin.Nextint, cin.Nextint - 1);
        }
        A = A.OrderBy(i => i.Key).ThenByDescending(i => i.Value).ToArray();

        int n = 1;
        while (n < MAX) n *= 2;

        var B = new RMQ(n);
        for (int i = 0; i < N; i++)
        {
            B.Update(A[i].Value, B.Query(0, A[i].Value, 0, 0, n) + 1);
        }
        WriteLine(B.Query(0, n, 0, 0, n));
    }

    class RMQ
    {
        int n;
        int[] dat;
        public RMQ(int t)
        {
            n = t;
            dat = new int[2 * n - 1];
        }
        public void Update(int k, int a)
        {
            k += n - 1;
            dat[k] = a;
            while (k > 0)
            {
                k = (k - 1) / 2;
                dat[k] = Math.Max(dat[k * 2 + 1], dat[k * 2 + 2]);
            }
        }
        public int Query(int a, int b, int k, int l, int r)
        {
            if (r <= a || b <= l) return 0;

            if (a <= l && r <= b) return dat[k];
            else
            {
                int vl = Query(a, b, k * 2 + 1, l, (l + r) / 2);
                int vr = Query(a, b, k * 2 + 2, (l + r) / 2, r);
                return Math.Max(vl, vr);
            }
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