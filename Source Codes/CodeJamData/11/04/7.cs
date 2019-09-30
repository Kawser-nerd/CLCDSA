using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cs_console
{
    class GQ_D
    {
        public static void Main(String[] args)
        {
            string input = @"C:\Documents and Settings\int\桌面\D.in";
            string output = @"C:\Documents and Settings\int\桌面\D.out";
            preCalc();
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    int tn = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= tn; tc++)
                    {
                        int n = int.Parse(sr.ReadLine());
                        double res = ls(sr.ReadLine());
                        sw.WriteLine("Case #{0}: {1:F6}", tc, res);
                    }
                }
            }
        }

        const int maxn = 1000;
        static double[] c = new double[maxn + 1];
        private static void preCalc()
        {
            checked
            {
                double[] b = new double[maxn + 1];
                double[] d = new double[maxn + 1];
                b[0] = 1;
                b[1] = 0;
                double s = -1;
                d[0] = d[1] = 1;
                for (int i = 2; i <= maxn; i++)
                {
                    s /= i;
                    s *= -1;
                    b[i] = b[i - 1] + s;
                    d[i] = d[i - 1] / i;
                }
                c[0] = 0;
                c[1] = 0;
                for (int i = 2; i <= maxn; i++)
                {
                    double t = 0;
                    double c0 = 0;
                    for (int j = 0; j < i; j++)
                    {
                        double x = b[j] * d[i - j];
                        t += x;
                        c0 += x * c[j];
                    }
                    c[i]++;
                    c[i] = (c0 + 1) / t;
                    //Console.WriteLine(c[i]);
                }
            }            
        }

        private static double ls(string s)
        {
            string[] ss = s.Split(' ');
            int n = ss.Length;
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++)
            {
                b[i] = a[i] = int.Parse(ss[i]);
            }
            Array.Sort(a);
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != b[i])
                    cnt++;
            }
            return c[cnt];
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
