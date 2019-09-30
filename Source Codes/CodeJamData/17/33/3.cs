using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1CProblemC
{
    class Program
    {
        private const double EPSILON = 0.00000001;

        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine());
            for (var i = 1; i <= t; i++)
            {
                var parts = Console.ReadLine().Split(' ');
                //var n = int.Parse(parts[0]);
                //var k = int.Parse(parts[1]);
                var u = double.Parse(Console.ReadLine());
                var p = Console.ReadLine().Split(' ').Select(part => double.Parse(part)).OrderBy(pi => pi).ToArray();
                Console.WriteLine($"Case #{i}: {Solve(u, p)}");
            }
        }

        private static bool Equals(double a, double b)
        {
            return Math.Abs(a - b) < EPSILON;
        }

        private static double Solve(double u, double[] cores)
        {
            while (u > EPSILON)
            {
                if (cores.All(part => Equals(part, 1)))
                {
                    return 1;
                }

                var currentLowestParts = 1;
                for (var i = 1; i < cores.Length; i++)
                {
                    if (Equals(cores[i], cores[0]))
                    {
                        currentLowestParts = i + 1;
                    }
                    else
                    {
                        break;
                    }
                }

                var limit = u / currentLowestParts;
                limit = Math.Min(limit, 1 - cores[0]);
                if (currentLowestParts < cores.Length)
                {
                    var max = cores[currentLowestParts];
                    limit = Math.Min(limit, max - cores[0]);
                }

                for (var i = 0; i < currentLowestParts; i++)
                {
                    cores[i] += limit;
                    u -= limit;
                }
            }

            double result = 1;
            for (var i = 0; i < cores.Length; i++)
            {
                result *= cores[i];
            }

            return result;
        }
    }
}
