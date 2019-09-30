using System;
using System.Linq;

namespace A.Happy_Birthday_
{
    class Program
    {
        static void Main(string[] args)
        {
            var AB = Console.ReadLine().Split().Select(int.Parse);

            Console.WriteLine(AB.Any(x => x > 8) ? ":(" : "Yay!");
        }
    }
}