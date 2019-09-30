using System;
using System.Linq;

namespace Beginner009B
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Enumerable.Range(0, int.Parse(Console.ReadLine()))
                            .Select(dummy => int.Parse(Console.ReadLine()))
                            .Distinct()
                            .OrderByDescending(price => price)
                            .Skip(1)
                            .First());
        }
    }
}