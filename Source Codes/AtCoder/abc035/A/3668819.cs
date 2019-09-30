using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A2
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var w = input[0];
            var h = input[1];

            var val4b3 = h / 3.0;
            var val16b9 = h / 9.0;

            if (w/val4b3 % 4 == 0 && h/val4b3 % 3 == 0)
            {
                Console.WriteLine("4:3");
            }
            else if (w/val16b9 % 16 == 0 && h/val16b9 % 9 == 0)
            {
                Console.WriteLine("16:9");
            }
        }
    }
}