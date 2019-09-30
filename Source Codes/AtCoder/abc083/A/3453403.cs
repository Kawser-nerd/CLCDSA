using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var left = input[0] + input[1];
            var right = input[2] + input[3];
            if (left == right) Console.WriteLine("Balanced");
            else if (left > right) Console.WriteLine("Left");
            else Console.WriteLine("Right");
        }
    }
}