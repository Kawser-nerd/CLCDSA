using System;
using System.Linq;

namespace B___Not_Found
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine().Distinct().OrderBy(x => x).ToArray();
            var abc = "abcdefghijklmnopqrstuvwxyz".ToArray();

            Console.WriteLine(S.SequenceEqual(abc) ? "None" : abc.Except(S).First().ToString());
        }
    }
}