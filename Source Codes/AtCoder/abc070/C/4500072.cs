using System;
using System.Collections.Generic;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // ????n?????
            int n = int.Parse(input);

            // ??????????????????
            List<ulong> times = new List<ulong>();

            // ??
            for(int i = 0; i < n; i++)
            {
                times.Add(ulong.Parse(Console.ReadLine()));
            }

            // ?????????
            while (times.Count != 1u)
            {
                ulong tmp = Lcm(times[0], times[1]);
                times.RemoveAt(1);
                times.RemoveAt(0);
                times.Add(tmp);
            }

            // ???????
            Console.WriteLine(times[0]);
        }

        // ?????
        static ulong Lcm(ulong a, ulong b)
        {
            return a / Gcd(a, b) * b;
        }

        // ??????????
        static ulong Gcd(ulong a, ulong b)
        {
            return (a < b) ? Gcd(b, a)
                : (b > 0) ? Gcd(b, a % b)
                : a;
        }
    }
}