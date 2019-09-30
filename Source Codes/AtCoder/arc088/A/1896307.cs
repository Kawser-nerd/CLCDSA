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
            var arg = Console.ReadLine().Split(' ');
            var x = long.Parse(arg[0]);
            var y = long.Parse(arg[1]);

            int i = 0;
            while(x<=y)
            {
                i++;
                x *= 2;
            }
            Console.WriteLine(i);
        }
    }
}