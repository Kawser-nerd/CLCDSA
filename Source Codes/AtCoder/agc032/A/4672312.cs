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
            var N = ReadInt();
            var b = ReadIntList();
            b.Insert(0, -1);
            var ans = new List<int>();
            ans.Add(-1);
            for (int i = 1; i <= N; i++)
            {
                if (b[i] > i)
                {
                    Console.WriteLine(-1);
                    return;
                }
            }
            for (int i = 1; i <= N; i++)
            {
                ans.Insert(b[i], b[i]);
            }
            for (int i = 1; i <= N; i++)
            {
                Console.WriteLine(ans[i]);
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
            while (upper - lower > 1)
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