using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_0_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var N = int.Parse(Console.ReadLine());
                if (N == 0)
                {
                    Console.WriteLine("Case #{0}: {1}", testN, "INSOMNIA");
                    continue;
                }
                var current = N;
                var digits = new bool[10];
                var digitCount = 0;
                while (true)
                {
                    var nn = current;
                    while (nn > 0)
                    {
                        int r;
                        nn = Math.DivRem(nn, 10, out r);
                        if (!digits[r])
                        {
                            digits[r] = true;
                            digitCount++;
                        }
                    }
                    if (digitCount == 10) break;
                    current += N;
                }
                Console.WriteLine("Case #{0}: {1}", testN, current);
            }
        }
    }
}
