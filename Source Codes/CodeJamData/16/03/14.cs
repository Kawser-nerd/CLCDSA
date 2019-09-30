using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_0_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var N = parts[0];
                var J = parts[1];

                Console.WriteLine("Case #{0}:", testN);
                var printed = 0;
                for (int i1 = 1; i1 < N - 1 && printed < J; i1 += 2)
                    for (int i11 = i1 + 2; i11 < N - 1 && printed < J; i11 += 2)
                        for (int i2 = 2; i2 < N && printed < J; i2 += 2)
                            for (int i22 = i2 + 2; i22 < N && printed < J; i22 += 2)
                            {
                                Console.Write('1');
                                for (int i = 1; i < N - 1; i++)
                                {
                                    Console.Write(i == i1 || i == i11 || i == i2 || i == i22 ? '1' : '0');
                                }
                                Console.WriteLine("1 3 2 3 2 7 2 3 2 3");
                                printed++;
                            }
            }
        }
    }
}
