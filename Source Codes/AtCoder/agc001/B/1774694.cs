using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var l = Console.ReadLine().Split(' ').Select(y => long.Parse(y)).ToArray();

            var n = l[0];
            var x1 = (n - l[1] > l[1]) ? n - l[1] : l[1];
            var x2 = (n - l[1] <= l[1]) ? n - l[1] : l[1];
            var sum = n;
            long a = 0;
            while (true)
            {
                a = x1 % x2;
                sum += (x1 - a) * 2;
                if (a == 0)
                {
                    sum -= x2;
                    break;
                }
                x1 = x2;
                x2 = a;
            }
            Console.Write(sum);
            
        }
    }
}