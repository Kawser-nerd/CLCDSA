using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_0_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var K = parts[0];
                var C = parts[1];
                var S = parts[2];
                if (S * C < K)
                {
                    Console.WriteLine("Case #{0}: {1}", testN, "IMPOSSIBLE");
                    continue;
                }
                var answers = new List<long>();
                var current = 0L;
                var covered = 0;
                var bitSig = 1L;
                for (long bitPos = 0; bitPos < K; bitPos++)
                {
                    current += bitSig * bitPos;
                    covered++;
                    bitSig *= K;
                    if (covered == C)
                    {
                        answers.Add(current + 1);
                        current = 0;
                        covered = 0;
                        bitSig = 1;
                        if (answers.Count == S) break;
                    }
                }
                if (answers.Count < S)
                    answers.Add(current + 1);

                Console.WriteLine("Case #{0}: {1}", testN, String.Join(" ", answers));
            }
        }
    }
}
