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
            var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var D = input[0];
            var X = input[1];
            for(var i = 0; i < N; i++)
            {
                X++;
                var A = int.Parse(Console.ReadLine());
                for(var j = A + 1; j <= D; j += A)
                {
                    X++;
                }
            }

            Console.WriteLine(X);
        }
    }
}