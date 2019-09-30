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
        eratos(N);
        int ans = 0;
        for (int i = 1; i <= N; i += 2)
        {
            int j = i;
            int yaku = 1;
            foreach (var item in prime)
            {
                int cnt = 1;
                while(j % item == 0)
                {
                    j /= item;
                    cnt++;
                }
                yaku *= cnt;
            }
            if (yaku == 8)
            {
                ans++;
            }
        }
        WriteLine(ans);
    }

    List<int> prime;
    bool[] is_prime;
    void eratos(int n)
    {
        prime = new List<int>();
        is_prime = new bool[n + 1];
        for (int i = 0; i <= n; i++) is_prime[i] = true;
        is_prime[0] = is_prime[1] = false;
        for (int i = 0; i <= n; i++)
        {
            if (is_prime[i])
            {
                prime.Add(i);
                for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
            }
        }
    }
    int[] P;
    void phi(int n)
    {
        P = new int[n + 1];
        for (int i = 0; i <= n; i++) P[i] = i;
        for (int i = 2; i <= n; i++)
        {
            if (is_prime[i])
            {
                P[i] -= P[i] / i;
                for (int j = 2 * i; j <= n; j += i) P[j] -= P[j] / i;
            }
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