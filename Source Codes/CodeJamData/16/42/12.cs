using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.IO;

namespace BestR2
{
    public class B
    {
        public const string PATH_IN = @"C:\Users\sergey.shcheglov\Downloads\B-small-attempt0 (1).in";
        public const string PATH_OUT = @"D:\Dropbox\Competitions\GCJ16\R2\out.txt";

        static void Main(string[] args)
        {
            var s = new B();

            var lines = File.ReadAllLines(PATH_IN);

            var res = s.Solve(lines);

            File.WriteAllLines(PATH_OUT, res);
        }

        int GetInt(string s)
        {
            return int.Parse(s.Trim());
        }

        int[] GetIntArray(string s)
        {
            return s.Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
        }

        double[] GetDoubleArray(string s)
        {
            return s.Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(d=>double.Parse(d,CultureInfo.InvariantCulture)).ToArray();
        }

        public string[] Solve(string[] INPUT)
        {
            int cases = int.Parse(INPUT[0]);
            string[] res = new string[cases];

            int LINEIDX = 1;

            for (int test = 0; test < cases; test++)
            {
                int[] l = GetIntArray(INPUT[LINEIDX++]);
                int N = l[0];
                int K = l[1];
                double[] vals = GetDoubleArray(INPUT[LINEIDX++]);

                string ans = BruteForce(N, K, vals).ToString("0.0#########");

                Console.WriteLine("Case #{0}: {1}", (test + 1), ans);
                res[test] = string.Format("Case #{0}: {1}", (test + 1), ans);


            }
            return res;
        }

        double BruteForce(int N, int K, double[] vals)
        {
            double res = 0;
            List<int> all = new List<int>();
            for (int mask = 0; mask < 1 << N; mask++)
            {
                int k = 0;
                for (int i = 0; i < N; i++)
                    if ((mask & (1 << i)) > 0)
                    {
                        k++;
                    }
                if (k == K)
                    all.Add(mask);
            }

            List<int> sec = new List<int>();
            for (int mask = 0; mask < 1 << K; mask++)
            {
                int k = 0;
                for (int i = 0; i < K; i++)
                    if ((mask & (1 << i)) > 0)
                    {
                        k++;
                    }
                if (k == K / 2)
                    sec.Add(mask);
            }


            for (int q = 0; q < all.Count; q++)
            {
                int mask = all[q];
                double x = 0.0;
                for (int w = 0; w < sec.Count; w++)
                {
                    int pat = sec[w];
                    int k = 0;
                    double y = 1.0;
                    for (int i = 0; i < N; i++)
                        if ((mask & (1 << i)) > 0)
                        {
                            if ((pat & (1 << k)) > 0)
                            {
                                y *= vals[i];
                            }
                            else
                            {
                                y *= (1.0 - vals[i]);
                            }
                            k++;
                        }
                    x += y;
                }
                res = Math.Max(res, x);
            }

            return res;
        }
    }
}
