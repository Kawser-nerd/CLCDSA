using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class gcj2009
    {
        static int[] max = new int[(1 << 10)];
        static int[,] ps = new int[10, (1 << 9)];

        static long solve(int from, int to, int p)
        {
            if (from >= to) return 0;
            int m = 0;
            int pos = -1;
            for (int i = from; i < to; ++i) if (max[i] > m) { m = max[i]; pos = i; }
            if (m == 0) return 0;

            int[] pmax = new int[to - from + 1];
            for (int i = from; i < to; ++i) { pmax[i - from] = max[i]; --max[i]; }
            long res = ps[p, from / (1 << (p + 1))] + solve(from, from + (to - from) / 2, p - 1) + solve(from + (to - from) / 2, to, p - 1);
            if (m == p + 1)
            {
                return res;
            }
            for (int i = from; i < to; ++i) max[i] = pmax[i - from];
            {
                long nres = solve(from, from + (to - from) / 2, p - 1) + solve(from + (to - from) / 2, to, p - 1);
                res = Math.Min(res, nres);
            }
            return res;

        }

        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    int NUM = int.Parse(sr.ReadLine().Trim());
                    for (int i = 0; i < NUM; ++i)
                    {
                        int p = int.Parse(sr.ReadLine().Trim());
                        string[] strs = sr.ReadLine().Trim().Split(' ');
                        for (int j = 0; j < (1<<p); ++j) max[j] = p - int.Parse(strs[j]);
                        for (int j = 0; j < p; ++j)
                        {
                            strs = sr.ReadLine().Trim().Split(' ');
                            for (int k = 0; k < strs.Length; ++k)
                            {
                                ps[j, k] = int.Parse(strs[k]);
                            }
                        }

                        string rstr = "Case #" + (i + 1) + ": " + solve(0, (1<<p), p - 1);
                        Console.WriteLine(rstr);
                        sw.WriteLine(rstr);
                    }

                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }
    }
}
