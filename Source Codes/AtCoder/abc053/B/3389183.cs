using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();

            var left = s.IndexOf('A');
            var right = s.LastIndexOf('Z');

            Console.WriteLine(right - left+1);


        }
    }
}