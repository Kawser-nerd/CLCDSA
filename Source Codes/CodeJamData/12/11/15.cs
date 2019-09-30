using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    static class Program
    {
        static T[] ReadArray<T>(this StreamReader sr, Converter<string, T> parse)
        {
            return Array.ConvertAll(sr.ReadLine().Split(' '), parse);
        }
        static double Solve(int A, int B, double[] p)
        {
            double correct = 1;
            double result = double.MaxValue;
            for (int i = 0; i <= A; i++)
            {
                result = Math.Min((A - i + B - i + 1) * correct + (A - i + B - i + 1 + B + 1) * (1 - correct), result);
                if (i < A) { correct *= p[i]; }
            }
            return Math.Min(result, B + 2);
        }
        static void Main(string[] args)
        {
            string name = "../A-large";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int[] n = sr.ReadArray(int.Parse);
                double[] p = sr.ReadArray(double.Parse);
                sw.WriteLine("Case #{0}: {1}", i, Solve(n[0], n[1], p));
                Console.WriteLine("Case #{0}: Done", i);
            }
            sw.Close();
            sr.Close();
        }
    }
}
