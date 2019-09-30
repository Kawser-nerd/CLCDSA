using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var C = new int[N - 1];
            var S = new int[N - 1];
            var F = new int[N - 1];
            for (int i = 0; i < N - 1; i++)
            {
                var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                C[i] = input[0];
                S[i] = input[1];
                F[i] = input[2];
            }

            for (int i = 0; i < N - 1; i++)
            {
                var ans = S[i] + C[i];
                for (int j = i + 1; j < N - 1; j++)
                {
                    if (ans < S[j])
                    {
                        ans = S[j] + C[j];
                    }else
                    {
                        var tmp = ans - S[j];
                        if (tmp % F[j] == 0)
                        {
                            ans = S[j] + F[j] * (tmp / F[j]) + C[j];
                        }else
                        {
                            ans = S[j] + F[j] * (tmp / F[j]) + F[j] + C[j];
                        }
                    }
                }
                Console.WriteLine(ans);
            }

            Console.WriteLine(0);
        }
    }
}