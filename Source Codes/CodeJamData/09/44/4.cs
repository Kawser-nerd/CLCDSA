using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;


namespace ProblemD
{
    class Program
    {
        static double Solve(int[] x, int[] y, int[] r)
        {
            if (x.Length == 1)
            {
                return r[0];
            }
            if (x.Length == 2)
            {
                return Math.Max(r[0], r[1]);
            }
            double r0 = Math.Max((Math.Sqrt(Math.Pow(x[1] - x[2], 2) + Math.Pow(y[1] - y[2], 2)) + r[1] + r[2]) / 2.0, r[0]);
            double r1 = Math.Max((Math.Sqrt(Math.Pow(x[0] - x[2], 2) + Math.Pow(y[0] - y[2], 2)) + r[0] + r[2]) / 2.0, r[1]);
            double r2 = Math.Max((Math.Sqrt(Math.Pow(x[0] - x[1], 2) + Math.Pow(y[0] - y[1], 2)) + r[0] + r[1]) / 2.0, r[2]);
            return Math.Min(r0, Math.Min(r1, r2));
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
                {
                    int C = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < C; i++)
                    {
                        int N = Int32.Parse(reader.ReadLine());

                        int[] x = new int[N];
                        int[] y = new int[N];
                        int[] r = new int[N];

                        for (int j = 0; j < N; j++)
                        {
                            string[] temp = reader.ReadLine().Split();
                            x[j] = Int32.Parse(temp[0]);
                            y[j] = Int32.Parse(temp[1]);
                            r[j] = Int32.Parse(temp[2]);
                        }

                        double res = Solve(x, y, r);
                        writer.WriteLine("Case #" + (i + 1) + ": " + res.ToString("F6", CultureInfo.InvariantCulture));
                    }
                }
            }
        }
    }
}
