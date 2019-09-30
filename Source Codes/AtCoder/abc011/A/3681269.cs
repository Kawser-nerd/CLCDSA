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
            var n = int.Parse(Console.ReadLine());
            if (n == 12)
            {
                Console.WriteLine(1);
            }
            else
            {
                Console.WriteLine(n + 1);
            }
        }
    }
}