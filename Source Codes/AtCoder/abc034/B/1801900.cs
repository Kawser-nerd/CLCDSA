using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Solve();
        }

        void Solve()
        {
            var x = int.Parse(Console.ReadLine());
            Console.WriteLine(x % 2 == 0 ? x - 1 : x + 1);
        }

    }
}