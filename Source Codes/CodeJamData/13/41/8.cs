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

        class Pair
        {
            public int A, B;
            public Pair(int a, int b)
            {
                A = a; B = b;
            }
        }

        long mod = 1000002013;
        int N;
        int M;
        List<Pair> points;

        void Swap(int i1, int i2)
        {
            int tmp = points[i1].B;
            points[i1].B = points[i2].B;
            points[i2].B = tmp;
        }

        private void Test(int tt)
        {
            N = GetInt();
            M = GetInt();
            points = new List<Pair>();
            for (int i = 0; i < M; i++)
            {
                int a = GetInt();
                int b = GetInt();
                int c = GetInt();
                for (int j = 0; j < c; j++)
                {
                    points.Add(new Pair(a, b));
                }
            }
            points.Sort((a, b) => a.A.CompareTo(b.A));
            long ret = 0;
            int K = points.Count;

            long orig = 0;
            for (int i = 0; i < K; i++)
            {
                long tmp = points[i].B - points[i].A;
                orig = (orig + GetVal(tmp)) % mod;
            }

            for (int i = 0; i < K; i++)
            {
                int ind2swap = -1;
                int max = points[i].B;
                int pos = i + 1;
                while (pos < K)
                {
                    if (points[pos].A > points[i].A) break;
                    pos++;
                }
                while (pos < K)
                {
                    if (points[pos].A > points[i].B) break;
                    if (points[pos].B > points[i].B)
                    {
                        Swap(i, pos);
                    }
                    pos++;
                }
                long tmp = (points[i].B - points[i].A);
                ret = (ret + GetVal(tmp)) % mod;
            }

            Wl(tt, (orig - ret) % mod);
        }

        long GetVal(long tmp)
        {
            long add = (tmp * N) % mod;
            add = (add - ((tmp * (tmp - 1)) / 2) % mod) % mod;
            return add;
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