using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ09R1AQ3
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
                string[] bits = file[offset].Split(' ');
                int c = int.Parse(bits[0]);
                int n = int.Parse(bits[1]);
                offset++;
                output.Add(string.Format("Case #{0}: {1}", counter + 1, Solve(c, n)));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static double Solve(int c, int n)
        {
            double[] cache = new double[c + 1];
            for (int i = 0; i <= c; i++)
                cache[i] = -1.0;
            return 1.0 + OtherSolve(cache, c, c - n, n);
        }

        private static double OtherSolve(double[] cache, int c, int p, int n)
        {
            if (p == 0)
                return 0;
            if (cache[p] >= 0.0)
                return cache[p];
            double expectation = 0.0;
            double totalProbs = 0.0;
            for (int i = 1; i <= n && i <= p; i++)
            {
                double probScenario = ((double)Choose(p, i) * (double)Choose(c - p, n - i)) / (double)Choose(c, n);
                totalProbs += probScenario;
                expectation += probScenario * OtherSolve(cache, c, p - i, n);
            }
            expectation /= totalProbs;
            expectation += 1.0/(totalProbs); // estimated number of rolls to not roll above totalProbs on a uniform 0.0-1.0
            cache[p] = expectation;
            return expectation;
        }

        public static long Choose(long n, long k)
        {
            long res = 1;
            long currentK = k;
            for (long i = n; i >= n - k + 1; i--)
            {
                res *= i;
                while (currentK > 1 && res % currentK == 0)
                {
                    res /= currentK;
                    currentK--;
                }
            }
            while (currentK > 1)
            {
                res /= currentK;
                currentK--;
            }
            return res;
        }
    }
}
