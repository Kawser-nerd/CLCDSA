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


    void Solve()
    {
        int N = cin.Nextint;
        int rmax = 0, rmin = int.MaxValue, bmax = 0, bmin = int.MaxValue;
        var R = new int[N];
        var B = new int[N];

        for (int i = 0; i < N; i++)
        {
            int x = cin.Nextint;
            int y = cin.Nextint;
            int r = Math.Min(x, y);
            rmax = Math.Max(rmax, r);
            rmin = Math.Min(rmin, r);
            int b = Math.Max(x, y);
            bmax = Math.Max(bmax, b);
            bmin = Math.Min(bmin, b);

            R[i] = r;
            B[i] = b;
        }

        Array.Sort(R, B);
        /*for (int i = 0; i < N; i++)
        {
            WriteLine($"{R[i]} {B[i]}");
        }*/
        long ans = (long)(rmax - rmin) * (bmax - bmin);

        long diff = R[N - 1] - R[0];

        int m = B[0];//B?????????????????????
        int M = R[N - 1];//B?????????????????????
        for (int i = 0; i < N; i++)
        {
            diff = Math.Min(diff, M - Math.Min(m, R[i]));
            m = Math.Min(m, B[i]);
            M = Math.Max(M, B[i]);
            
            //WriteLine($"m={m} M={M} diff={diff}");
        }
        ans = Math.Min(ans, diff * (bmax - rmin));
        WriteLine(ans);


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