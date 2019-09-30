using System;
using System.Linq;

namespace B___Kagami_Mochi
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var Di = Enumerable.Range(1, N).Select(_ => int.Parse(Console.ReadLine())).OrderByDescending(x => x).Distinct().ToArray();

            Console.WriteLine(Di.Count());
        }
    }
}