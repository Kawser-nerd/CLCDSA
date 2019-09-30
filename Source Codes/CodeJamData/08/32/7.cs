using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CodeJam2
{
    class Program
    {
        /* PROBLEM 2 */

        static void Main(string[] args)
        {
            String filename = "B-small";
            TextReader tr = new StreamReader(filename + ".in");
            TextWriter tw = new StreamWriter(filename + ".out.txt");

            int KK = getInt(tr);
            for (int kk = 0; kk < KK; kk++)
            {
                string cc = getString(tr);
                char[] c = cc.ToCharArray();
                count = 0;
                doSearch(c, 1, c[0] + "", 0);
                Console.WriteLine("Case #{0}: {1}",(kk+1),count);
                tw.WriteLine("Case #{0}: {1}", (kk + 1), count);
            }
            tr.Close();
            tw.Close();
            Console.Read();
        }

        private static long count;

        // level start at 1
        private static void doSearch(char[] c, int level, string buff, long sofar)
        {
            if (level > c.Length - 1)
            {
                long b = Convert.ToInt64(buff);
                sofar += b;

                // Console.WriteLine("num = " + sofar);
                // end
                if (sofar % 2 == 0 || sofar % 3 == 0 || sofar % 5 == 0 || sofar % 7 == 0)
                {
                    count++;
                }
            }
            else
            {
                // continue
                doSearch(c, level + 1, buff + c[level],sofar);

                
                long b = Convert.ToInt64(buff);
                sofar += b;

                // plus
                buff = "";
                doSearch(c, level + 1, buff + c[level], sofar);
                
                // minus
                buff = "-";
                doSearch(c, level + 1, buff + c[level], sofar);

            }
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
