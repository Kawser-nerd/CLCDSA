using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.IO;
using System.Globalization;
using System.Collections;

namespace Marius.C
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            Thread.CurrentThread.CurrentUICulture = CultureInfo.InvariantCulture;

            var reader = Console.In;
            var writer = Console.Out;

            if (args.Length == 2)
            {
                reader = File.OpenText(args[0]);
                writer = new StreamWriter(args[1]);
            }

            int numCases = int.Parse(reader.ReadLine().Trim());

            for (int n = 1; n <= numCases; n++)
            {
                //n, m, X, Y and Z
                var data = reader.ReadLine().Split().Select(s => long.Parse(s)).ToArray();

                var count = data[0];
                var m = data[1];
                var X = data[2];
                var Y = data[3];
                var Z = data[4];

                /*
                    for i = 0 to n-1
                      print A[i mod m]
                      A[i mod m] = (X * A[i mod m] + Y * (i + 1)) mod Z
                */

                var A = new long[m];
                for (int i = 0; i < m; i++)
                {
                    A[i] = long.Parse(reader.ReadLine().Trim());
                }

                var G = new long[count];
                for (int i = 0; i < count; i++)
                {
                    G[i] = A[i % m];
                    A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
                }

                var result = Count(G);
                writer.WriteLine("Case #{0}: {1}", n, result);
            }

            if (reader != Console.In)
                reader.Close();
            if (writer != Console.Out)
                writer.Close();
        }

        private static string Count(long[] A)
        {
            var C = new BigInteger[A.Length];
            for (int i = 0; i < A.Length; i++)
            {
                C[i] = 1L;
            }

            for (int i = 0; i < A.Length; i++)
            {
                for (int k = i; k < A.Length; k++)
                {
                    if (A[i] < A[k])
                        C[k] = (C[k] + C[i]);
                }
            }

            BigInteger result = new BigInteger();
            for (int i = 0; i < C.Length; i++)
            {
                result += C[i];
                result = result % 1000000007;
            }

            return result.ToString();
        }
    }
}
