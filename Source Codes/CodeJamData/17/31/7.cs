using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamCS
{
    class A
    {
        int N, K;
        List<ValueTuple<double, double>> sizes = new List<(double, double)>();

        public static A Parse()
        {
            var pb = new A();
            var parts = Console.ReadLine().Split(' ');
            pb.N = int.Parse(parts[0]);
            pb.K = int.Parse(parts[1]);

            for (int i = 0; i < pb.N; i++)
            {
                parts = Console.ReadLine().Split(' ');
                pb.sizes.Add((double.Parse(parts[0]), double.Parse(parts[1])));
            }

            return pb;
        }

        public string Solve()
        {
            var sorted = new List<(double flank, double radius)>();
            for (int i = 0; i < N; i++)
            {
                var (r, h) = sizes[i];
                sorted.Add((2 * Math.PI * r * h, r));
            }
            sorted.Sort();
            sorted.Reverse();
            double max = 0;
            for (int i = 0; i < N; i++)
            {
                var (f, r) = sorted[i];
                double sum = f + r * r * Math.PI;
                int taken = 1;
                for (int j = 0; j < N && taken < K; j++)
                {
                    if (j == i || sorted[j].radius > r)
                        continue;
                    sum += sorted[j].flank;
                    taken++;
                }
                if (sum > max)
                    max = sum;
            }
            return max.ToString(System.Globalization.CultureInfo.InvariantCulture);
        }

        public static void Main(string[] args)
        {
            int nb = int.Parse(Console.ReadLine());
            for (int i = 0; i < nb; i++)
                Console.WriteLine($"Case #{(i + 1)}: {Parse().Solve()}");
        }
    }
}
