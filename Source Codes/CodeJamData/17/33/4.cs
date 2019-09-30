using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017_1C_C
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
                var U = decimal.Parse(Console.ReadLine());
                var Ps = Console.ReadLine().Split().Select(decimal.Parse).ToArray();
                Array.Sort(Ps);
                var step = decimal.One / 10000;
                while (U > 0)
                {
                    var i = 0;
                    while (i < N - 1 && Ps[i] == Ps[i + 1])
                        i++;
                    Ps[i] += step;
                    U -= step;
                }

                var result = 1D;
                for (int i = 0; i < N; i++)
                {
                    result *= (double)Ps[i];
                }
                Console.WriteLine("Case #{0}: {1}", testN, result);
            }
        }
    }
}
