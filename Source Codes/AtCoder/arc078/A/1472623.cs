using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SplitPile
{
    class Program
    {
        public Tuple<int, int> a = new Tuple<int, int>(1,3);
        public static void Main(string[] args)
        {
            var num = int.Parse(Console.ReadLine());
            var curdNums = Console.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

            var absDiffs = new long[num - 1];
            long xSum = curdNums[0];
            long ySum = curdNums.Sum() - curdNums[0];
            absDiffs[0] = Math.Abs(xSum - ySum);

            for (int i = 1; i < absDiffs.Length; i++)
            {
                xSum += curdNums[i];
                ySum -= curdNums[i];
                absDiffs[i] = Math.Abs(xSum - ySum);
            }

            Console.WriteLine(absDiffs.Min());
        }

    }
}