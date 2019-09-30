using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC077
{
    class pushpush
    {
        public static void Main()
        {
            var n = int.Parse(ReadLine().Trim());
            var nums = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_)).ToArray();
            var even = nums.Where((v, i) => i % 2 == 1);
            var odd = nums.Where((v, i) => i % 2 == 0);
            Write(string.Join(" ", (n % 2 == 0) ? even.Reverse() : odd.Reverse()));
            if (n != 1) Write(' ');
            Write(string.Join(" ", (n % 2 == 0) ? odd : even));
        }
    }
}