using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_D
{
    class D119
    {
        static void Main(string[] args)
        {
            int[] p = Console.ReadLine().Split(' ').Select(xx => int.Parse(xx)).ToArray();
            int A = p[0], B = p[1], C = p[2];

            long[] s = new long[A];
            for(int i = 0; i < A; i++)
            {
                s[i] = long.Parse(Console.ReadLine());
            }
            long[] t = new long[B];
            for (int i = 0; i < B; i++)
            {
                t[i] = long.Parse(Console.ReadLine());
            }

            long[] x = new long[C];
            for (int i = 0; i < C; i++)
            {
                x[i] = long.Parse(Console.ReadLine());
            }

            for(int i = 0; i < C; i++)
            {
                int lbs = LowerBound(s, x[i]);
                if (lbs == A) lbs = lbs - 1;
                int lbt= LowerBound(t, x[i]);
                if (lbt == B) lbt = lbt - 1;

                long s1 = s[lbs]; long s2 = lbs == 0 ? s[lbs] : s[lbs - 1];
                long t1 = t[lbt]; long t2 = lbt == 0 ? t[lbt] : t[lbt - 1];

                long mx = long.MaxValue;
                long d = distance(s1, t1, x[i]); if (d < mx) mx = d;
                d = distance(s1, t2, x[i]); if (d < mx) mx = d;
                d = distance(s2, t1, x[i]); if (d < mx) mx = d;
                d = distance(s2, t2, x[i]); if (d < mx) mx = d;
                Console.WriteLine(mx);
            }            
        }

        static long distance(long s, long t, long p)
        {
            long x = s - p, y = t - p;
            if (Math.Sign(x) == Math.Sign(y))
            {
                return Math.Max(Math.Abs(x), Math.Abs(y));
            }
            else
            {
                long w = Math.Min(Math.Abs(x), Math.Abs(y));
                long r = Math.Max(Math.Abs(x), Math.Abs(y));
                return r + 2 * w;
            }
        }

        /// <summary>
        /// ???????????????????
        /// </summary>
        /// <typeparam name="T">???????</typeparam>
        /// <param name="arr">??????????????????</param>
        /// <param name="start">??????? [inclusive]</param>
        /// <param name="end">??????? [exclusive]</param>
        /// <param name="value">?????</param>
        /// <param name="comparer">????(????????)</param>
        /// <returns>????????????????</returns>
        public static int LowerBound<T>(T[] arr, int start, int end, T value, IComparer<T> comparer)
        {
            int low = start;
            int high = end;
            int mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) < 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }
        //????????????
        public static int LowerBound<T>(T[] arr, T value) where T : IComparable
        {
            return LowerBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }


    }
}