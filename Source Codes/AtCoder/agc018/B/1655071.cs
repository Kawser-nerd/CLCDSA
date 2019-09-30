using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
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
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";
    readonly string ALFA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int N, M;
    void solve()
    {
        N = cin.nextint;
        M = cin.nextint;
        var A = new int[N][];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.scanint.Select(j => j - 1).ToArray();
        }
        int ans = int.MaxValue;
        var H = new HashSet<int>();
        for (int i = 0; i < M; i++)
        {
            var C = new int[M];
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    int d = A[j][k];
                    if (!H.Contains(d))
                    {
                        C[d]++;
                        break;
                    }
                }
            }
            int idx = -1;
            int max = 0;
            //WriteLine(string.Join(" ", C));
            for (int j = 0; j < M; j++)
            {
                if (C[j] > max)
                {
                    max = C[j];
                    idx = j;
                }
            }
            ans = Math.Min(max, ans);
            H.Add(idx);
        }
        WriteLine(ans);
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