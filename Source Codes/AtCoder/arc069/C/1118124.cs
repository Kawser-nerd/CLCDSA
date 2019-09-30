using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC069
{
    public class E
    {
        private void Run()
        {
            var N = int.Parse(Console.ReadLine().Trim());
            var A = Console.ReadLine().Trim().Split()
                .Select((s, i) => new { index = i, value = long.Parse(s) })
                .OrderByDescending(x => x.value)
                .ThenByDescending(x => x.index)
                .ToArray();

            var results = new long[N];
            int index = 0;
            while (index + 1 < A.Length && A[index].value == A[index + 1].value)
            {
                index++;
            }

            int minIndex = A[index].index;
            long count = index + 1;
            while (index + 1 < A.Length)
            {
                int prevMinIndex = minIndex;
                int sameValueLastIndex = index + 1;
                minIndex = Math.Min(minIndex, A[sameValueLastIndex].index);
                while (sameValueLastIndex + 1 < A.Length &&
                    A[sameValueLastIndex].value == A[sameValueLastIndex + 1].value)
                {
                    sameValueLastIndex += 1;
                    minIndex = Math.Min(minIndex, A[sameValueLastIndex].index);
                }
                long nextValue = A[sameValueLastIndex].value;
                results[prevMinIndex] += (A[index].value - nextValue) * count;

                count += sameValueLastIndex - index;

                index = sameValueLastIndex;
            }
            results[minIndex] += A.Last().value * count;

            foreach (var result in results)
            {
                Console.WriteLine(result);
            }
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new E().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}