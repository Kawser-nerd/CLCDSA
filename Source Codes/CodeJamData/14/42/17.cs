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

        private void Test(int tt)
        {
            int N = GetInt();
            List<int> A = GetIntArr(N);

            int s = 0;
            int e = N - 1;
            int ans = 0;
            while (s + 1 < e)
            {
                int min = int.MaxValue;
                int minpos = -1;
                for (int i = s; i <= e; i++)
                {
                    if (A[i] < min) { min = A[i]; minpos = i; }
                }
                if (minpos == s) s++;
                else if (minpos == e) e--;
                else
                {
                    if (e - minpos < minpos - s)
                    {
                        ans += (e - minpos);
                        for (int i = minpos; i < e; i++)
                        {
                            A[i] = A[i + 1];
                        }
                        e--;
                    }
                    else
                    {
                        ans += (minpos - s);
                        for (int i = minpos; i > s; i--)
                        {
                            A[i] = A[i - 1];
                        }
                        s++;
                    }
                }
            }

            Wl(tt, ans);
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