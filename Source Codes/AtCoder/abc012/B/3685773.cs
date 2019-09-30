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

            var h = n / 3600;
            n %= 3600;
            var m = n / 60;
            n %= 60;
            var s = n;

            Console.WriteLine("{0:D2}:{1:D2}:{2:D2}", h, m, s);
        }
    }
}