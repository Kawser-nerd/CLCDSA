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

        int?[, , ,] dp;
        int Hd, B, D;

        int Get(int hd, int ad, int hk, int ak)
        {
            int? v = dp[hd, ad, hk, ak];
            if (v == null)
            {
                dp[hd, ad, hk, ak] = -1;
                v = -1;

                if (ad >= hk)
                {
                    v = 1;
                }
                else if (ak >= hd)
                {
                    int newAk = Math.Max(ak-D, 0);
                    if (newAk < hd)
                    {
                        v = Get(hd - newAk, ad, hk, newAk);
                        if(v >= 0)
                            v++;
                    }

                    if (Hd - ak > 0)
                    {
                        int w = Get(Hd - ak, ad, hk, ak);
                        if (w >= 0 && (v < 0 || w + 1 < v))
                            v = w + 1;
                    }
                }
                else
                {
                    v = Get(hd - ak, ad, hk - ad, ak);
                    if (v >= 0)
                        v++;

                    int? w = Get(hd - ak, ad + B, hk, ak);
                    if (w >= 0 && (v < 0 || w + 1 < v))
                        v = w + 1;

                    int newAk = Math.Max(ak - D, 0);
                    w = Get(hd - newAk, ad, hk, newAk);
                    if (w >= 0 && (v < 0 || w + 1 < v))
                        v = w + 1;
                }
            }

            dp[hd, ad, hk, ak] = v;
            return v.Value;
        }

        private void Test(int tt)
        {
            Hd = GetInt();
            int Ad = GetInt();
            int Hk = GetInt();
            int Ak = GetInt();
            B = GetInt();
            D = GetInt();

            int maxAd = Math.Max(Ad, Hk + B);

            dp = new int?[Hd + 1, maxAd + 1, Hk + 1, Ak + 1];

            int ans = Get(Hd, Ad, Hk, Ak);

            if (ans <= 0)
                Wl("IMPOSSIBLE");
            else
                Wl(ans);
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