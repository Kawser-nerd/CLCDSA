using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC120
{
    class Program
    {
        static void Main(string[] args)
        {
            A();
        }

        static void A()
        {
            var ABC = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var a = ABC[1] / ABC[0];
            Console.WriteLine(a >= ABC[2] ? ABC[2] : a);
        }
    }
}