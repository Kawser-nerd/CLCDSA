using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class B
    {
        private static ThreadStart s_threadStart = new B().Go;

        private double Prob(IList<double> p, int k)
        {
            int n = p.Count;

            double[,] dp = new double[n, k + 1];

            dp[0, 0] = 1.0 - p[0];
            dp[0, 1] = p[0];

            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < k + 1; j++)
                {
                    dp[i, j] = dp[i - 1, j] * (1.0 - p[i]);
                    if (j > 0)
                        dp[i, j] += dp[i - 1, j - 1] * p[i];
                }
            }

            return dp[n - 1, k];
        }


        private int BitCount(int mask)
        {
            int count = 0;
            while(mask > 0)
            {
                count += (mask & 1);
                mask >>= 1;
            }
            return count;
        }

        private void Test(int tt)
        {
            int N = GetInt();
            int K = GetInt();
            double[] p = new double[N];
            for (int i = 0; i < N; i++)
            {
                p[i] = GetDouble();
            }
            Array.Sort(p);

            double ans = 0.0;

            for (int mask = 0; mask <= K; mask++)
            {
                List<double> prob = new List<double>();
                for (int i = 0; i < mask; i++)
                {
                    prob.Add(p[i]);
                }
                for (int i = N-1; prob.Count < K; i--)
                {
                    prob.Add(p[i]);
                }

                double cand = Prob(prob, K / 2);
                if (cand > ans)
                {
                    ans = cand;
                }
            }

            Wl(ans);
        }

        #region Template

        private static StringBuilder output = new StringBuilder();

        private void Go()
        {
            int T = GetInt();
            for (int t = 1; t <= T; t++)
            {
                output.AppendFormat("Case #{0}: ", t);
                Test(t);
            }
        }

        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch();
            output.Length = 0;
            Thread main = new Thread(new ThreadStart(s_threadStart));
            timer.Start();
            main.Start();
            main.Join();
            Console.Write(output);
            timer.Stop();
            Console.Error.WriteLine(timer.ElapsedMilliseconds);
        }

        private static IEnumerator<string> ioEnum;
        private static string GetString()
        {
            do
            {
                while (ioEnum == null || !ioEnum.MoveNext())
                {
                    ioEnum = Console.ReadLine().Split().AsEnumerable().GetEnumerator();
                }
            } while (string.IsNullOrEmpty(ioEnum.Current));

            return ioEnum.Current;
        }

        private static int GetInt()
        {
            return int.Parse(GetString());
        }

        private static long GetLong()
        {
            return long.Parse(GetString());
        }

        private static double GetDouble()
        {
            return double.Parse(GetString());
        }

        private static List<int> GetIntArr(int n)
        {
            List<int> ret = new List<int>(n);
            for (int i = 0; i < n; i++)
            {
                ret.Add(GetInt());
            }
            return ret;
        }

        private static void Wl<T>(T o)
        {
            W(o);
            output.Append(Console.Out.NewLine);
        }

        private static void Wl<T>(IEnumerable<T> enumerable)
        {
            W(enumerable);
            output.Append(Console.Out.NewLine);
        }

        private static void W<T>(T o)
        {
            output.Append(o.ToString());
        }

        private static void W<T>(IEnumerable<T> enumerable)
        {
            W(string.Join(" ", enumerable.Select(e => e.ToString()).ToArray()));
        }

        #endregion
    }
}