using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    public class SegTree<T>
    {
        public SegTree(IList<T> data, Func<T, T, T> assoc)
        {
            this.assoc = assoc;
            N = data.Count;
            D = 1;
            for (int tmp = 1; tmp < N; tmp <<= 1) ++D;
            theTree = new T[N, D];

            for (int i = 0; i < N; i++)
            {
                theTree[i, 0] = data[i];
            }

            for (int d = 1; d < D; d++)
            {
                for (int i = 0; i < N; i += (1 << d))
                {
                    if (i + (1 << (d - 1)) < N)
                        theTree[i, d] = assoc(theTree[i, d - 1], theTree[i + (1 << (d - 1)), d - 1]);
                    else
                        theTree[i, d] = theTree[i, d - 1];
                }
            }
        }

        public T Get(int start, int end)
        {
            if (start < 0) start = 0;
            if (end > N) end = N;
            if (start >= end) throw new ApplicationException(string.Format("Invalid range: [{0}, {1}]", start, end));

            bool first = true;
            int d = 0;
            T ret = default(T);

            while (start < end)
            {
                for (; (start & (1 << d)) == 0 && d < D - 1; ++d) ;
                for (; start + (1 << d) >= end && d > 0; --d) ;

                if (first)
                {
                    ret = theTree[start, d];
                    first = false;
                }
                else
                {
                    ret = assoc(ret, theTree[start, d]);
                }
                start += (1 << d);
            }

            return ret;
        }

        public void Set(int index, T value)
        {
            if (index < 0 || index >= N) throw new ApplicationException(string.Format("Index out of range: {0}", index));
            theTree[index, 0] = value;
            for (int d = 1; d < D; d++)
            {
                int x = index - (index & ((1 << d) - 1));
                if (x + (1 << (d - 1)) < N)
                    theTree[x, d] = assoc(theTree[x, d - 1], theTree[x + (1 << (d - 1)), d - 1]);
                else
                    theTree[x, d] = theTree[x, d - 1];
            }
        }

        public T this[params int[] ranges]
        {
            set
            {
                for (int i = 0; i < ranges.Length; i += 2)
                {
                    int startRange = ranges[i];
                    int endRange = i == ranges.Length - 1 ? ranges[i] + 1 : ranges[i + 1];
                    for (int pos = startRange; pos < endRange; pos++)
                    {
                        Set(pos, value);
                    }
                }
            }
            get
            {
                T ret = default(T);
                bool first = true;
                for (int i = 0; i < ranges.Length; i += 2)
                {
                    int startRange = ranges[i];
                    int endRange = i == ranges.Length - 1 ? ranges[i] + 1 : ranges[i + 1];
                    if (first)
                    {
                        ret = Get(startRange, endRange);
                        first = false;
                    }
                    else
                    {
                        ret = assoc(ret, Get(startRange, endRange));
                    }
                }
                return ret;
            }
        }

        private Func<T, T, T> assoc;
        private T[,] theTree;
        private int N;
        private int D;
    }

    class A
    {
        private static ThreadStart s_threadStart = new A().Go;
        private static bool s_time = false;

        string Print(int x)
        {
            switch (x)
            {
                case 0: return "Game has not completed";
                case 1: return "Draw";
                case 2: return "X won";
                case 3: return "O won";
            }
            return "FAIL";
        }

        bool Check(char ch, char target)
        {
            return ch == 'T' || ch == target;
        }

        int Check(char x1, char x2, char x3, char x4)
        {
            if (x1 == '.' || x2 == '.' || x3 == '.' || x4 == '.') return 0;
            char target = x1;
            if (target == 'T') target = x2;
            if (Check(x1, target) && Check(x2, target) && Check(x3, target) && Check(x4, target)) return target == 'X' ? 2 : 3;
            return 1;
        }

        private void Test(int tt)
        {
            int res;
            int ans = 1;
            string[] tab = new string[4];
            for (int i = 0; i < 4; i++)
            {
                tab[i] = GetString();
            }

            for (int i = 0; i < 4; i++)
            {
                res = Check(tab[0][i], tab[1][i], tab[2][i], tab[3][i]);
                if (res > 1)
                {
                    Wl(tt, Print(res));
                    return;
                }
                ans *= res;

                res = Check(tab[i][0], tab[i][1], tab[i][2], tab[i][3]);
                if (res > 1)
                {
                    Wl(tt, Print(res));
                    return;
                }
                ans *= res;
            }

            res = Check(tab[0][0], tab[1][1], tab[2][2], tab[3][3]);
            if (res > 1)
            {
                Wl(tt, Print(res));
                return;
            }
            ans *= res;

            res = Check(tab[0][3], tab[1][2], tab[2][1], tab[3][0]);
            if (res > 1)
            {
                Wl(tt, Print(res));
                return;
            }
            ans *= res;

            Wl(tt, Print(ans));
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