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
    readonly int mod = 998244353;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }


    void solve()
    {
        int N = cin.nextint;
        var A = cin.nextlong;
        var B = cin.nextlong;
        var K = cin.nextlong;
        table(2 * N);

        long ans = 0;
        if (A == B)
        {
            if (K % A == 0)
            {
                var p = K / A;
                if (p <= 2 * N)
                {
                    ans = combi(2 * N, (int)p);
                }
            }
            WriteLine(ans);
            return;
        }

        // i ????????
        for (int i = 0; i <= 2 * N; i++)
        {
            int M = 2 * N - i;
            if (A != B)
            {
                var x = (K - B * M) / (A - B);
                var y = (K - A * M) / (B - A);
                if (0 <= x && x <= N && 0 <= y && y <= N && x + y == M && A * x + B * y == K)
                {
                    ans += combi(N, (int)x) * combi(N, (int)y) % mod;
                    ans %= mod;
                }
            }

            //WriteLine(ans);
        }
        WriteLine(ans);
    }

    long[] A, B;
    //a^b(mod p) solution works in O(logb).
    long powmod(long a, long b, long p)
    {
        if (b == 0) return 1;
        if (b % 2 == 0)
        {
            long d = powmod(a, b / 2, p);
            return d * d % p;
        }
        else
        {
            return a * powmod(a, b - 1, p) % p;
        }
    }
    void table(int n)
    {
        A = new long[n + 1];
        B = new long[n + 1];
        A[0] = 1;
        for (int i = 0; i < n; i++)
        {
            A[i + 1] = A[i] * (i + 1) % mod;
        }
        B[n] = powmod(A[n], mod - 2, mod);
        for (int i = 0; i < n; i++)
        {
            B[n - i - 1] = B[n - i] * (n - i) % mod;
        }
    }
    long combi(int n, int r)
    {
        return A[n] * B[r] % mod * B[n - r] % mod;
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