using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC090
{
    class Candies
    {
        public static void Main()
        {
            var n = int.Parse(ReadLine().Trim());
            var upper = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_)).ToArray();
            var lower = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_)).ToArray();
            for (var i = 1; i < n; ++i)
            {
                upper[i] += upper[i - 1];
                lower[n - i - 1] += lower[n - i];
            }
            WriteLine(upper.Zip(lower, (a, b) => a + b).Max());
        }
    }
}