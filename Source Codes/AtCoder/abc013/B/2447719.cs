using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());

            int c = Math.Abs(a - b);

            c = Math.Min(c, 10 - c);

            Console.WriteLine(c);

        }
    }
}