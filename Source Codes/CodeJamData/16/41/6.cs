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

        private void Test(int tt)
        {
            int N = GetInt();
            int R = GetInt();
            int P = GetInt();
            int S = GetInt();

            int M = (1<<N);

            //0 - P
            //1 - R
            //2 - S

            string[,] dp = new string[3, M + 1];

            string p, r, s;

            p = "P";
            r = "R";
            s = "S";

            for (int l = 1; l < N + 1; l++)
            {
                string pp = p.CompareTo(r) < 0 ? p + r : r + p;
                string rr = r.CompareTo(s) < 0 ? r + s : s + r;
                string ss = s.CompareTo(p) < 0 ? s + p : p + s;

                p = pp;
                r = rr;
                s = ss;
            }

            List<string> sorted = new List<string>();
            sorted.Add(p);
            sorted.Add(r);
            sorted.Add(s);
            sorted.Sort();

            foreach(string ss in sorted)
            {
                int cp = 0;
                int cr = 0;
                int cs = 0;

                foreach(char ch in ss)
                {
                    if (ch == 'P') cp++;
                    if (ch == 'R') cr++;
                    if (ch == 'S') cs++;

                    if(cp == P && cr == R && cs == S)
                    {
                        Wl(ss);
                        return;
                    }
                }
            }

            Wl("IMPOSSIBLE");
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