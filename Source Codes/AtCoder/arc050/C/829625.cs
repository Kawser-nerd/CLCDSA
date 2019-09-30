using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var a = Int64.Parse(str[0]);
            var b = Int64.Parse(str[1]);
            var mod = Int64.Parse(str[2]);

            var gcd = Gcd(a, b);

            var ret = ModPowSum(10, b, mod);
            ret *= ModPowSum(ModPow(10, gcd, mod), a / gcd, mod);
            Console.WriteLine(ret % mod);
        }

        static Int64 Lcm(Int64 a, Int64 b)
        {
            return (a * b) / Gcd(a, b);
        }

        static Int64 Gcd(Int64 a, Int64 b)
        {
            if (a < b)
            {
                var tmp = a;
                a = b;
                b = tmp;
            }
            if (b == 0) return a;
            var p = a > b ? a : b;
            return Gcd(b, p % b);
        }

        static public Int64 ModPow(Int64 x, Int64 n, Int64 mod)
        {
            Int64 ret = 1;
            while (n > 0)
            {
                if ((n & 1) == 1) ret = ret * x % mod;
                x = x * x % mod;
                n >>= 1;
            }
            return ret;
        }

        //????????????????O(Logn)?
        public static Int64 ModPowSum(Int64 r, Int64 n, Int64 mod)
        {
            if (n == 0) return 0;
            
            //n????1 + r + ... + r^(n-1) = 1 + r(1 + r + ... + r^(n-2))
            if (n % 2 == 1) return (ModPowSum(r, n - 1, mod) * r + 1) % mod;

            //n????1 + r + ... + r^(n-1) = ( 1 + r + ... + r^(n/2-1)) +  r^(n/2) x ( 1 + r + ... + r^(n/2-1))
            Int64 result = ModPowSum(r, n / 2, mod);
            return (result * ModPow(r, n / 2, mod) + result) % mod;
        }
    }
}