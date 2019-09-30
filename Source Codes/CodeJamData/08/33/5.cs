using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CodeJam3
{
    class Program
    {
        /* PROBLEM 3 */

        static void Main(string[] args)
        {
            String filename = "C-small";
            TextReader tr = new StreamReader(filename + ".in");
            TextWriter tw = new StreamWriter(filename + ".out.txt");

            long modder = 1000000007;
            int KK = getInt(tr);

            for (int kk = 0; kk < KK; kk++)
            {
                // n, m, X, Y and Z 
                long[] pp = getLongs(tr);
                long n = pp[0], m = pp[1],
                    X = pp[2], Y = pp[3], Z = pp[4];

                long[] A = new long[m];

                for (int i = 0; i < m; i++)
                    A[i] = getLong(tr);


                long[] t = new long[n];
                long[] count = new long[n];

                for (int i = 0; i < n; i++)
                {
                    t[i] = A[i % m];
                    A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
                }

                for (long i = 0; i < n; i++)
                {
                    long temp = 1;
                    for (int j = 0; j < i; j++)
                    {
                        if (t[j] < t[i])
                        {
                            temp += (count[j] % modder);
                            temp %= modder;
                        }
                    }
                    count[i] = temp;
                    // Console.WriteLine(count[i]+ "*");
                }

                long result = 0;
                for (int i = 0; i < n; i++)
                {
                    result += (count[i] % modder);
                    result %= modder;
                }

                Console.WriteLine("Case #{0}: {1}",(kk+1),result);
                tw.WriteLine("Case #{0}: {1}", (kk + 1), result);

            }
            tr.Close();
            tw.Close();
            Console.Read();
        }

        private static int getInt(TextReader tr)
        {
            return Convert.ToInt32(tr.ReadLine());
        }

        private static int[] getInts(TextReader tr)
        {
            String[] param = tr.ReadLine().Split(' ');
            int[] ret = new int[param.Length];
            for (int i = 0; i < param.Length; i++)
                ret[i] = Convert.ToInt32(param[i]);
            return ret;
        }

        private static long getLong(TextReader tr)
        {
            return Convert.ToInt64(tr.ReadLine());
        }

        private static long[] getLongs(TextReader tr)
        {
            String[] param = tr.ReadLine().Split(' ');
            long[] ret = new long[param.Length];
            for (int i = 0; i < param.Length; i++)
                ret[i] = Convert.ToInt64(param[i]);
            return ret;
        }

        private static double getDouble(TextReader tr)
        {
            return Convert.ToDouble(tr.ReadLine());
        }

        private static double[] getDoubles(TextReader tr)
        {
            String[] param = tr.ReadLine().Split(' ');
            double[] ret = new double[param.Length];
            for (int i = 0; i < param.Length; i++)
                ret[i] = Convert.ToDouble(param[i]);
            return ret;
        }

        private static String getString(TextReader tr)
        {
            return tr.ReadLine();
        }

        private static String[] getStrings(TextReader tr)
        {
            String[] param = tr.ReadLine().Split(' ');
            return param;
        }
    }
}
