using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static long[] calc(int K)
        {
            var res = new long[2] { 2, 1 };
            while (K > 1)
            {
                var a = res[0] + res[1];
                var b = res[0];
                res[0] = a;
                res[1] = b;
                K--;
            }
            return res;
        }
        static void Main(string[] args)
        {
            //var buffer = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var K = int.Parse(Console.ReadLine());
            var res = calc(K);
            Console.WriteLine("{0} {1}", res[0], res[1]);
        }
    }
}