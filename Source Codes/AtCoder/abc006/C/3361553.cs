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
            var M = vals[1];

            //????????
            //a=???b=???c=???????
            // 2a+3b+4c=M
            // a+b+c=N
            //c=c*??????????
            // a = -M + 3N + c*
            // b = M - 2N - 2c*
            //??????
            for(var child = 0; child <= Math.Min(N, M/4); child++)
            {
                var adult = -M + 3 * N + child;
                var silver = M - 2 * N - 2 * child;
                if(adult >= 0 && silver >= 0)
                {
                    Console.WriteLine($"{adult} {silver} {child}");
                    return;
                }
            }
            Console.WriteLine("-1 -1 -1");
        }
    }
}