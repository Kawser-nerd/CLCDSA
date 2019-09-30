using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ1A
{
    static class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
            {
                var parts = Console.ReadLine().Split();
                var r = double.Parse(parts[0]);
                var t = double.Parse(parts[1]);

                var root = (ulong)(Math.Sqrt(0.25 * r * r - 0.25 * r + 1.0 / 16.0 + 0.5 * t) - 0.5 * r + 0.25);

                Console.WriteLine("Case #{0}: {1}", testNumber, root);
            }
        }
    }
}
