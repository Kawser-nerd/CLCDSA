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
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";
    readonly string ALFA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int N;
    void solve()
    {
        var X = new int[3];
        var Y = new int[3];
        X[0] = cin.nextint;
        Y[0] = cin.nextint;
        int r = cin.nextint;
        X[1] = cin.nextint;
        Y[1] = cin.nextint;
        X[2] = cin.nextint;
        Y[2] = cin.nextint;

        bool red = false;
        for (int k = 0; k < 4; k++)
        {
            int x = X[0] + dd[k] * r;
            int y = Y[0] + dd[k + 1] * r;
            //WriteLine(x + " " + y);
            if (x < X[1] || X[2] < x || y < Y[1] || Y[2] < y)
            {
                red = true;
            }
        }
        bool blue = false;
        for (int i = 1; i < 3; i++)
        {
            for (int j = 1; j < 3; j++)
            {
                if(r * r < (X[i] - X[0]) * (X[i] - X[0]) + (Y[j] - Y[0]) * (Y[j] - Y[0]))
                {
                    blue = true;
                }
            }
        }
        WriteLine(red ? "YES" : "NO");
        WriteLine(blue ? "YES" : "NO");

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