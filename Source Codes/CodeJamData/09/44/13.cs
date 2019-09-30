using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Dsmall
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("D-small-attempt0.in"))
            {
                using (StreamWriter sw = new StreamWriter("D-small-attempt0.out"))
                {
                    int count = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= count; tc++)
                    {
                        int N = int.Parse(sr.ReadLine());
                        int[] x = new int[N];
                        int[] y = new int[N];
                        int[] r = new int[N];
                        for (int i = 0; i < N; i++)
                        {
                            string[] elem = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                            x[i] = int.Parse(elem[0]);
                            y[i] = int.Parse(elem[1]);
                            r[i] = int.Parse(elem[2]);
                        }

                        if (N == 1)
                        {
                            sw.WriteLine("Case #{0}: {1:0.000000}", tc, r[0]);
                        }
                        else if (N == 2)
                        {
                            double rad2 = FindRad(x[0], y[0], r[0], x[1], y[1], r[1]);
                            double dist = Math.Max(r[0], r[1]);
                            double mindist = Math.Min(rad2, dist);
                            sw.WriteLine("Case #{0}: {1:0.000000}", tc, mindist);
                        }
                        else if (N == 3)
                        {
                            double rad1 = FindRad(x[1], y[1], r[1], x[2], y[2], r[2]);
                            double dist1 = Math.Max(r[0], rad1);
                            double rad2 = FindRad(x[0], y[0], r[0], x[1], y[1], r[1]);
                            double dist2 = Math.Max(r[2], rad2);
                            double rad3 = FindRad(x[0], y[0], r[0], x[2], y[2], r[2]);
                            double dist3 = Math.Max(r[1], rad3);

                            double mindist = Math.Min(dist1, Math.Min(dist2, dist3));

                            sw.WriteLine("Case #{0}: {1:0.000000}", tc, mindist);
                        }
                    }
                }
            }
        }

        static double FindRad(int x1, int y1, int r1, int x2, int y2, int r2)
        {
            double dist2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            double dist = Math.Sqrt(dist2);
            dist += (r1 + r2);
            return dist / 2;
        }
    }
}
