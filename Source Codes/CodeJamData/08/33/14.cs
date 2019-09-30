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
                int T = Convert.ToInt32(tr.ReadLine());


                for (int i = 1; i <= T; i++)
                {
                    List<long> inp = ReadVector(tr);
                    List<long> A = ReadVectorLines(tr, inp[1]);
                    tw.WriteLine("Case #{0}: {1}", i, Alg.Solve(inp[0], inp[1], inp[2], inp[3], inp[4], A));
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

        private static List<long> ReadVectorLines(TextReader tr, long m)
        {
            List<long> r = new List<long>();
            for (int i = 0; i < m; i++)
            {
                r.Add(Convert.ToInt64(tr.ReadLine()));
            }
            return r;
        }

        private class Alg
        {
            private const long q = 1000000007;

            public static long Solve(long n, long m, long X, long Y, long Z, List<long> A)
            {
                long[] s = new long[n];
                for (long i = 0; i < n; i++)
                {
                    s[i] = A[(int)(i % m)];
                    A[(int)(i % m)] = (X * A[(int)(i % m)] + Y * (i + 1)) % Z;
                }

                long[] r = new long[n];

                for (long i = n - 1; i >=0; i--)
                {
                    r[i] = 1;

                    for (long j = i+1; j < n; j++)
                    {
                        if (s[j] > s[i])
                        {
                            r[i] = (r[i] + r[j]) % q;
                        }
                    }
                }

                long rr = 0;
                for (long i = 0; i < n; i++)
                {
                    rr = (rr + r[i]) % q;
                }

                return rr;
            }
        }
    }
}
