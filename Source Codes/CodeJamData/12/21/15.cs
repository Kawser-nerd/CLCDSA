using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codeforces
{
    class A
    {
        private static ThreadStart s_threadStart = new A().Go;
        private static bool s_time = false;

        private void Go()
        {
            int TT = GetInt();
            for (int tt = 1; tt <= TT; tt++)
            {
                int N = GetInt();
                List<int> s = GetIntArr(N);
                double S = s.Sum();

                Console.Write("Case #{0}: {1}", tt, "");

                for (int k = 0; k < N; k++)
                {
                        double perMin = 0.0;
                        double perMax = 100.0;
                        for (int ii = 0; ii < 40; ii++)
                        {
                            double per = (perMax + perMin) / 2;
                            double kScore = s[k] + S * per / 100;
                            double sLeft = S * (100 - per) / 100;
                            double sum = 0.0;
                            for (int i = 0; i < N; i++)
                            {
                                if (i == k) continue;
                                sum += Math.Max(0, kScore - s[i]);
                            }
                            if (sum < sLeft) perMin = per;
                            else perMax = per;
                        }
                        Console.Write(" " + perMin);
                }

                Console.WriteLine();
            }
        }

        #region Template

        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch();
            Thread main = new Thread(new ThreadStart(s_threadStart), 512 * 1024 * 1024);
            timer.Start();
            main.Start();
            main.Join();
            timer.Stop();
            if (s_time)
                Console.WriteLine(timer.ElapsedMilliseconds);
        }

        private static IEnumerator<string> ioEnum;
        private static string GetString()
        {
            while (ioEnum == null || !ioEnum.MoveNext())
            {
                ioEnum = Console.ReadLine().Split().AsEnumerable().GetEnumerator();
            }

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

        private static void Wl<T>(int testCase, T o)
        {
            Console.WriteLine("Case #{0}: {1}", testCase, o.ToString());
        }

        private static void Wl<T>(int testCase, IEnumerable<T> enumerable)
        {
            Wl(testCase, string.Join(" ", enumerable.Select(e => e.ToString()).ToArray()));
        }

        #endregion
    }
}