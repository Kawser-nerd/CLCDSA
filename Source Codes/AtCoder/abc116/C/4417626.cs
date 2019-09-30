using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] h = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            Console.WriteLine("{0}", f(h, 0, N - 1));
        }

        public static int f(int[] nums, int l, int r)
        {
            for (int i = l; i < r + 1; i++)
            {
                if (nums[i] > 0) { nums[i]--; continue; }
                // Console.WriteLine("{0} {1} {2}", i, l, r);
                return (l == r) ? 0 :
                       (i == l) ? f(nums, i + 1, r) :
                       (i == r) ? 1 + f(nums, l, i - 1)
                                : 1 + f(nums, l, i - 1) + f(nums, i + 1, r);
            }
            return 1 + f(nums, l, r);
        }
    }
}