using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            var raw_inputs = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            var N = raw_inputs[0];
            var M = raw_inputs[1];

            var likes = Console
                    .ReadLine()
                    .Split(' ')
                    .Skip(1)
                    .Select(x => int.Parse(x))
                    .ToArray();

            for (int i = 1; i < N; i++)
            {
                var likes2 = Console
                    .ReadLine()
                    .Split(' ')
                    .Skip(1)
                    .Select(x => int.Parse(x))
                    .ToArray();

                likes = likes.Intersect(likes2).ToArray();
            }

            Console.WriteLine(likes.Count());
        }
    }
}