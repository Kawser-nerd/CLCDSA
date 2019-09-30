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
                                        .Select(vote => new { Name = vote.Key, Count = vote.Count() })
                                        .Aggregate((memberA, memberB) => memberA.Count > memberB.Count ? memberA : memberB)
                                        .Name);
        }
    }
}