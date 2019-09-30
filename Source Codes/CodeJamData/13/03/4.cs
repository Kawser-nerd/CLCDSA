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

        long[] l = new long[]
        {
            121,
            1,
            484,
            4,
            9,
            1002001,
            10201,
            1234321,
            12321,
            14641,
            4008004,
            40804,
            44944,
            10000200001,
            100020001,
            10221412201,
            102030201,
            104060401,
            12102420121,
            121242121,
            12345654321,
            123454321,
            125686521,
            40000800004,
            400080004,
            404090404,
            1000002000001,
            1002003002001,
            1004006004001,
            1020304030201,
            1022325232201,
            1024348434201,
            1210024200121,
            1212225222121,
            1214428244121,
            1232346432321,
            1234567654321,
            4000008000004,
            4004009004004
        };

        private void Test(int tt)
        {
            long A = GetLong();
            long B = GetLong();
            int count = 0;

            foreach (long x in l)
            {
                if (A <= x && x <= B)
                    count++;
            }

            Wl(tt, count);
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