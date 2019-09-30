using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            if (n==12) {
            Console.WriteLine("1");
            Console.ReadKey();
        }
            else
                Console.WriteLine(n+1);
            Console.ReadKey();
        }
}
    }