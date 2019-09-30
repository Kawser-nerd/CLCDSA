using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1C
{
    internal class Program
    {
        private static void Main(string[] args)
        {

            long t = long.Parse(Console.ReadLine());

            for (long i = 0; i < t; i++)
            {
                var line = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
                var b = line[0];
                var m = line[1];

                Console.Write("Case #{0}: ", i + 1);
                if (m > Math.Pow(2, b - 2))
                {
                    Console.WriteLine("IMPOSSIBLE");
                }
                else
                {
                    Console.WriteLine("POSSIBLE");

                    var ind = new List<long>();
                    long node = 1;
                    while (m > 0)
                    {
                        node++;
                        if (m%2 == 1)
                        {
                            ind.Add(node);
                        }
                        m = m/2;
                    }


                    for (long j = 0; j < b; j++)
                    {
                        for (long k = 0; k < b; k++)
                        {
                            if (j < b - node - 1)
                            {
                                if (j+1==k) Console.Write('1');
                                else Console.Write('0');
                            }
                            else if (j == b - node-1)
                            {
                                if (ind.Contains(b-k)) Console.Write('1');
                                else Console.Write('0');
                            }
                            else
                            {
                                if (j<k) Console.Write('1');
                                else Console.Write('0');
                            }
                        }
                        Console.WriteLine();
                    }
                }
               
            }
        }

    }
}
