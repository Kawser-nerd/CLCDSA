using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017_0_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var input = Console.ReadLine().ToCharArray();
                var cutoff = 1;
                while (cutoff < input.Length && input[cutoff] >= input[cutoff - 1])
                    cutoff++;
                if (cutoff < input.Length)
                {
                    var earliestChange = cutoff - 1;
                    while (earliestChange > 0 && input[earliestChange] == input[earliestChange - 1])
                        earliestChange--;
                    input[earliestChange]--;
                    for (int i = earliestChange + 1; i < input.Length; i++)
                        input[i] = '9';
                }
                var result = 0L;
                for (int i = 0; i < input.Length; i++)
                    result = result * 10 + (input[i] - '0');
                Console.WriteLine("Case #{0}: {1}", testN, result);
            }
        }
    }
}
