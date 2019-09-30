using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cs_console
{
    class GQ_C
    {
        public static void Main(String[] args)
        {
            string input = @"C:\Documents and Settings\int\桌面\C.in";
            string output = @"C:\Documents and Settings\int\桌面\C.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    int tn = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= tn; tc++)
                    {
                        int n = int.Parse(sr.ReadLine());
                        string res = ls(sr.ReadLine());
                        sw.WriteLine("Case #{0}: {1}", tc, res);
                    }
                }
            }
        }

        private static string ls(string s)
        {
            string[] ss = s.Split(' ');
            int n = ss.Length;
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(ss[i]);
            }
            int v = 0;
            for (int i = 0; i < n; i++)
            {
                v = v ^ a[i];
            }
            if (v != 0)
            {
                return "NO";
            }
            Array.Sort(a);
            int c = 0;
            for (int j = 1; j < n; j++)
            {
                c += a[j];
            }
            return c + "";
            /*
            int m = (1 << n);
            int res = 0;
            for (int i = 1; i < m - 1; i++)
            {
                int a1 = 0;
                int a2 = 0;
                int c = 0;
                for (int j = 0; j < n; j++)
                {
                    if (((1 << j) & i) != 0)
                    {
                        a1 ^= a[j];
                        c += a[j];
                    }
                    else
                    {
                        a2 ^= a[j];
                    }
                }
                if (a1 == a2)
                    res = Math.Max(res, c);
            }
            if (res > 0)
            {
                return res + "";
            }
            Console.WriteLine("See?");
            return "NO";*/
        }

        static void assert(bool v)
        {
            if (false)
            {
                throw new Exception();
            }
        }
    }
}
