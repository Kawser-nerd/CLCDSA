using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2009
{
    class R2D
    {
        public static void f()
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\D.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\D.out"))
                {
                    //bool[] b = new bool[1 << 24];
                    int cs = int.Parse(sr.ReadLine());
                    for (int ci = 0; ci < cs; ci++)
                    {
                        int n = int.Parse(sr.ReadLine());
                        int[] x = new int[n];
                        int[] y = new int[n];
                        int[] r = new int[n];
                        for (int i = 0; i < n; i++)
                        {
                            String[] strs = sr.ReadLine().Split(' ');
                            x[i] = int.Parse(strs[0]);
                            y[i] = int.Parse(strs[1]);
                            r[i] = int.Parse(strs[2]);
                        }
                        double min = double.MaxValue;
                        if (n == 1)
                        {
                            min = r[0];
                        }
                        else if (n == 2)
                        {
                            min = Math.Max(r[0], r[1]);
                        }
                        else
                        {
                            min = Math.Min(min, g(x[0], y[0], r[0], x[1], y[1], r[1], x[2], y[2], r[2]));
                            min = Math.Min(min, g(x[0], y[0], r[0], x[2], y[2], r[2], x[1], y[1], r[1]));
                            min = Math.Min(min, g(x[2], y[2], r[2], x[1], y[1], r[1], x[0], y[0], r[0]));
                        }
                        Console.WriteLine("Case #" + (ci + 1) + ": " + min);
                        sw.WriteLine("Case #" + (ci + 1) + ": " + min);
                    }
                }
            }
        }

        private static double g(int p_1, int p_2, int p_3, int p_4, int p_5, int p_6, int p_7, int p_8, int p_9)
        {
            double v1 = (d(p_1 - p_4, p_2 - p_5) + p_3 + p_6) / 2.0;
            return Math.Max(v1, p_9);
        }

        private static double d(double p, double q)
        {
            return Math.Sqrt(p * p + q * q);
        }
    }
}
