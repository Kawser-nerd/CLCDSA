using System;
using System.Collections.Generic;
using System.Linq;

namespace arugo
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            foreach(var s in S)
            {
                var count = 0;
                foreach (var t in S)
                {
                    if (s == t)
                        count++;
                }
                if (count > 1)
                {
                    Console.WriteLine("no");
                    return;
                }
            }
            Console.WriteLine("yes");
        }
    }
}