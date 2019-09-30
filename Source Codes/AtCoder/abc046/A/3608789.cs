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

            int a = input[0];
            int b = input[1];
            int c = input[2];

            if (a == b && a == c) Console.WriteLine(1);
            else if (a == b && a != c) Console.WriteLine(2);
            else if (a == c && a != b) Console.WriteLine(2);
            else if (b == c && a != b) Console.WriteLine(2);
            else Console.WriteLine(3);

        }
    }
}