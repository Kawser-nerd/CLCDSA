using System;
using System.Collections.Generic;
using System.Text;

class Program
{
    class Solution
    {
        int n, m;
        long a;


        int[] readint(System.IO.TextReader r)
        {
            string[] x = (r.ReadLine().Trim().Split(' '));
            int[] y = new int[x.Length];

            for (int i = 0; i < y.Length; i++)
                y[i] = int.Parse(x[i]);
            return y;
        }


        public void readcase(System.IO.TextReader r)        
        {
            int[] x = readint(r);
            n = x[0];
            m = x[1];
            a = x[2];
        }

        public string solve()
        {

            for(long x1 = 0; x1 <= n; x1++)
                for(long y1 = 0; y1 <= m; y1++)
                    for(long x2 = x1-n; x2<=n; x2++)
                        for (long y2 = y1-m; y2 <=m; y2++)
                        {
                            long aa = x2 * y1 - x1 * y2;
                            if (aa != a && aa != -a) continue;

                            long x0 = 0;
                            long y0 = 0;
                            if (x2 < 0)
                            {
                                x0 -= x2;
                                x1 -= x2;
                                x2 = 0;
                            }
                            if (y2 < 0)
                            {
                                y0 -= y2;
                                y1 -= y2;
                                y2 = 0;
                            }

                            long aaa;
                            aaa = x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1);

                            return string.Format("{0} {1} {2} {3} {4} {5}", x0, y0, x1, y1, x2, y2);
                        }

            /*
            if (a == 0) return "0 0 0 0 0 0";

            long a2 = a * a;
            for(long x = 0; x<n; x++)
                for (long y = 0; y < m; y++)
                {
                    long b2 = x * x + y * y;
                    if (b2 == 0) continue;
                    if (a2 % b2 != 0) continue;
                    long h2 = a2 / b2;

                    double h = Math.Sqrt(h2);
                    double b = Math.Sqrt(b2);

                    double xx = (long)(-y * (h/b));
                    double yy = (long)(x * (h/b));

                    if (xx * xx + yy * yy != h2) continue;

                    xx += x;
                    yy += y;

                }
             */
             
            return string.Format("IMPOSSIBLE");
        }
    }

    static void Main(string[] args)
    {
        System.IO.TextReader r = new System.IO.StreamReader("../../a.in");
        System.IO.TextWriter w = new System.IO.StreamWriter("../../a.out");
        int n = int.Parse(r.ReadLine());

        for (int i = 0; i < n; i++)
        {
            Solution t = new Solution();
            t.readcase(r);

            string s = t.solve();
           
            w.WriteLine("Case #{0}: {1}", i + 1, s);
        }
        w.Close();
    }
}
