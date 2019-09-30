using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = ReadInt();
            var A = ReadArrayInt();
            var Asort = A.OrderBy(i => i).ToArray();
            var used = new bool[N];
            var pat = new List<long>();
            for (int i = 1; Math.Pow(2, i) < Math.Pow(10, 10); i++) pat.Add((long)Math.Pow(2, i));
            var beki = pat.ToArray();
            var ans = 0L;
            var chk = 0L;
            var plus = 0;
            for (int i = N - 1; i >= 0; i--)
            {
                if (used[i]) continue;
                used[i] = true;
                var num = beki[UpperBound(beki, Asort[i])] - Asort[i];
                var match = LowerBound(Asort, (int)num);
                if (num == chk)
                {
                    match += plus;
                }
                else
                {
                    plus = 0;
                    chk = num;
                }
                while (match < N && Asort[match] == num)
                {
                    if (!used[match])
                    {
                        ans++;
                        used[match] = true;
                        plus++;
                        break;
                    }
                    match++;
                    plus++;
                }
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static int LowerBound(int[] arr, int val)
        {
            if (arr[0] >= val) return 0;
            if (arr[arr.Length - 1] < val) return arr.Length;

            var low = 0;
            var high = arr.Length - 1;

            while (low + 1 < high)
            {
                var mid = (low + high) / 2;
                if (arr[mid] >= val) high = mid;
                else low = mid;
            }

            return high;
        }

        static int UpperBound(long[] arr, int val)
        {
            val++;
            if (arr[0] >= val) return 0;
            if (arr[arr.Length - 1] < val) return arr.Length;

            var low = 0;
            var high = arr.Length - 1;

            while (low + 1 < high)
            {
                var mid = (low + high) / 2;
                if (arr[mid] >= val) high = mid;
                else low = mid;
            }

            return high;
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}