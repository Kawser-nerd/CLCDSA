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
            int R = GetInt();
            int C = GetInt();

            StringBuilder[] s = new StringBuilder[R];
            for (int i = 0; i < R; i++)
            {
                s[i] = new StringBuilder(GetString());
            }

            for (int i = 0; i < R; i++)
            {
                bool fill = DoRow(s[i]);
                if (fill)
                {
                    s[0] = new StringBuilder(s[i].ToString());
                    break;
                }
            }
            for (int i = 1; i < R; i++)
            {
                bool fill = DoRow(s[i]);
                if (!fill)
                    s[i] = new StringBuilder(s[i - 1].ToString());
            }

            Wl("");
            for (int i = 0; i < R; i++)
            {
                Wl(s[i]);
            }
        }

        bool DoRow(StringBuilder s)
        {
            char ch = (char)0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] != '?')
                {
                    ch = s[i];
                    break;
                }
            }
            if(ch == 0) return false;

            s[0] = ch;
            for(int i = 1; i < s.Length; i++)
            {
                if (s[i] == '?')
                    s[i] = s[i - 1];
            }
            return true;
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