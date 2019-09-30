using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC052
{
    public class B
    {
        private void Run()
        {
            var input = Console.ReadLine().Trim().Split();
            var N = int.Parse(input[0]);
            var Q = int.Parse(input[1]);
            var cones = Enumerable.Range(0, N)
                .Select(_ => Console.ReadLine().Trim().Split())
                .Select(arr => new { X = double.Parse(arr[0]), R = double.Parse(arr[1]), H = double.Parse(arr[2]) })
                .ToArray();
            while (Q-- > 0)
            {
                input = Console.ReadLine().Trim().Split();
                var A = int.Parse(input[0]);
                var B = int.Parse(input[1]);

                double result = cones.Sum(c =>
                    {
                        double a = Math.Max(A, c.X) - c.X;
                        double b = Math.Min(B, c.X + c.H) - c.X;

                        if (a >= b) { return 0.0; }

                        double ra = (c.H - a) / c.H * c.R;
                        double rb = (c.H - b) / c.H * c.R;
                        return
                            (((ra * ra) * (c.H - a))
                                - ((rb * rb) * (c.H - b)))
                            * Math.PI / 3;
                    });

                Console.WriteLine(result.ToString("F4"));
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}