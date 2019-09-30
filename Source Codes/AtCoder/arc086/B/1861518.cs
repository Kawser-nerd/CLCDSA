using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC086
{
    class NonDecreasing
    {
        public static void Main()
        {
            var n = int.Parse(ReadLine());
            var nums = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_)).ToArray();
            var min = nums.Min();
            var max = nums.Max();
            var minIndex = 0;
            var maxIndex = 0;
            for (var i = 0; i < nums.Count(); ++i)
            {
                if (nums[i] == min) minIndex = i + 1;
                if (nums[i] == max) maxIndex = i + 1;
            }
            WriteLine(2 * n - 1);
            if (min + max >= 0)
            {
                for (var i = 1; i <= n; ++i)
                {
                    WriteLine($"{maxIndex} {i}");
                }
                for (var i = 1; i < n; ++i)
                {
                    WriteLine($"{i} {i + 1}");
                }
            }
            else
            {
                for (var i = 1; i <= n; ++i)
                {
                    WriteLine($"{minIndex} {i}");
                }
                for (var i = n; i > 1; --i)
                {
                    WriteLine($"{i} {i - 1}");
                }
            }
        }
    }
}