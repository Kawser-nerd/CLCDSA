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
        int N = cin.nextint;
        var C = new int[N];

        var J = new bool[N];
        var A = new int[N + 1];
        var B = new int[N];


        for (int i = 0; i < N; i++)
        {
            C[i] = cin.nextint;
            A[C[i]] = A[C[i] - 1] + 1;
        }

        //WriteLine(string.Join(" ", A));

        WriteLine(N - A.Max());


        //var X = lis(C);
        //Array.Reverse(C);
        //var Y = lis(C);

        //WriteLine(X + " " + Y);


        //WriteLine(N - lis(C));
    }

    int lis(int[] A)
    {
        var dp = new int[A.Length];
        for (int i = 0; i < A.Length; i++)
        {
            dp[i] = int.MaxValue;
        }
        foreach (var i in A)
        {
            dp[lower_bound(dp, i)] = i;
        }

        return lower_bound(dp, int.MaxValue);
    }
    int lower_bound(int[] arr, int val)
    {
        int low = 0, high = arr.Count();
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid] < val) low = mid + 1;
            else high = mid;
        }
        return low;
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