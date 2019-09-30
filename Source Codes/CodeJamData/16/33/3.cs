using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1CProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine());
            for (var t0 = 1; t0 <= t; t0++)
            {
                var line = Console.ReadLine().Split(' ');
                var j = int.Parse(line[0]);
                var p = int.Parse(line[1]);
                var s = int.Parse(line[2]);
                var k = int.Parse(line[3]);
                var n = Math.Min(s, k);

                Console.WriteLine($"Case #{t0}: {j * p * n}");

                for (var ij = 0; ij < j; ij++)
                {
                    for (var ip = 0; ip < p; ip++)
                    {
                        for (var i = 0; i < n; i++)
                        {
                            Console.WriteLine($"{ij + 1} {ip + 1} {((ij + ip + i) % s) + 1}");
                        }
                    }
                }
            }
        }
    }
}
