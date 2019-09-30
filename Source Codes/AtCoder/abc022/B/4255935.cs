using System;
using System.Linq;

namespace Beginner022B
{
    class Program
    {
        static void Main(string[] args)
        {
            var numberOfPolinated = Enumerable.Range(0, int.Parse(Console.ReadLine()))
                                              .Select(_ => int.Parse(Console.ReadLine()))
                                              .GroupBy(flowerType => flowerType)
                                              .Select(flowerType => new { Name = flowerType.Key, Count = flowerType.Count() })
                                              .Where(numberOfVisits => numberOfVisits.Count >= 2)
                                              .Sum(numberOfVisits => numberOfVisits.Count - 1);

            Console.WriteLine(numberOfPolinated);
        }
    }
}