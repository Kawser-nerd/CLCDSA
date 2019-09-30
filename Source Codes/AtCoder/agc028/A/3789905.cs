using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {

            var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var n = input[0];
            var m = input[1];

            var s = Console.ReadLine();
            var t = Console.ReadLine();

            var gcd = GCD(n, m);
            var ss = n / gcd;
            var tt = m / gcd;
            for (int i = 0; i < gcd; i++)
            {
                if(s[ss * i] != t[tt * i])
                {
                    Console.WriteLine("-1");
                    return;
                }
            }
            Console.WriteLine((long)ss * tt * gcd);
    }


        static int GCD(int x, int y)
        {
            if (x < y) return GCD(y, x);
            var r = x % y;
            if (r == 0) return y;
            return GCD(y, r);
        }

}