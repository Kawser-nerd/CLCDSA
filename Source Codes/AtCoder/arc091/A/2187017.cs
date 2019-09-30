using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder.Regular091
{
    public class ARC091C_Flip
    {
        public static void Main(string[] args)
        {

            long[] nums = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            long n = nums[0];
            long m = nums[1];

            if(n > m)
            {
                long w = n;
                n = m;
                m = w;
            }

            if(n > 2 && m > 2)
            {
                Console.WriteLine((n - 2) * (m - 2));
            }
            else if(n == 1 && m == 1)
            {
                Console.WriteLine(1);
            }
            else if(n == 1 && m >= 2)
            {
                Console.WriteLine(m - 2);
            }
            else
            {
                Console.WriteLine(0);
            }
            
        }
    }
}