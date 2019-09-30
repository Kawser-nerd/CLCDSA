using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ09R2Q4
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] file = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int count = int.Parse(file[0]);
            int offset = 1;
            for (int counter = 0; counter < count; counter++)
            {
                int N = int.Parse(file[offset]);
                offset++;
                int[] xs = new int[N];
                int[] ys = new int[N];
                int[] rs = new int[N];
                for (int i = 0; i < N; i++)
                {
                    string[] bits = file[offset].Split(' ');
                    xs[i] = int.Parse(bits[0]);
                    ys[i] = int.Parse(bits[1]);
                    rs[i] = int.Parse(bits[2]);
                    offset++;
                }
                output.Add(string.Format("Case #{0}: {1}", counter + 1, Solve(xs, ys, rs)));
            }
            File.WriteAllLines("output.txt", output.ToArray());

        }

        private static double Solve(int[] xs, int[] ys, int[] rs)
        {
            if (xs.Length == 1)
                return (double)rs[0];
            if (xs.Length == 2)
                return (double)Math.Max(rs[0], rs[1]);
            if (xs.Length == 3)
            {
                double minR = double.MaxValue;
                for (int i = 0; i < xs.Length - 1; i++)
                {
                    for (int j = i + 1; j < xs.Length; j++)
                    {
                        for (int k = 0; k < xs.Length; k++)
                        {
                            if (i == k)
                                continue;
                            if (j == k)
                                continue;
                            double r1 = Dist(xs[i], ys[i], xs[j], ys[j]) + rs[i] + rs[j];
                            r1 /= 2.0;
                            double r2 = rs[k];
                            double rTrial = Math.Max(r1, r2);
                            if (rTrial < minR)
                                minR = rTrial;
                        }
                    }
                }
                return minR;
            }
            throw new NotImplementedException();
            // For the N > 3 case...
        }

        private static double Dist(int x1, int y1, int x2, int y2)
        {
            return Math.Sqrt(Math.Pow(x1 - x2, 2) + Math.Pow(y1 - y2, 2));
        }
    }
}
