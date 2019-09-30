using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.OtherPractice
{
    class AtTemplate
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            long a = long.Parse(input[0]);
            long b = long.Parse(input[1]);
            long x = long.Parse(input[2]);

            long min = (a - 1) / x;
            if (a == 0)
            {
                min = -1;
            }
            long max = b / x;

            long cnt = max - min;
            Console.WriteLine(cnt);
        }
    }
}