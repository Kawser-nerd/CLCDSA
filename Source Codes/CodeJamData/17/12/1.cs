using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using Tup = System.Tuple<int, int>;

namespace Codejam
{
    class B
    {
        private static ThreadStart s_threadStart = new B().Go;

        private void Test(int tt)
        {
            int N = GetInt();
            int P = GetInt();
            List<int> R = GetIntArr(N);
            List<Tup>[] Q = new List<Tup>[N];
            for (int i = 0; i < N; i++)
            {
                var li = Q[i] = new List<Tup>();
                for (int j = 0; j < P; j++)
                {
                    int x = GetInt();
                    int hi = (int)Math.Floor(x / 0.9 / R[i]);
                    int low = (int)Math.Ceiling(x / 1.1 / R[i]);
                    if (low <= hi)
                        li.Add(new Tup(low, hi));
                }
                li.Sort();
            }

            int[] pointer = new int[N];
            int ans = 0;
            bool search = true;
            while (true)
            {
                int q = 0;
                int oldq = -1;
                while (oldq < q)
                {
                    oldq = q;
                    for (int i = 0; i < N; i++)
                    {
                        while (pointer[i] < Q[i].Count && Q[i][pointer[i]].Item2 < q)
                            pointer[i]++;

                        if (pointer[i] >= Q[i].Count)
                        {
                            Wl(ans);
                            return;
                        }
                        q = Math.Max(q, Q[i][pointer[i]].Item1);
                    }
                }

                ans++;

                for (int i = 0; i < N; i++)
                {
                    pointer[i]++;
                }
            }
        }

        #region Template

        private static StringBuilder output = new StringBuilder();

        private void Go()
        {
            int T = GetInt();
            for (int t = 1; t <= T; t++)
            {
                output.AppendFormat("Case #{0}: ", t);
                Test(t);
            }
        }

        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch();
            output.Length = 0;
            Thread main = new Thread(new ThreadStart(s_threadStart));
            timer.Start();
            main.Start();
            main.Join();
            Console.Write(output);
            timer.Stop();
            Console.Error.WriteLine(timer.ElapsedMilliseconds);
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

        private static void Wl<T>(T o)
        {
            W(o);
            output.Append(Console.Out.NewLine);
        }

        private static void Wl<T>(IEnumerable<T> enumerable)
        {
            W(enumerable);
            output.Append(Console.Out.NewLine);
        }

        private static void W<T>(T o)
        {
            output.Append(o.ToString());
        }

        private static void W<T>(IEnumerable<T> enumerable)
        {
            W(string.Join(" ", enumerable.Select(e => e.ToString()).ToArray()));
        }

        #endregion
    }
}