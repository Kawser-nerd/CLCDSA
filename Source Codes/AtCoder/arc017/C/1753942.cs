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
        int X = cin.nextint;
        var W = new int[N];
        for (int i = 0; i < N; i++)
        {
            W[i] = cin.nextint;
        }
        int n2 = N / 2;
        var Q = new int[1 << n2];
        for (int i = 0; i < 1 << n2; i++)
        {
            int w = 0;
            for (int j = 0; j < n2; j++)
            {
                if ((i >> j & 1) == 1)
                {
                    w += W[j];
                }
            }
            Q[i] = w;
        }
        Array.Sort(Q);
        long ans = 0;
        for (int i = 0; i < 1 << (N - n2); i++)
        {
            int w = 0;
            for (int j = 0; j < N - n2; j++)
            {
                if ((i >> j & 1) == 1)
                {
                    w += W[n2 + j];
                }
            }
            ans += upper_bound(Q, X - w) - lower_bound(Q, X - w);
        }
        WriteLine(ans);
    }

    int upper_bound(int[] arr, int val)
    {
        int low = 0, high = arr.Length;
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid] <= val) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    int lower_bound(int[] arr, int val)
    {
        int low = 0, high = arr.Length;
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