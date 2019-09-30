using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc119d
{
    class Program
    {
        static void Main(string[] args)
        {
            var ABQ = ReadIntList();
            var s = new List<long>();
            var t = new List<long>();

            s.Add(-1000000000000);
            for (int i = 0; i < ABQ[0]; i++)
            {
                s.Add(ReadLong());
            }
            s.Add(1000000000000);
            t.Add(-1000000000000);
            for (int i = 0; i < ABQ[1]; i++)
            {
                t.Add(ReadLong());
            }
            t.Add(1000000000000);
            for (int i = 0; i < ABQ[2]; i++)
            {
                long x = ReadLong();
                var a = BinarySearch(s, x);
                var c = BinarySearch(t, x);
                var ans = new List<long>();
                for (int j = 0; j <= 1; j++)
                {
                    for (int k = 0; k <= 1; k++)
                    {
                        ans.Add(Math.Abs(s[a + j] - x) + Math.Abs(t[c + k] - s[a + j]));
                        ans.Add(Math.Abs(t[c + k] - x) + Math.Abs(s[a + j] - t[c + k]));
                    }
                }
                Console.WriteLine(ans.Min());
            }

#if DEBUG
            Console.ReadKey();
#endif
        }

        private static bool IsRange(int a, int from, int to) => (from <= a && a <= to);
        private static int ReadInt() => int.Parse(Console.ReadLine());
        private static List<int> ReadIntList() => Console.ReadLine().Split().Select(int.Parse).ToList();
        private static double ReadDouble() => double.Parse(Console.ReadLine());
        private static List<double> ReadDoubleList() => Console.ReadLine().Split().Select(double.Parse).ToList();
        private static long ReadLong() => long.Parse(Console.ReadLine());
        private static List<long> ReadLongList() => Console.ReadLine().Split().Select(long.Parse).ToList();
        private static List<int> Int2Digits(int a) => a.ToString().ToCharArray().Select(_ => int.Parse(_.ToString())).ToList();
        private static int BinarySearch<Type>(IReadOnlyList<Type> s, Type target) // target ?????????????????
            where Type : IComparable
        {
            var lower = 0;
            var upper = s.Count - 1;
            while(upper - lower > 1)
            {
                var mid = lower + (upper - lower) / 2;
                if (s[mid].CompareTo(target) <= 0)
                {
                    lower = mid;
                }
                else
                {
                    upper = mid;
                }

            }
            return lower;
        }
    }
}