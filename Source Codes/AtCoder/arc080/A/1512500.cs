using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC080
{
    class FourAdjacent
    {
        public static void Main()
        {
            var n = int.Parse(ReadLine().Trim());
            var a = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_));
            var b1 = a.Where(_ => _ % 2 != 0).Count();
            var b2 = a.Where(_ => _ % 4 == 2).Count();
            var b4 = a.Where(_ => _ % 4 == 0).Count();
            if (b1 + (b2 % 2)<= b4 + 1) WriteLine("Yes");
            else WriteLine("No");
        }
    }
}