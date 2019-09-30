using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class A
    {
        private static ThreadStart s_threadStart = new A().Go;
        private static bool s_time = false;

        int BitCount(long x)
        {
            long sum = 0;
            while (x > 0)
            {
                sum += (x & 1);
                x >>= 1;
            }
            return (int)sum;
        }

        private void Test(int tt)
        {
            int N = GetInt();
            int L = GetInt();

            List<long> source = new List<long>();
            for (int i = 0; i < N; i++)
            {
                string s = GetString();
                source.Add(Convert.ToInt64(s, 2));
            }

            List<long> target = new List<long>();
            for (int i = 0; i < N; i++)
            {
                string s = GetString();
                target.Add(Convert.ToInt64(s, 2));
            }
            target.Sort();

            List<long> check = new List<long>(source);

            int ans = int.MaxValue;
            for (int i = 0; i < N; i++)
            {
                long x = source[i] ^ target[0];
                for (int j = 0; j < N; j++)
                {
                    check[j] = source[j] ^ x;
                }
                check.Sort();
                bool ok = true;
                for (int j = 0; j < N; j++)
                {
                    if (check[j] != target[j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    ans = Math.Min(ans, BitCount(x));
                }
            }

            if (ans == int.MaxValue) Wl(tt, "NOT POSSIBLE");
            else Wl(tt, ans);
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