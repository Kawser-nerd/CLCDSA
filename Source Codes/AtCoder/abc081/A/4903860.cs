using System;
using System.Linq;

namespace A___Placing_Marbles
{
    class Program
    {
        static void Main(string[] args)
        {
            var si = Console.ReadLine();

            Console.WriteLine(si.Count(x => x == '1'));
        }
    }
}