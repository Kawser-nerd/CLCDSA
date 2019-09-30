using System;
using System.Linq;

namespace B___OddString
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();

            Console.WriteLine(new string(s.Where((e, i) => i % 2 == 0).ToArray()));
        }
    }
}