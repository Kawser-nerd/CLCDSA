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
//using pair = Pair<int, int>;

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
        int R = cin.nextint;
        int G = cin.nextint;
        int B = cin.nextint;

        long ans = long.MaxValue;

        //G???
        for (int l = -499; l <= 200; l++)
        {
            int r = l + G - 1;
            var a = calc(l, r, 0, G);

            //B???
            long b = long.MaxValue;
            for (int lb = r + 1; lb <= 500; lb++)
            {
                int rb = lb + B - 1;
                b = Math.Min(b, calc(lb, rb, 100, B));
            }
            //R???
            long c = long.MaxValue;
            for (int rr = -500; rr <= l - 1; rr++)
            {
                int lr = rr - R + 1;
                c = Math.Min(c, calc(lr, rr, -100, R));
            }

            ans = Math.Min(ans, a + b + c);
        }

        WriteLine(ans);
    }

    long calc(int l, int r, int S, int N)
    {
        int ll = Math.Abs(l - S);
        int rr = Math.Abs(r - S);
        if (S <= l)
        {
            return ll * N + (1 + N - 1) * (N - 1) / 2;
        }
        else if(r <= S)
        {
            return rr * N + (1 + N - 1) * (N - 1) / 2;
        }
        else
        {
            return (rr + 1) * rr / 2 + (ll + 1) * ll / 2;
        }
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