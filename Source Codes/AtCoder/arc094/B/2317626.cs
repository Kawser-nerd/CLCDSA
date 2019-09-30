using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
//using System.Text;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
using System.Numerics;
//using static System.Math;
//using pair = Pair<int, int>;

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
        int TT = cin.nextint;
        for (int i = 0; i < TT; i++)
        {
            var A = cin.nextlong;
            var B = cin.nextlong;

            var C = A * B;

            BigInteger ng = (BigInteger)1 << 32; //???
            BigInteger ok = 0; //??

            while (ng - ok > 1)
            {
                var mid = (ng + ok) / 2;
                if (mid % 2 == 1)
                {
                    var P = (mid + 1) / 2;
                    if (P >= A) P++;
                    var Q = (mid + 1) / 2;
                    if (Q >= B) Q++;

                    if (P * Q < C)
                    {
                        ok = mid;
                    }
                    else
                    {
                        ng = mid;
                    }
                }
                else
                {
                    var p1 = mid / 2;
                    var p2 = mid / 2 + 1;
                    if (p1 >= A) p1++;
                    if (p2 >= A) p2++;
                    var q1 = mid / 2;
                    var q2 = mid / 2 + 1;
                    if (q1 >= B) q1++;
                    if (q2 >= B) q2++;

                    if (p1 * q2 < C && p2 *q1 < C)
                    {
                        ok = mid;
                    }
                    else
                    {
                        ng = mid;
                    }
                }
            }
            WriteLine(ok);



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