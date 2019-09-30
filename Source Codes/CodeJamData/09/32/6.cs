using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Csharp_B
{
    class b
    {
        private static double eps = 1e-8;
        static void Main(string[] args)
        {
            int t, ca = 0;
            string line = Console.ReadLine();
            for (t = Convert.ToInt32(line); t > 0; --t)
            {
                line = Console.ReadLine();
                int n = Convert.ToInt32(line);
                double[,] xyz = new double[510, 3];
                double[,] dd = new double[510, 3];
                for (int i = 0; i < n; ++i)
                {
                    string[] tokens = Console.ReadLine().Trim().Split();
                    for (int j = 0; j < 3; ++j)
                    {
                        xyz[i, j] = Convert.ToDouble(tokens[j]);
                        dd[i, j] = Convert.ToDouble(tokens[j + 3]);
                    }
                }

                double[] sum = new double[] { 0, 0, 0 }, sumd = new double[] { 0, 0, 0 };
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        sum[j] += xyz[i, j];
                        sumd[j] += dd[i, j];
                    }
                }

                double a = (double)(sumd[0] * sumd[0] + sumd[1] * sumd[1] + sumd[2] * sumd[2]) / n / n;
                double c = (double)(sum[0] * sum[0] + sum[1] * sum[1] + sum[2] * sum[2]) / n / n;
                double b = (double)(2 * (sum[0] * sumd[0] + sum[1] * sumd[1] + sum[2] * sumd[2])) / n / n;
                double delta = b * b - 4 * a * c;
                double[] res = new double[2];
                if (Math.Abs(a) < eps)
                { // if a ==0
                    if (b > -eps)
                    { // if b >= 0
                        res[0] = c; res[1] = 0;
                    }
                    else
                    { // if b < 0
                        res[0] = 0; res[1] = -c / b;
                    }
                }
                else if (delta >= 0)
                {
                    double t1 = (-b - delta) / 2.0 / a, t2 = (-b + delta) / 2.0 / a;
                    if (t1 > t2)
                    {
                        double zzz = t1;
                        t1 = t2;
                        t2 = zzz;
                    }
                    if (t1 > -eps)
                    {
                        res[0] = 0; res[1] = t1;
                    }
                    else if (t2 > -eps)
                    {
                        res[0] = 0; res[1] = t2;
                    }
                    else
                    {
                        res[0] = c; res[1] = 0;
                    }
                }
                else if (-b / (2 * a) > 0)
                {
                    res[0] = -delta / (4 * a); res[1] = -b / (2 * a);
                }
                else
                {
                    res[0] = c; res[1] = 0;
                }

                Console.WriteLine("Case #{0}: {1} {2}", ++ca, Math.Sqrt(res[0]), res[1]);
            }
        }
    }
}
