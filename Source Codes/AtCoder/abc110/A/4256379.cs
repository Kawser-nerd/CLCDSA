using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.Maximize_the_Formula
{
    class Program
    {
        static void Main(string[] args)
        {
            var num = Console.ReadLine().Split(null).ToArray();
            int res;

            num = num.OrderByDescending(x => x).ToArray();

            res = int.Parse(string.Join(null, num.Take(2))) + int.Parse(string.Join(null, num.Skip(2).Take(1)));

            Console.WriteLine(res);
        }
    }
}