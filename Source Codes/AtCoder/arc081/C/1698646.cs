using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
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
        var S = cin.next;
        int N = S.Length;


        var G = Enumerable.Range(0, 26).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < N; i++)
        {
            G[S[i] - 'a'].Add(i);
        }
        for (int i = 0; i < 26; i++)
        {
            G[i].Add(N + 1);
        }
        var dp = Enumerable.Repeat(int.MaxValue, N + 2).ToArray();// i??????????????

        dp[N + 1] = 0;
        dp[N] = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
            {
                dp[i] = Math.Min(dp[i], 1 + dp[upper_bound(G[j], i)]);
            }
        }
        //WriteLine(string.Join(" ", dp));
        int L = int.MaxValue;
        for (int j = 0; j < 26; j++)
        {
            L = Math.Min(L, 1 + dp[upper_bound(G[j], -1)]);
        }
        //WriteLine(L);
        int r = -1;
        while (r < N)
        {
            int x = (r == -1) ? L : dp[r];
            for (int j = 0; j < 26; j++)
            {
                int y = upper_bound(G[j], r);
                if (dp[y] == x - 1)
                {
                    Write((char)('a' + j));
                    r = y;
                    break;
                }
            }
        }
        WriteLine();
    }

    //int next(int i, int c, List<int> G)//i??????c??????????????N????
    //{
    //    return upper_bound(G, i);
    //}

    int upper_bound(List<int> arr, int val)
    {
        int low = 0, high = arr.Count;
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid] <= val) low = mid + 1;
            else high = mid;
        }
        return arr[low];
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