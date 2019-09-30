using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class D
    {
        private static ThreadStart s_threadStart = new D().Go;
        private static bool s_time = false;

        private void Test(int tt)
        {
            long K = GetInt();
            long C = GetInt();
            long S = GetInt();

            if (S * C < K)
            {
                Wl(tt, "IMPOSSIBLE");
                return;
            }

            Console.Write("Case #{0}: ", tt);

            long N = 1;
            for (int c = 0; c < C; c++)
            {
                N *= K;
            }

            bool first = true;
            long start = 1;
            long level = N / K;
            for (int k = 1; k <= K; k++)
            {
                start += level * (k - 1);
                level /= K;

                if (level == 0 || k == K)
                {
                    if (!first) Console.Write(" ");
                    first = false;
                    Console.Write(start);

                    level = N / K;
                    start = 1;
                }
            }
            Console.WriteLine();
        }

        #region Template

        private void Go()
        {
            int T = GetInt();
            for (int t = 1; t <= T; t++)
            {
                Test(t);
            }
        }

        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch();
            Thread main = new Thread(new ThreadStart(s_threadStart), 1 * 1024 * 1024 * 1024);
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