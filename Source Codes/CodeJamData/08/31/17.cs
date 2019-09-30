using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace jam
{
    class Program
    {
        static void Main(string[] args)
        {
            string inFile = (args.Length < 1) ? "test.in" : args[0];
            string outFile = (args.Length < 2) ? "test.out" : args[1];

            using (TextReader tr = new StreamReader(inFile))
            using (TextWriter tw = new StreamWriter(outFile))
            {
                int N = Convert.ToInt32(tr.ReadLine());

                for (int i = 1; i <= N; i++)
                {
                    List<long> inp = ReadVector(tr);
                    List<long> f = ReadVector(tr);

                    // read input
                    tw.WriteLine("Case #{0}: {1}", i, Solve(inp[0], inp[1], f));
                }
            }
        }

        private static List<long> ReadVector(TextReader tr)
        {
            List<long> r = new List<long>();
            string[] val = tr.ReadLine().Split(' ');
            foreach (string v in val)
            {
                r.Add(Convert.ToInt64(v));
            }
            return r;
        }

        public static long Solve(long p, long k, List<long> f)
        {
            long r = 0;

            f.Sort();
            f.Reverse();

            for (long i = 0; i < p; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    int l = (int)(i * k) + j;
                    if (l >= f.Count) break;
                    r += f[l] * (i + 1);
                }
            }

            return r;
        }
    }
}
