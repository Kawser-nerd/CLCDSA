using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_0_B
{
    static class SortedCountListExtensions
    {
        public static SortedCountList<T> ToSortedCountList<T, U>(this IEnumerable<U> seq, Func<U, T> keySelector, Func<U, long> countSelector) where T : IComparable<T>
        {
            var result = new SortedCountList<T>();
            foreach (var item in seq)
                result.Add(keySelector(item), countSelector(item));
            return result;
        }
    }

    public class SortedCountList<T> where T : IComparable<T>
    {
        List<T> keys = new List<T>();
        List<long> counts = new List<long>();

        public bool Add(T key, long count)
        {
            int index = keys.BinarySearch(key);
            var found = index >= 0;
            if (found)
                counts[index] += count;
            else
            {
                index = -1 - index;
                keys.Insert(index, key);
                counts.Insert(index, count);
            }
            return found;
        }

        public T GetMax()
        {
            return keys.Last();
        }

        public long GetMaxCount()
        {
            return counts.Last();
        }

        public void RemoveMax()
        {
            keys.RemoveAt(counts.Count - 1);
            counts.RemoveAt(counts.Count - 1);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var nonEmptyDiners = int.Parse(Console.ReadLine());
                var list = Console.ReadLine().Split().Select(int.Parse).GroupBy(n => n).Select(g => Tuple.Create(g.Key, g.Count())).ToList();
                var min = long.MaxValue;
                var specialMinutes = 0L;
                for (int i = list.Max(g => g.Item1); i >= 1 && specialMinutes < min; i--)
                {
                    specialMinutes = list.Aggregate(0L, (acc, g) => acc + ((g.Item1 - 1) / i) * g.Item2);
                    var candidate = specialMinutes + i;
                    if (candidate < min)
                        min = candidate;
                }
                Console.WriteLine("Case #{0}: {1}", testN, min);
            }
        }
    }
}
