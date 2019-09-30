using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codeforces
{
    class C
    {
        private static ThreadStart s_threadStart = new C().Go;
        private static bool s_time = false;

        private void Go()
        {
            int TT = GetInt();
            bool found = false;
            for (int tt = 1; tt <= TT; tt++)
            {
                Wl(tt, "");
                int N = GetInt();
                long N1 = 1<<N;
                List<int> list = GetIntArr(N);
                Dictionary<int, long> masks = new Dictionary<int, long>();
                for (int mask = 1; mask < N1; mask++)
                {
                    int sum = 0;
                    for (long p = 1, i = 0; p < N1; i++, p <<= 1)
                    {
                        if ((p & mask) != 0)
                            sum += list[(int)i];
                    }
                    if (masks.ContainsKey(sum))
                    {
                        found = true;
                        bool first = true;
                        for (long p = 1, i = 0; p < N1; i++, p <<= 1)
                        {
                            if ((p & masks[sum]) != 0)
                            {
                                if (!first) Console.Write(" ");
                                Console.Write(list[(int)i]);
                                first = false;
                            }
                        }
                        Console.WriteLine();
                        first = true;
                        for (long p = 1, i = 0; p < N1; i++, p <<= 1)
                        {
                            if ((p & mask) != 0)
                            {
                                if (!first) Console.Write(" ");
                                Console.Write(list[(int)i]);
                                first = false;
                            }
                        }
                        break;
                    }
                    else
                    {
                        masks[sum] = mask;
                    }
                }
                if(!found)
                    Console.Write("Impossible");
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