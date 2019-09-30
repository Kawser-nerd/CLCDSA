using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamCS
{
    class C
    {
        int N, K;
        double U;
        double[] probas;

        public static C Parse()
        {
            var pb = new C();
            var parts = Console.ReadLine().Split(' ');
            pb.N = int.Parse(parts[0]);
            pb.K = int.Parse(parts[1]);
            pb.U = double.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
            pb.probas = Console.ReadLine().Split(' ').Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();

            return pb;
        }

        public string Solve()
        {
            Array.Sort(probas);
            double smallest = probas[0];
            int next = 1;
            while (true)
            {
                while (next < N && probas[next] == smallest)
                    next++;
                if (next >= N)
                {
                    var p = Math.Min(smallest + U / N, 1);
                    return Math.Pow(p, N).ToString(CultureInfo.InvariantCulture);
                }
                if (smallest + U / next <= probas[next])
                {
                    var res = Math.Pow(smallest + U / next, next);
                    for (int i = next; i < N; i++)
                        res *= probas[i];
                    return res.ToString(CultureInfo.InvariantCulture);
                }
                U -= (probas[next] - smallest) * next;
                smallest = probas[next];
                next++;
            }
        }

        public static void Main(string[] args)
        {
            int nb = int.Parse(Console.ReadLine());
            for (int i = 0; i < nb; i++)
                Console.WriteLine($"Case #{(i + 1)}: {Parse().Solve()}");
        }
    }
}
