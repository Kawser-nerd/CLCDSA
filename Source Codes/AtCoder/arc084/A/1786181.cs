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
        var A = cin.scanint;
        var B = cin.scanint;
        var C = cin.scanint;
        Array.Sort(A);
        Array.Sort(B);
        Array.Sort(C);
 
        var BB = new long[N];
        for (int i = 0; i < N; i++)
        {
            BB[i] =  N - upper_bound(C, B[i]);
        }
        for (int i = 1; i < N; i++)
        {
            int k = N - i - 1;
            BB[k] += BB[k + 1];
        }
        long ans = 0;
        for (int i = 0; i < N; i++)
        {
            int b = upper_bound(B, A[i]);
            if (b == N) break;
            ans += BB[b];
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