using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017_0_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var input = Console.ReadLine().Split().Select(long.Parse).ToArray();
                var N = input[0];
                var K = input[1];
                var largerGaps = 0L;
                var smallerGaps = 1L;
                while (largerGaps + smallerGaps < K)
                {
                    K -= largerGaps + smallerGaps;
                    if ((N & 1) != 0)
                        smallerGaps = largerGaps + smallerGaps + smallerGaps;
                    else
                        largerGaps = smallerGaps + largerGaps + largerGaps;
                    N = (N - 1) >> 1;
                }
                if (largerGaps >= K)
                    N++;
                Console.WriteLine("Case #{0}: {1} {2}", testN, N / 2, (N - 1) / 2);
            }
        }
    }
}
