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
        private static bool s_time = false;

        double Bin(long n, long k, long h)
        {
            long[] ar = new long[n + 1];
            ar[0] = 1;
            ar[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                ar[i] = 1;
                for (int j = i-1; j >= 1; j--)
                {
                    ar[j] = ar[j - 1] + ar[j];
                }
            }

            double ret = 0.0;
            long x;
            for (long i = 0; i <= n; i++)
            {
                x = n - i;
                if (i >= k || (x > h && (x - h + i) >= k))
                    ret += ar[i];

            }
            return ret;
        }

        private void Test(int tt)
        {
            long N = GetInt();
            long X = GetInt();
            long Y = GetInt();

            X = Math.Abs(X);

            long level = X + Y;

            if (level == 0)
            {
                Wl(tt, 1.0);
                return;
            }

            long height = level;
            level--;

            if (N <= (level * (level + 1)) / 2)
            {
                Wl(tt, 0.0);
                return;
            }
            if (N >= ((level + 2) * (level + 3)) / 2)
            {
                Wl(tt, 1.0);
                return;
            }

            long left = N - (level * (level + 1)) / 2;
            long need = Y + 1;

            if (X == 0 && Y == height)
            {
                Wl(tt, 0.0);
                return;
            }


            double ret = Bin(left, need, height);
            for (int i = 0; i < left; i++)
            {
                ret *= 0.5;
            }

            Wl(tt, ret);
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