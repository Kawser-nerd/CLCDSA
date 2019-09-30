using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Facebook
{
    static class Program
    {
        static void Solve()
        {
            var s = sr.ReadLine().Split(' ');
            int A = int.Parse(s[0]);
            int n = int.Parse(s[1]);
            s = sr.ReadLine().Split(' ');
            if (A == 1)
            {
                Print(n.ToString());
                return;
            }
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(s[i]);
            }
            Array.Sort(a);
            int m = 1000000000;
            int c = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < A) A += a[i];
                else
                {
                    if (c + n - i < m) m = c + n - i;
                    c++;
                    A += A - 1;
                    i--;
                }
            }
            if (c < m) m = c;
            Print(m.ToString());
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
