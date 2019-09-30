using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC091C
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long N = line[0];
            long M = line[1];

            long ans = 0;
            if (N == 1 && M == 1) ans = 1;
            else if (N == 1) ans = M - 2;
            else if (M == 1) ans = N - 2;
            else
            {
                ans = (N - 2) * (M - 2);
            }

            Console.WriteLine(ans);
            Console.ReadKey();
        }
    }
}