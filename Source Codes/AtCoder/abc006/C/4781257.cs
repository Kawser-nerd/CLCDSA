using System;
using System.Linq;

namespace BC006_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var vals = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var N = vals[0];
            var M = vals[1];

            for (var child = 0; child <= Math.Min(N, M / 4); child++)
            {
                var adult = -M + 3 * N + child;
                var silver = M - 2 * N - 2 * child;
                if (adult >= 0 && silver >= 0)
                {
                    Console.WriteLine($"{adult} {silver} {child}");
                    return;
                }
            }
            Console.WriteLine("-1 -1 -1");
        }
    }
}