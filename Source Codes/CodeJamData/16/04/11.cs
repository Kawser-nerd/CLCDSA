using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int cs = 1; cs <= T; ++cs)
            {
                var inputs = Console.ReadLine().Split(' ');
                int K = int.Parse(inputs[0]);
                int C = int.Parse(inputs[1]);
                int S = int.Parse(inputs[2]);

                Console.Write("Case #{0}:", cs);

                int require = (K - 1) / C + 1;
                if (S < require)
                {
                    Console.WriteLine(" IMPOSSIBLE");
                    continue;
                }

                for (int i = 0; i < K; i += C)
                {
                    BigInteger sum = 0;
                    for (int j = 0; j < C && i + j < K; ++j)
                    {
                        sum = sum * K + i + j;
                    }
                    Console.Write(" {0}", sum + 1);
                }
                Console.WriteLine();
            }
        }
    }
}
