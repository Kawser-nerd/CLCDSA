using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class C
    {
        private static ThreadStart s_threadStart = new C().Go;
        private static bool s_time = false;

        public static long AreaPoly2D(long[] p1, long[] p2, long[] p3)
        {
            return AreaPoly2D(p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]);
        }

        public static long AreaPoly2D(params long[] points)
        {
            long area = 0;
            long x1, y1, x2, y2;
            int n = points.Length / 2;
            if (n > 2)
            {
                x2 = points[2 * (n - 1)];
                y2 = points[2 * (n - 1) + 1];
                for (int i = 0; i < n; i++)
                {
                    x1 = x2;
                    y1 = y2;
                    x2 = points[2 * i];
                    y2 = points[2 * i + 1];
                    area += (y1 + y2) * (x1 - x2);
                }
            }
            return area;
        }

        private void Test(int tt)
        {
            int N = GetInt();

            List<long[]> points = new List<long[]>();
            long[] point;
            for (int i = 0; i < N; i++)
            {
                point = new long[] { GetInt(), GetInt() };
                points.Add(point);
            }
            
            Wl(tt, "");

            if(N < 4)
            {
                for (int i = 0; i < N; i++)
                {
                    Console.WriteLine("0");
                }
                return;
            }

            for (int i = 0; i < N; i++)
            {
                int ans = int.MaxValue;
                for (int j = 0; j < N; j++)
                {
                    if (i != j)
                    {
                        int neg = 0;
                        int pos = 0;

                        for (int k = 0; k < N; k++)
                        {
                            long area = AreaPoly2D(points[i], points[j], points[k]);
                            if (area < 0) neg++;
                            if (area > 0) pos++;
                        }

                        ans = Math.Min(ans, pos);
                        ans = Math.Min(ans, neg);
                    }
                }

                Console.WriteLine(ans);
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