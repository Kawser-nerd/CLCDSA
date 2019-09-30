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

        private void Test(int tt)
        {
            int R = GetInt();
            int N = GetInt();
            int M = GetInt();
            int K = GetInt();

            Wl(tt, "");
            int[] counts = new int[10];
            for (int xx = 0; xx < R; xx++)
            {
                List<int> nums = GetIntArr(K);
                for (int i = 0; i < 10; i++)
                {
                    counts[i] = 0;
                }
                bool aTwo = false;
                foreach (int x in nums)
                {
                    if (x % 125 == 0)
                    {
                        counts[5] = 3;
                    }
                    else if (x % 25 == 0)
                    {
                        counts[5] = Math.Max(counts[5], 2);
                    }
                    else if (x % 5 == 0)
                    {
                        counts[5] = Math.Max(counts[5], 1);
                    }

                    if (x % 27 == 0)
                    {
                        counts[3] = 3;
                    }
                    else if (x % 9 == 0)
                    {
                        counts[3] = Math.Max(counts[3], 2);
                    }
                    else if (x % 3 == 0)
                    {
                        counts[3] = Math.Max(counts[3], 1);
                    }

                    if (x % 64 == 0)
                    {
                        counts[2] = 6;
                    }
                    else if (x % 32 == 0)
                    {
                        counts[2] = Math.Max(counts[2], 5);
                        aTwo = true;
                    }
                    else if (x % 16 == 0)
                    {
                        counts[2] = Math.Max(counts[2], 4);
                    }
                    else if (x % 8 == 0)
                    {
                        counts[2] = Math.Max(counts[2], 3);
                        aTwo = true;
                    }
                    else if (x % 4 == 0)
                    {
                        counts[2] = Math.Max(counts[2], 2);
                    }
                    else if (x % 2 == 0)
                    {
                        counts[2] = Math.Max(counts[2], 1);
                        aTwo = true;
                    }
                }

                string ans = "";
                for (int i = 0; i < counts[5]; i++)
                {
                    ans += "5";
                }
                for (int i = 0; i < counts[3]; i++)
                {
                    ans += "3";
                }

                int twos = counts[2];
                int n = ans.Length;
                if (n == 2)
                {
                    if (aTwo) ans += "2";
                    else if (twos > 1) ans += "4";
                    else ans += "2";
                }
                else if (n == 1)
                {
                    if (aTwo)
                    {
                        ans += "2";
                        if (twos > 2) ans += "4";
                        else ans += "2";
                    }
                    else if (twos > 3) ans += "44";
                    else if (twos > 2) ans += "42";
                    else ans += "22";
                }
                else
                {
                    if (twos > 5) ans = "444";
                    else if (twos > 4)
                    {
                        ans = "244";
                    }
                    else if (twos > 3)
                    {
                        ans = "244";
                    }
                    else
                        ans = "222";
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