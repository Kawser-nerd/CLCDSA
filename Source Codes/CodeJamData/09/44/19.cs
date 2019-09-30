using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class gcj2009
    {
        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int i = 0; i < T; ++i)
                    {
                        int N=int.Parse(sr.ReadLine());
                        string[] lines = new string[N];
                        for (int j = 0; j < N; ++j) lines[j] = sr.ReadLine();

                        sw.WriteLine("Case #" + (i + 1) + ": " + solve(lines, N).ToString("f6"));
                    }
                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }

        private static int[,] vals;

        private static double slv(int i, int j)
        {
            double r = 0;
            r = (vals[i, 0] - vals[j, 0]) * (vals[i, 0] - vals[j, 0]) +
                (vals[i, 1] - vals[j, 1]) * (vals[i, 1] - vals[j, 1]);
            r = Math.Sqrt(r*1.0) + vals[i, 2] + vals[j, 2];

            return r / 2;
        }

        private static double solve(string[] lines, int N)
        {
            double r = 0;
            vals = new int[N, 3];
            for (int i = 0; i < N; ++i)
            {
                string[] strs = lines[i].Trim().Split(' ');
                for (int j = 0; j < 3; ++j) vals[i, j] = int.Parse(strs[j]);
            }
            if (N == 1) r = vals[0, 2];
            else if (N == 2)
            {
                r = slv(0, 1);
                r = Math.Min(r, Math.Max(vals[0,2], vals[1,2]));
            }
            else
            {
                r = Math.Max(slv(0, 1), vals[2, 2]);
                r = Math.Min(r, Math.Max(slv(0, 2), vals[1, 2]));
                r = Math.Min(r, Math.Max(slv(1, 2), vals[0, 2])); 
            }

            return r;
        }
    }
}
