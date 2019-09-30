using System;
using System.Linq;

namespace Beginner008B
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Enumerable.Range(0, int.Parse(Console.ReadLine()))
                                        .Select(dummy => Console.ReadLine())
                                        .GroupBy(name => name)
                                        .OrderByDescending(vote => vote.Count())
                                        .First()
                                        .Key);
        }
    }
}