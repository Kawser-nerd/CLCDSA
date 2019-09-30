using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');
            var s = int.Parse(input.First());
            var t = int.Parse(input.Skip(1).First());

            Console.WriteLine(t - s + 1);
        }
    }
}