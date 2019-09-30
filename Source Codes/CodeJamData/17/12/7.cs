using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017R1A
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (var t = 1; t <= T; ++t)
            {
                var ar = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                var N = ar[0];
                var P = ar[1];
                var R = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                var Q =
                    Enumerable.Repeat(0, N)
                        .Select(_ => Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(x => x).ToArray())
                        .ToArray();
                var S = new List<Tuple<int, int>>[N];
                for (var i = 0; i < N; ++i)
                {
                    S[i] = new List<Tuple<int, int>>();
                    for (var j = 0; j < P; ++j)
                    {
                        var vM = Q[i][j] * 10 / (9 * R[i]);
                        var vm = Q[i][j] * 10 / (11 * R[i]) + ((Q[i][j] * 10) % (11 * R[i]) == 0 ? 0 : 1);
                        if (vm <= vM)
                        {
                            S[i].Add(Tuple.Create(vm, vM));
                        }
                    }
                }
                var ret = 0;
                while (S[0].Any(x => true))
                {
                    var n1 = S[0][0];
                    S[0].RemoveAt(0);
                    for (int i = n1.Item1; i <= n1.Item2; ++i)
                    {
                        if (Enumerable.Range(1, N - 1).All(x => S[x].Any(y => i >= y.Item1 && i <= y.Item2)))
                        {
                            for (int j = 1; j < N; ++j)
                            {
                                while (true)
                                {
                                    if (i >= S[j][0].Item1 && i <= S[j][0].Item2)
                                    {
                                        S[j].RemoveAt(0);
                                        break;
                                    }
                                    S[j].RemoveAt(0);
                                }
                            }
                            ret += 1;
                            break;
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", t, ret);

            }
        }
    }
}
