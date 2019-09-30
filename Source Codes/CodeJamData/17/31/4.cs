using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017_1C_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var N = input[0];
                var K = input[1];
                var byRK = new double[N];
                var byRV = new double[N];
                var byHK = new double[N];
                var byHV = new double[N];
                for (int i = 0; i < N; i++)
                {
                    var line = Console.ReadLine().Split().Select(long.Parse).ToArray();
                    byRK[i] = Math.PI * line[0] * line[0];
                    byRV[i] = Math.PI * 2 * line[0] * line[1];
                    byHK[i] = Math.PI * 2 * line[0] * line[1];
                    byHV[i] = Math.PI * line[0] * line[0];
                }
                Array.Sort(byRK, byRV);
                Array.Sort(byHK, byHV);

                var result = 0D;
                for (int i = K - 1; i < N; i++)
                {
                    var total = byRK[i] + byRV[i];
                    var taken = 1;
                    var touched = false;
                    for (int j = N - 1; taken < K; j--)
                        if (byHV[j] <= byRK[i])
                        {
                            if (byHV[j] == byRK[i] && byHK[j] == byRV[i] && !touched)
                            {
                                touched = true;
                                continue;
                            }
                            taken++;
                            total += byHK[j];
                        }
                    if (total > result) result = total;
                }

                Console.WriteLine("Case #{0}: {1}", testN, result);
            }
        }
    }
}
