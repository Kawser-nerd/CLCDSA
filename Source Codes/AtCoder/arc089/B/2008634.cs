using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
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
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;


    void solve()
    {
        int N = cin.nextint;
        int K = cin.nextint;
        var P = new Two_D(2 * K, 2 * K);
        var Q = new Two_D(2 * K, 2 * K);
        for (int i = 0; i < N; i++)
        {
            int y = cin.nextint;
            int x = cin.nextint;
            var c = cin.next[0];
            if (c == 'W')
            {
                Q.D[y % (2 * K), x % (2 * K)]++;
                y += K;
                P.D[y % (2 * K), x % (2 * K)]++;
            }
            else
            {
                P.D[y % (2 * K), x % (2 * K)]++;
                y += K;
                Q.D[y % (2 * K), x % (2 * K)]++;
            }

        }
        //for (int i = 0; i < 2 * K; i++)
        //{
        //    for (int j = 0; j < 2 * K; j++)
        //    {
        //        Write(P.D[i, j]);
        //    }
        //    WriteLine();
        //}
        //WriteLine();

        P.build();
        Q.build();

        long ans = 0;
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < K; j++)
            {
                long ret = P.query(i, Min(i + K - 1, 2 * K - 1), j, Min(j + K - 1, 2 * K - 1));
                if (i > 0 && j > 0) ret += P.query(0, i - 1, 0, j - 1); //??
                if (i > 0) ret += P.query(0, i - 1, j + K, 2 * K - 1);  //??
                if (j > 0) ret += P.query(i + K, 2 * K - 1, 0, j - 1);  //??
                ret += P.query(i + K, 2 * K - 1, j + K, 2 * K - 1);     //??

                ans = Max(ret, ans);

                ret = Q.query(i, Min(i + K - 1, 2 * K - 1), j, Min(j + K - 1, 2 * K - 1));
                if (i > 0 && j > 0) ret += Q.query(0, i - 1, 0, j - 1);
                if (i > 0) ret += Q.query(0, i - 1, j + K, 2 * K - 1);
                if (j > 0) ret += Q.query(i + K, 2 * K - 1, 0, j - 1);
                ret += Q.query(i + K, 2 * K - 1, j + K, 2 * K - 1);

                ans = Max(ret, ans);
            }
        }

        WriteLine(ans);
    }

}

class Two_D
{
    public long[,] D;
    public int H;
    public int W;
    public Two_D(int H, int W)
    {
        this.H = H;
        this.W = W;
        D = new long[H, W];
    }
    public void build()
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 1; j < W; j++)
            {
                D[i, j] += D[i, j - 1];
            }
        }
        for (int i = 1; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                D[i, j] += D[i - 1, j];
            }
        }
    }
    //sum [(min_y, min_x), (max_y, max_x)]
    public long query(int min_y, int max_y, int min_x, int max_x)
    {
        long ret = D[max_y, max_x];
        if (min_y > 0) ret -= D[min_y - 1, max_x];
        if (min_x > 0) ret -= D[max_y, min_x - 1];
        if (min_y > 0 && min_x > 0) ret += D[min_y - 1, min_x - 1];

        return ret;
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