using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var vals = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var N = vals[0];
            var K = vals[1];

            var rates = Console.ReadLine().Split(' ').Select(x => int.Parse(x))
                .OrderByDescending(x => x).Take(K).OrderBy(x => x).ToArray();
            var result = 0.0;
            foreach(var r in rates)
            {
                result = (result + (double)r) / 2.0;
            }

            Console.WriteLine(result);
        }
    }
}