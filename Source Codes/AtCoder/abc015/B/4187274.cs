using System;
using System.Linq;

namespace Beginner015B
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            var bugCount = Console.ReadLine().Split(' ').Select(x => int.Parse(x));

            Console.WriteLine(Math.Ceiling((decimal)bugCount.Sum() / bugCount.Where(x => x != 0).Count()));
        }
    }
}