using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Facebook
{
    static class Program
    {
        static long[] p2 = new long[64];

        static long get0(long p)
        {
            int t = 0;
            bool b = true;
            while(p>0)
            {
                t++;
                if (p % 2 == 0) b = false;
                p >>= 1;
            }
            if (t == 0) return 0;
            if (b) return t;
            return t - 1;
        }

        static long solve(long n, long p)
        {
            p--;
            long x = n - get0(p);
            return p2[n] - p2[x];
        }

        static void Solve()
        {

            var s = sr.ReadLine().Split(' ');
            long n = long.Parse(s[0]);
            long p = long.Parse(s[1]);
            long x = solve(n, p);
            //long yy = solve(n, p2[n] - p);
            //if (yy == 0) yy -= 1;
            long y = p2[n] - solve(n, p2[n] - p) - 2;
            if (p == p2[n]) y = p2[n] - 1;
            Print(y.ToString() + " " + x.ToString());
        }

        static void PreCalc()
        {
            p2[0] = 1;
            for (int i = 1; i < 60; i++) p2[i] = 2 * p2[i - 1];
        }

        #region Main
        static int testNum = 1;
        static StreamReader sr;
        static StreamWriter sw;
        static void Print(string s)
        {
            sw.WriteLine("Case #{0}: {1}", testNum, s);
            testNum++;
        }
        static void Main(string[] args)
        {
            PreCalc();
            sr = new StreamReader(@"..\..\in.txt");
            sw = new StreamWriter(@"..\..\out.txt");
            int t = int.Parse(sr.ReadLine());
            for (int i = 0; i < t; i++)
            {
                Solve();
            }
            sr.Dispose();
            sw.Dispose();
        }
        #endregion
    }
}
