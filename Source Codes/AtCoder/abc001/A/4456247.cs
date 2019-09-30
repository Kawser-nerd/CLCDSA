using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC001A
{
    class Program
    {
        static void Main(string[] args)
        {
            var h1 = int.Parse(Console.ReadLine());
            var h2 = int.Parse(Console.ReadLine());

            var h = h1 - h2;
            Console.WriteLine($"{h}");
        }
    }
}