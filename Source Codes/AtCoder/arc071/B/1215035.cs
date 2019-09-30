using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC071
{
    class LTLT
    {
        static long Mod = 1000000007;
        public static void Main()
        {
            var nm = ReadLine();
            var x = ReadLine().Trim().Split(' ').Select(i => long.Parse(i)).ToArray();
            var y = ReadLine().Trim().Split(' ').Select(i => long.Parse(i)).ToArray();
            long xArea = 0;
            for (var left = 1; left < x.Length; ++left)
                xArea = (xArea + (x[left] - x[left - 1]) * left * (x.Length - left)) % Mod;
            long yArea = 0;
            for (var left = 1; left < y.Length; ++left)
                yArea = (yArea + (y[left] - y[left - 1]) * left * (y.Length - left)) % Mod;
            WriteLine(xArea * yArea % Mod);
        }

    }
}