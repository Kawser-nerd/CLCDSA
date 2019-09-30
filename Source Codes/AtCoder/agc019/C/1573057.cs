using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;
using static System.Math;

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
    int sx, sy, gx, gy, dx, dy;
    int[] X;
    int[] Y;
    List<int> G;
    decimal dis;

    void input()
    {
        sx = cin.nextint;
        sy = cin.nextint;
        gx = cin.nextint;
        gy = cin.nextint;
        dx = Abs(sx - gx);
        dy = Abs(sy - gy);
        N = cin.nextint;
        X = new int[N];
        Y = new int[N];
        for (int i = 0; i < N; i++)
        {
            X[i] = cin.nextint;
            Y[i] = cin.nextint;
        }
        dis = (decimal)(Math.Abs(sx - gx) + Math.Abs(sy - gy)) * 100;
    }

    void straight()
    {
        if (G.Count > 0)
        {
            dis = dis - 20 + 20 / 2 * (decimal)Math.PI;
        }
        WriteLine(dis.ToString("F12"));
    }
    void solve()
    {
        input();
        Array.Sort(Y, X);
        int MinY = Math.Min(sy, gy);
        int MaxY = Math.Max(sy, gy);
        int MinX = Math.Min(sx, gx);
        int MaxX = Math.Max(sx, gx);


        //WriteLine(MinY + " " + MaxY);
        int s = LowerBound(Y, MinY);
        int t = UpperBound(Y, MaxY) - 1;
        //WriteLine(s + " " + t);
        // s <= i <= t??????

        G = new List<int>();
        for (int i = s; i <= t; i++)
        {
            if (MinX <= X[i] && X[i] <= MaxX)
            {
                G.Add(X[i]);
            }
        }
        if (sx == gx || sy == gy)
        {
            straight();
            return;
        }
        //var A = G.ToArray();
        int F = G.Count;
        if (F == 0)
        {
            WriteLine(dis.ToString("F12"));
            return;
        }


        var dp = new int[F];
        for (int i = 0; i < F; i++)
        {
            dp[i] = int.MaxValue;
        }
        if ((sx < gx && sy < gy) || (gx < sx && gy < sy))
        {
            for (int i = 0; i < F; i++)
            {
                dp[LowerBound(dp, G[i])] = G[i];
            }
        }
        else
        {
            for (int i = 0; i < F; i++)
            {
                int k = F - i - 1;
                dp[LowerBound(dp, G[k])] = G[k];
            }
        }
        int cnt = LowerBound(dp, int.MaxValue);
        //WriteLine(cnt + " " + dis);
   
        dis = dis - 20 * cnt + cnt * 20 / 4 * (decimal)Math.PI;
        if (Min(dx, dy) + 1 == cnt)
        {
            dis += 20 / 4 * (decimal)Math.PI;
        }
        WriteLine(dis.ToString("F12"));

    }


    int LowerBound(int[] arr, int val)
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

    int UpperBound(int[] arr, int val)
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