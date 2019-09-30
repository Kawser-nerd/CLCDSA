using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

            var count = 0;

            foreach (var item in a)
            {
                var flower = item;

                while (flower % 3 == 2 || flower % 2 == 0)
                {
                    flower--;
                }

                count += item - flower;
            }

            Console.WriteLine(count);
        }
    }
}