using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC064A_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            var x = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var xConnected = x[1] * 10 + x[2];
            if (xConnected % 4 == 0)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }

        }
    }
}