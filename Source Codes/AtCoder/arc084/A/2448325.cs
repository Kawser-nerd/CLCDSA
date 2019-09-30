using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC84_C
{



    class Program
    {
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

        public static int UpperBound<T>(T[] arr, int start, int end, T value, IComparer<T> comparer)
        {
            int low = start;
            int high = end;
            int mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) <= 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static int UpperBound<T>(T[] arr, T value)
        {
            return UpperBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }
        //????????????
        public static int LowerBound<T>(T[] arr, T value) where T : IComparable
        {
            return LowerBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }

        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());
            var a0 = Console.ReadLine().Split().Select(long.Parse).ToArray();
            var b0 = Console.ReadLine().Split().Select(long.Parse).ToArray();
            var c0 = Console.ReadLine().Split().Select(long.Parse).ToArray();
            Array.Sort(a0);
            Array.Sort(b0);
            Array.Sort(c0);

            long d = 0;
            for (int i = 0; i < n; i++)
            {
                long ai = Math.Max(LowerBound<long>(a0, b0[i]), 0);
                long ci = Math.Max(n - UpperBound<long>(c0, b0[i]), 0);
                d += ai * ci;
            }

            Console.WriteLine(d);
        }
    }
}