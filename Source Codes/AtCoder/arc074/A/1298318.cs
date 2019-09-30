using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";


    void Solve()
    {
        long H = cin.Nextlong;
        long W = cin.Nextlong;
        long ans = long.MaxValue;
        long max = H * W;

        for (long i = 1; i < H; i++)
        {
            long z = i * W;
            long rem = max - z; 
            if (rem % 2 == 0)
            {
                rem /= 2;
                long smin = Math.Min(z, rem);
                long smax = Math.Max(z, rem);
                ans = Math.Min(ans, smax - smin);
            }
            else
            {
                long tate = H - i;
                long yoko = W;
                long sma = Math.Min(tate, yoko);
                long ue = (rem - sma) / 2 + sma;
                long sita = (rem - sma) / 2;
                long smin = Math.Min(z, sita);
                long smax = Math.Max(z, ue);
                ans = Math.Min(ans, smax - smin);
            }        
        }

        long tmp = H;
        H = W;
        W = tmp;

        for (long i = 1; i < H; i++)
        {
            long z = i * W;
            long rem = max - z;
            if (rem % 2 == 0)
            {
                rem /= 2;
                long smin = Math.Min(z, rem);
                long smax = Math.Max(z, rem);
                ans = Math.Min(ans, smax - smin);
            }
            else
            {
                long tate = H - i;
                long yoko = W;
                long sma = Math.Min(tate, yoko);
                long ue = (rem - sma) / 2 + sma;
                long sita = (rem - sma) / 2;
                long smin = Math.Min(z, sita);
                long smax = Math.Max(z, ue);
                ans = Math.Min(ans, smax - smin);
            }
        }

        WriteLine(ans);
    }

}

class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] Scan { get { return ReadLine().Split(); } }
    public int[] Scanint { get { return Array.ConvertAll(Scan, int.Parse); } }
    public long[] Scanlong { get { return Array.ConvertAll(Scan, long.Parse); } }
    public double[] Scandouble { get { return Array.ConvertAll(Scan, double.Parse); } }
    public string Next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return Next;
        }
    }
    public int Nextint { get { return int.Parse(Next); } }
    public long Nextlong { get { return long.Parse(Next); } }
    public double Nextdouble { get { return double.Parse(Next); } }
}