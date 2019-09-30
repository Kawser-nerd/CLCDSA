using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Get());
        }

        static int Get()
        {
            var sp = ReadLine().Split(' ');
            int a = int.Parse(sp[0]);
            int b = int.Parse(sp[1]);
            int c = int.Parse(sp[2]);
            int x = int.Parse(sp[3]);
            int y = int.Parse(sp[4]);
            if (a + b <= c * 2) return a * x + b * y;
            if (x == y) return c * x * 2;
            if (x < y)
            {
                if (c * 2 <= b) return c * y * 2;
                return c * x * 2 + b * (y - x);
            }
            if (c * 2 <= a) return c * x * 2;
            return c * y * 2 + a * (x - y);
        }
    }
}