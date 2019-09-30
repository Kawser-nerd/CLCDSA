using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class BB
    {
        private static ThreadStart s_threadStart = new BB().Go;
        private static bool s_time = false;

        long N;
        long B;
        List<int> M;

        long Completed(long time, out long firstAvailable)
        {
            long count = 0;
            long completed = 0;
            firstAvailable = -1;
            for (int i = 0; i < B; i++)
            {
                completed += time / M[i];

                if (time % M[i] == 0)
                {
                    count++;
                }
            }

            completed += B - count;

            if (completed < N && completed + count >= N)
            {
                long queue = N - 1 - completed;
                for (int i = 0; i < B; i++)
                {
                    if (firstAvailable < 0 && time % M[i] == 0)
                    {
                        if (queue-- == 0)
                            firstAvailable = i;
                    }
                }
            }

            return completed + count;
        }

        private void Test(int tt)
        {
            B = GetInt();
            N = GetInt();
            M = GetIntArr((int)B);

            long lo = 0;
            long hi = M.Max() * N;
            long mi;
            long firstAvailable = -1;
            long completed;

            while (lo + 1 < hi)
            {
                mi = (lo + hi) / 2;
                completed = Completed(mi, out firstAvailable);
                if (completed >= N)
                    hi = mi;
                else
                    lo = mi;
            }

            long ans = 0;
            long queue = 0;

            long time = lo - 1;
            if (time < 0)
            {
                time = 0;
                queue = N - 1;
            }

            while(true)
            {
                completed = Completed(time, out ans);
                time++;
                if (completed >= N)
                {
                    Wl(tt, ans + 1);
                    return;
                }
            }
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