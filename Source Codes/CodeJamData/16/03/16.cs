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
            int N = GetInt();
            int J = GetInt();

            Wl(tt, "");

            string s = "{0} 3 4 5 6 7 8 9 10 11";
            int count = 0;
            StringBuilder sb = new StringBuilder("10000000000000000000000000000001");

            for (int i = 0; i < 3; i++)
            {
                if (i == 0)
                {
                    sb[1] = sb[2] = '0';
                    sb[3] = sb[4] = '0';
                }
                if (i == 1)
                {
                    sb[1] = sb[2] = '0';
                    sb[3] = sb[4] = '1';
                }
                if (i == 2)
                {
                    sb[1] = sb[2] = '1';
                    sb[3] = sb[4] = '0';
                }

                for (int j = 5; j < 31; j+=2)
                {
                    for (int k = 6; k < 31; k+=2)
                    {
                        sb[j] = sb[k] = '1';
                        Console.WriteLine(s, sb.ToString());
                        sb[j] = sb[k] = '0';
                        count++;
                        if (count == J) return;
                    }
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