using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var t = Console.ReadLine();

            s = string.Join("", s.OrderBy(c => c).ToArray());
            t = string.Join("", t.OrderByDescending(c => c).ToArray());
            Console.WriteLine(string.Compare(s, t) < 0 ? "Yes" : "No");
        }
    }
}