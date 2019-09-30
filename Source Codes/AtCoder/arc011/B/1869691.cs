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
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;


    void solve()
    {
        int N = cin.nextint;
        var D = new Dictionary<char, int>
        {
            ['b'] = 1,
            ['c'] = 1,
            ['d'] = 2,
            ['w'] = 2,
            ['t'] = 3,
            ['j'] = 3,
            ['f'] = 4,
            ['q'] = 4,
            ['l'] = 5,
            ['v'] = 5,
            ['s'] = 6,
            ['x'] = 6,
            ['p'] = 7,
            ['m'] = 7,
            ['h'] = 8,
            ['k'] = 8,
            ['n'] = 9,
            ['g'] = 9,
            ['z'] = 0,
            ['r'] = 0
        };
        var H = new List<StringBuilder>();
        for (int i = 0; i < N; i++)
        {
            var S = cin.next.ToLower();
            var sb = new StringBuilder();
            foreach (var item in S)
            {
                if (D.ContainsKey(item))
                {
                    sb.Append(D[item]);
                }
            }
            if (sb.Length > 0) H.Add(sb);
        }
        for (int i = 0; i < H.Count; i++)
        {
            if (i != 0) Write(" ");
            Write(H[i]);
        }
        WriteLine();
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