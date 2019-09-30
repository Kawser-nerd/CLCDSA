using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC121
{
    class Program
    {
        static void Main(string[] args)
        {
            B();
        }

        static void B()
        {
            var NMC = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var B = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var N = NMC[0];
            var M = NMC[1];
            var C = NMC[2];

            var okSource = 0;
            for (var i = 0; i < N; i++)
            {
                var A = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                var sum = 0;
                for (var j = 0; j < M; j++)
                    sum += A[j] * B[j];

                if (sum + C > 0)
                    okSource += 1;
            }
            Console.WriteLine(okSource);
        }
    }
}