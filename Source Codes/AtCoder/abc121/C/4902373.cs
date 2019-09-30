using System;
using System.Linq;

namespace AtCoder.ABC121.C
{
    class Program
    {
        static void Rep(long n, Action<long> action) { for (var i = 0; i < n; ++i) { action(i); } }
        static void Rep(long n, long s, Action<long> action) { for (var i = s; i < n; ++i) { action(i); } }

        public static void Main()
        {
            // Solve(2, 5, new Tuple<long, long>[] { new Tuple<long, long>(4, 9), new Tuple<long, long>(2, 4) });
            // Solve(4, 30, new Tuple<long, long>[] {
            //      new Tuple<long, long>(6, 18),
            //      new Tuple<long, long>(2, 5),
            //      new Tuple<long, long>(3, 10),
            //      new Tuple<long, long>(7, 9)
            // });
            // Solve(1, 100000, new Tuple<long, long>[] {
            //      new Tuple<long, long>(1000000000, 100000)
            // });
            // return;

            var str1 = Console.ReadLine().Split(' ');
            var N = long.Parse(str1[0]);
            var M = long.Parse(str1[1]);
            var AB = new Tuple<long, long>[N];
            Rep(N, i =>
            {
                var str2 = Console.ReadLine().Split(' ');
                AB[i] = new Tuple<long, long>(long.Parse(str2[0]), long.Parse(str2[1]));
            });
            Solve(N, M, AB);
        }

        static void Solve(long N, long M, Tuple<long, long>[] AB)
        {
            var ABsorted = AB.OrderBy(t => t.Item1).ToArray();
            long currentNum = 0;
            long currentMoney = 0;
            long currentIndex = 0;
            while (currentNum != M)
            {
                if (ABsorted[currentIndex].Item2 < M - currentNum)
                {
                    currentNum += ABsorted[currentIndex].Item2;
                    currentMoney += ABsorted[currentIndex].Item1 * ABsorted[currentIndex].Item2;
                    ++currentIndex;
                }
                else
                {
                    var diff = M - currentNum;
                    currentNum = M;
                    currentMoney += ABsorted[currentIndex].Item1 * diff;
                }
            }
            Console.WriteLine(currentMoney);
        }
    }
}