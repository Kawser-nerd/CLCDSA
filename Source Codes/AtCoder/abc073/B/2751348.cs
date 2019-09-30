using System;
using System.Linq;

namespace ABC073_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var s = 0;
            for (int i = 0; i < N; i++)
            {
                var lr = Console.ReadLine().Split().Select(int.Parse).ToArray();
                s += lr[1] - lr[0] + 1;
            }
            Console.WriteLine(s);
        }
    }
}