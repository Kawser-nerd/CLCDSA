using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC078
{
    class SplittingPile
    {
        public static void Main()
        {
            var n = int.Parse(ReadLine());
            var cards = ReadLine().Split(' ').Select(_ => long.Parse(_)).ToArray();
            var sum = cards.Sum();
            long min = long.MaxValue;
            long s = 0;
            for (var i = 0; i < cards.Length - 1; ++i) {
                s += cards[i];
                if (min > Math.Abs(sum - s - s)) {
                    min = Math.Abs(sum - s - s);
                }
            }
            WriteLine(min);
        }
    }
}