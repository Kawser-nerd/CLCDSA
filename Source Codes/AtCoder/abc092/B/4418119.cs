using System;
using System.Linq;

namespace B___Chocolate
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var DX = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var D = DX[0];
            var X = DX[1];
            var Ai = Enumerable.Range(1, N).Select(_ => Console.ReadLine()).Select(int.Parse).ToArray();

            int cnt = 0;

            for (int i = 1; i <= D; i++)
            {
                foreach (var ai in Ai)
                {
                    for (int j = 1; j <= i; j += ai)
                    {
                        if (j == i)
                        {
                            cnt++;
                        }

                    }

                }
            }

            Console.WriteLine(X + cnt);

        }
    }
}