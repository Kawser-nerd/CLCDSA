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
            //Console.Error.WriteLine("processing" + tt);
            int L = GetInt();
            long X = GetLong();
            string s = GetString();

            List<Quaternion> li = new List<Quaternion>(L);
            foreach (char ch in s)
            {
                switch(ch)
                {
                    case 'i': li.Add(Quaternion.I); break;
                    case 'j': li.Add(Quaternion.J); break;
                    case 'k': li.Add(Quaternion.K); break;
                }
            }

            List<Quaternion> prefix = new List<Quaternion>(L);
            Quaternion cur = 1;
            foreach(Quaternion q in li)
            {
                cur = cur * q;
                prefix.Add(cur);
            }

            Quaternion l = prefix[L-1];
            Quaternion total = 1;
            for (int i = 0; i < X % 4; i++)
			{
			    total = total * l;
			}
            if(total != -1)
            {
                Wl(tt, "NO"); return;
            }

            //prefix
            Quaternion prod = 1;
            long pos = long.MaxValue;
            for (int x = 0; x < Math.Min(X, 4); x++)
            {
                for (int i = 0; i < L; i++)
                {
                    if (prod * prefix[i] == Quaternion.I)
                    {
                        pos = x * L + i;
                        break;
                    }
                }
                if (pos < long.MaxValue) break;
                prod = prod * l;
            }
            if (pos == long.MaxValue)
            {
                Wl(tt, "NO");
                return;
            }

            long prefixPos = pos + 1;

            //suffix
            List<Quaternion> suffix = new List<Quaternion>(L);
            cur = 1;
            for(int i = L-1; i >= 0; i--)
            {
                cur = li[i] * cur;
                suffix.Add(cur);
            }

            prod = 1;
            pos = long.MaxValue;
            for (int x = 0; x < Math.Min(X, 4); x++)
            {
                for (int i = 0; i < L; i++)
                {
                    if (suffix[i] * prod == Quaternion.K)
                    {
                        pos = x * L + i;
                        break;
                    }
                }
                if (pos < long.MaxValue) break;
                prod = l * prod;
            }
            if (pos == long.MaxValue)
            {
                Wl(tt, "NO");
                return;
            }

            if (prefixPos + pos + 1 > X * L)
            {
                Wl(tt, "NO");
            }
            else
            {
                Wl(tt, "YES");
            }
        }

        public struct Quaternion
        {
            public double Re, ImI, ImJ, ImK;

            public static readonly Quaternion I = new Quaternion(0, 1, 0, 0);
            public static readonly Quaternion J = new Quaternion(0, 0, 1, 0);
            public static readonly Quaternion K = new Quaternion(0, 0, 0, 1);

            #region Constructor and factory methods
            public Quaternion(double re, double imi, double imj, double imk)
            {
                Re = re;
                ImI = imi;
                ImJ = imj;
                ImK = imk;
            }

            public Quaternion(double Re) : this(Re, 0.0, 0.0, 0.0) { }
            #endregion

            public void Scale(double scale)
            {
                Re *= scale;
                ImI *= scale;
                ImJ *= scale;
                ImK *= scale;
            }

            public double Norm()
            {
                return Math.Sqrt(Norm2());
            }

            public double Norm2()
            {
                return Re * Re + ImI * ImI + ImJ * ImJ + ImK * ImK;
            }

            #region Operators

            public static implicit operator Quaternion(double Re)
            {
                return new Quaternion(Re);
            }

            public static Quaternion operator -(Quaternion x)
            {
                return new Quaternion(-x.Re, -x.ImI, -x.ImJ, -x.ImK);
            }

            public static Quaternion operator ~(Quaternion x)
            {
                return new Quaternion(x.Re, -x.ImI, -x.ImJ, -x.ImK);
            }

            public static Quaternion operator +(Quaternion x, Quaternion y)
            {
                return new Quaternion(x.Re + y.Re, x.ImI + y.ImI, x.ImJ + y.ImJ, x.ImK + y.ImK);
            }

            public static Quaternion operator -(Quaternion x, Quaternion y)
            {
                return new Quaternion(x.Re - y.Re, x.ImI - y.ImI, x.ImJ - y.ImJ, x.ImK - y.ImK);
            }

            public static Quaternion operator *(Quaternion x, Quaternion y)
            {
                return new Quaternion(
                    x.Re * y.Re - x.ImI * y.ImI - x.ImJ * y.ImJ - x.ImK * y.ImK,
                    x.Re * y.ImI + x.ImI * y.Re + x.ImJ * y.ImK - x.ImK * y.ImJ,
                    x.Re * y.ImJ + x.ImJ * y.Re + x.ImK * y.ImI - x.ImI * y.ImK,
                    x.Re * y.ImK + x.ImK * y.Re + x.ImI * y.ImJ - x.ImJ * y.ImI
                );
            }

            public static Quaternion operator *(Quaternion x, double y)
            {
                Quaternion r = x;
                r.Scale(y);
                return r;
            }

            public static Quaternion operator *(double x, Quaternion y)
            {
                return y * x;
            }

            public static Quaternion operator /(Quaternion x, Quaternion y)
            {
                return x * ~y * (1.0 / y.Norm2());
            }

            public static bool operator ==(Quaternion x, Quaternion y)
            {
                return x.Re == y.Re && x.ImI == y.ImI && x.ImJ == y.ImJ && x.ImK == y.ImK;
            }

            public static bool operator !=(Quaternion x, Quaternion y)
            {
                return x.Re != y.Re || x.ImI != y.ImI || x.ImJ != y.ImJ || x.ImK != y.ImK;
            }

            #endregion

            public override bool Equals(object obj)
            {
                return obj is Quaternion && this == (Quaternion)obj;
            }

            public override int GetHashCode()
            {
                return Re.GetHashCode() ^ ImI.GetHashCode() ^ ImJ.GetHashCode() ^ ImK.GetHashCode();
            }

            public override string ToString()
            {
                string s = "";
                if (Re != 0) s += string.Format("{0:+0.##;-0.##}", Re);
                if (ImI == -1.0) s += "-i"; else if (ImI == 1.0) s += "i"; else if (ImI != 0) s += string.Format("{0:+0.##;-0.##}i", ImI);
                if (ImJ == -1.0) s += "-j"; else if (ImJ == 1.0) s += "j"; else if (ImJ != 0) s += string.Format("{0:+0.##;-0.##}j", ImJ);
                if (ImK == -1.0) s += "-k"; else if (ImK == 1.0) s += "k"; else if (ImK != 0) s += string.Format("{0:+0.##;-0.##}k", ImK);
                if (s.Length == 0) return "0";
                return s.TrimStart('+');
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