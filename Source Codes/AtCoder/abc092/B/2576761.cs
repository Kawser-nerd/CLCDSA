using System;
using System.Linq;

namespace ABC092_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var DX = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var X = DX[1];

            for (int i = 0; i < N; i++)
            {
                var A = int.Parse(Console.ReadLine());
                for (int j = 1; j <= DX[0]; j+=A)
                    X++;
            }
            Console.WriteLine(X);
        }
    }
}