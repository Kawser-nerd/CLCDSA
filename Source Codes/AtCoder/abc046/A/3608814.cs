using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp8
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            var input2 = input.Distinct();

            Console.WriteLine(input2.Count());

        }
    }
}