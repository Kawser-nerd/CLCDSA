using System;
using System.Linq;

namespace abc087_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int A = int.Parse(Console.ReadLine());
            int B = int.Parse(Console.ReadLine());
            int C = int.Parse(Console.ReadLine());
            int X = int.Parse(Console.ReadLine());

            var ptn = from a in Enumerable.Range(0, A + 1)
                      from b in Enumerable.Range(0, B + 1)
                      from c in Enumerable.Range(0, C + 1)
                      select a * 500 + b * 100 + c * 50;

            Console.WriteLine(ptn.Count(m => m == X));
        }
    }
}