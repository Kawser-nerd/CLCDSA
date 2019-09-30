using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Facebook
{
    static class Program
    {
        static double f(int k, int n)
        {
            double res = 1;
            for (int i = 1; i <= k; ++i)
                res = res * (n - k + i) / i /2.0;
            for (int i = k + 1; i <= n; i++)
                res /= 2.0;
            return res;
        }

        static void Solve()
        {
            var s = sr.ReadLine().Split(' ');
            int n = int.Parse(s[0]);
            int x = int.Parse(s[1]);
            if (x < 0) x = -x;
            int y = int.Parse(s[2]);
            if (y < 0) y = -y;
            int t = 0;
            int j = 0;
            while (t <= n)
            {
                t += 4 * j + 1;
                j++;
            }
            j -= 2;
            int l = (x + y) / 2;
            if (l <= j)
            {
                Print("1.0");
                return;
            }
            if (l > j + 1)
            {
                Print("0.0");
                return;
            }
            t = 0;
            for (int i = 0; i <= j; i++)
            {
                t += 4 * i + 1;
            }
            if (x==0)
            {
                Print("0.0");
                return;
            }
            int r = n - t;
            y++;
            if (r < y)
            {
                Print("0.0");
                return;
            }
            if (r - 2 * (j+1) >= y)
            {
                Print("1.0");
                return;
            }
            double res = 0;
            for (int i = y; i <= r; i++)
            {
                res += f(i, r);
            }
            Print(res.ToString(CultureInfo.InvariantCulture));
        }

        static void PreCalc()
        {
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
