using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var pathIn = @"D:\Projects\Google CodeJam 2013\Round 1B\B-small-attempt0.in";
            var pathOut = Path.ChangeExtension(pathIn, @"out");
            using (var input = new StreamReader(pathIn))
            {
                using (var output = new StreamWriter(pathOut, false) { AutoFlush = true })
                {
                    Solve(input, output);
                }
            }
        }

        private static void Solve(StreamReader input, StreamWriter output)
        {
            var T = Int32.Parse(input.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                var arr = input.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
                int N = arr[0];
                int X = arr[1];
                int Y = arr[2];

                double result = solver(X, Y, N);

                output.WriteLine("Case #{0}: {1}", t, result.ToString("f7", CultureInfo.InvariantCulture));
            }
        }

        private static double solver(int X, int Y, int N)
        {
            int l = ((Math.Abs(X) + Math.Abs(Y))) / 2;
            int lsize = 1;
            int size = 0;
            for (var i = 0; i < l; i++)
            {
                size += lsize;
                lsize += 4;
            }

            if (size >= N) return 0;

            int elemCount = N - size;
            
            int h = 2 * l;
            if (elemCount >= h + Y + 1) return 1;

            if (X == 0)
            {
                if (elemCount != lsize)
                    return 0;
                else return 1;
            }

            Int64 c = 0;
            for(int i = Y + 1; i <= elemCount; i++)
            {
                c += Comb(elemCount, i);
            }

            double result = c/Math.Pow(2, elemCount);
            return result;
        }

        private static Int64 Comb(int n, int m)
        {
            return Factor(n) / (Factor(m) * Factor(n - m));
        }

        private static Int64 Factor(int n)
        {
            Int64 result = 1;
            for (int x = 1; x <= n; x++)
            {
                result *= x;
            }

            return result;
        }


    }
}
