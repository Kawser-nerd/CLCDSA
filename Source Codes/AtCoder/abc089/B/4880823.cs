using System;
using System.Linq;

namespace B___Hina_Arare
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var Si = Console.ReadLine().Split().ToArray();

            Console.WriteLine(Si.Any(x => x == "Y") ? "Four" : "Three");
        }
    }
}