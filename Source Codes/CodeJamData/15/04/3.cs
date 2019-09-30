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
            int X = GetInt();
            int R = GetInt();
            int C = GetInt();

            int m = Math.Min(R, C);
            int M = Math.Max(R, C);

            if (X >= 7 || (m * M) % X != 0 || M < X || m < (X + 1) / 2)
            {
                Wl(tt, "RICHARD"); return;
            }
            if (X <= 3)
            {
                Wl(tt, "GABRIEL"); return;
            }

            if (X == 4)
            {
                if (m == 2)
                {
                    Wl(tt, "RICHARD"); return;
                }
            }

            if (X == 5)
            {
                if (m == 3 && M == 5)
                {
                    Wl(tt, "RICHARD"); return;
                }
            }

            if (X == 6)
            {
                if (m == 3)
                {
                    Wl(tt, "RICHARD"); return;
                }
            }

            Wl(tt, "GABRIEL");
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