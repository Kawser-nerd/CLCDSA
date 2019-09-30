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
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    void solve()
    {
        int N = cin.nextint;
        var A = cin.scanlong;
        var B = new long[N + 1];
        var C = new long[N + 1];
        //long ans = 0;
        for (int i = 0; i < N; i++)
        {
            B[i + 1] = B[i] + A[i];
            C[i + 1] = C[i] ^ A[i];
        }
        //WriteLine(string.Join(" ", B));
        //WriteLine(string.Join(" ", C));

        ////long cnt = 0;
        //for (int i = 0; i < N; i++)
        //{
        //    for (int j = i; j < N; j++)
        //    {
        //        if (gcd(i, j) == 1) cnt++;
        //    }
        //}
        //WriteLine(cnt);
        //[l,r)
        int l = 0;
        int r = 1;
        long ans = 0;
        long cnt = 0;
        int Len = 1;
        while (l < N)
        {
            //WriteLine(l + " " + (r - 1) + " " + ans);
            var sum = B[r] - B[l];
            var xor = C[r] ^ C[l];
            if (sum == xor)
            {
                r++;
                if (r == N + 1)
                {
                    //WriteLine(l + " " + (r - 2));
                    ans += r - l - 1;
                    l++;
                    r = N;

                }
            }
            else
            {
                //WriteLine(l + " " + (r - 2));
                ans += r - l - 1;
                l = l + 1;
                //cnt = 0;
                //Len = 1;

            }

        }

        WriteLine(ans);

    }

    long gcd(long a, long b)
    {
        return (b != 0) ? gcd(b, a % b) : a;
    }
    long lcm(long a, long b)
    {
        return a / gcd(a, b) * b;
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