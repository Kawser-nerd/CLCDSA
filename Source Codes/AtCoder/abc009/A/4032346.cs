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
            if (n % 2 == 1) {
            Console.WriteLine(n/2 + 1);
            Console.ReadKey();
        }
            else if (n % 2 == 0){

                Console.WriteLine(n/2);
            Console.ReadKey();
        }
}
    }
}