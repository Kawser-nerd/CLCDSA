using System;
using System.Linq;

namespace ABC006_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var NM = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var N = NM[0];
            var M = NM[1];

            for (int i = 0; i <= N; i++)
            {
                if ((M - i * 3) % 2 == 0 && 2 * (N-i) + i * 3 <= M && M <= 4 * (N - i) + i * 3)
                {
                    for (int j = 0; j <= N - i; j++)
                    {
                        if(3 * i + 2* j + 4 * (N - i - j) == M)
                        {
                            Console.WriteLine(j + " " + i + " " + (N - i - j));
                            goto end;
                        }
                    }
                }
            }
            Console.WriteLine("-1 -1 -1");
            end:;
            Console.WriteLine();
        }
    }
}