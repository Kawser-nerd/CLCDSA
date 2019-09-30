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

        void Print(bool[,] dots)
        {
            for (int i = 0; i < dots.GetLength(0); i++)
            {
                for (int j = 0; j < dots.GetLength(1); j++)
                {
                    if (i == 0 && j == 0) Console.Write("c");
                    else Console.Write(dots[i, j] ? "." : "*");
                }
                Console.WriteLine();
            }
        }

        private void Test(int tt)
        {
            int R = GetInt();
            int C = GetInt();
            int stars = GetInt();
            int dots = R * C - stars;
            bool[,] tab = new bool[R, C];
            tab[0, 0] = true;
            bool imposible = false;
            if (dots == 1) { }
            else if (R == 1)
            {
                for (int i = 0; i < dots; i++)
                {
                    tab[0, i] = true;
                }
            }
            else if (C == 1)
            {
                for (int i = 0; i < dots; i++)
                {
                    tab[i, 0] = true;
                }
            }
            else if (R == 2)
            {
                if (dots % 2 != 0 || dots == 2) imposible = true;
                else
                {
                    for (int i = 0; i < dots / 2; i++)
                    {
                        tab[0, i] = tab[1, i] = true;
                    }
                }
            }
            else if (C == 2)
            {
                if (dots % 2 != 0 || dots == 2) imposible = true;
                else
                {
                    for (int i = 0; i < dots / 2; i++)
                    {
                        tab[i, 0] = tab[i, 1] = true;
                    }
                }
            }
            else
            {
                if (dots == 2 || dots == 3 || dots == 5 || dots == 7) imposible = true;
                else
                {
                    int x = 2 * (R + C) - 4;
                    if (dots >= x)
                    {
                        dots -= x;
                        for (int i = 0; i < C; i++)
                        {
                            tab[0, i] = tab[1, i] = true;
                        }
                        for (int i = 0; i < R; i++)
                        {
                            tab[i, 0] = tab[i, 1] = true;
                        }
                        for (int i = 2; i < R && dots > 0; i++)
                        {
                            for (int j = 2; j < C && dots > 0; j++)
                            {
                                tab[i, j] = true;
                                dots--;
                            }
                        }
                    }
                    else
                    {
                        if (dots % 2 != 0)
                        {
                            tab[2, 2] = true;
                            dots--;
                        }
                        tab[0, 0] = tab[0, 1] = tab[1, 0] = tab[1, 1] = true;
                        dots -= 4;
                        if (dots > 0)
                        {
                            tab[2, 0] = tab[2, 1] = true;
                            dots -= 2;
                        }
                        if (dots > 0)
                        {
                            tab[0, 2] = tab[1, 2] = true;
                            dots -= 2;
                        }

                        for (int i = 3; i < R && dots > 0; i++)
                        {
                            tab[i, 0] = tab[i, 1] = true;
                            dots -= 2;
                        }
                        for (int i = 3; i < C && dots > 0; i++)
                        {
                            tab[0, i] = tab[1, i] = true;
                            dots -= 2;
                        }
                    }
                }
            }

            if (imposible)
            {
                Wl(tt, "");
                Console.WriteLine("Impossible");
            }
            else
            {
                Wl(tt, "");
                Print(tab);
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