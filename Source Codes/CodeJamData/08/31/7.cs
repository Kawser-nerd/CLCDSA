using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CodeJam1
{
    class Program
    {
        /* PROBLEM 1 */

        static void Main(string[] args)
        {
            String filename = "A-large";
            TextReader tr = new StreamReader(filename + ".in");
            TextWriter tw = new StreamWriter(filename + ".out.txt");

            int KK = getInt(tr);
            for (int kk = 0; kk < KK; kk++)
            {
                int[] pp = getInts(tr);
                int P = pp[0], K = pp[1], L = pp[2];
                if (L > P * K)
                {
                    Console.WriteLine("Case #{0}: Impossible", (kk + 1));
                    tw.WriteLine("Case #{0}: Impossible", (kk + 1));
                    continue;
                }

                int[] fr = getInts(tr);
                Array.Sort(fr);
                Array.Reverse(fr);

                long count = 0;
                int top = 0, level = 1, temp = 0;
                while (top != fr.Length)
                {
                    count += fr[top] * level;
                    top++; temp++;
                    if (temp == K)
                    {
                        temp = 0;
                        level++;
                    }
                        
                }

                Console.WriteLine("Case #{0}: {1}", (kk + 1), count);
                tw.WriteLine("Case #{0}: {1}", (kk + 1),count);

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

    public class Pnt
    {
        public long X { get; set; }
        public long Y { get; set; }

        public Pnt(long x, long y)
        {
            X = x;
            Y = y;
        }

        public override string ToString()
        {
            return string.Format("({0},{1})", X, Y);
        }
    }
}


