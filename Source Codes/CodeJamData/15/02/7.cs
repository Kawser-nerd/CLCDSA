using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace km.gcj.gcj2015
{
    class Program
    {
        static System.Diagnostics.Stopwatch sw;

        /// <summary> プログラムのスタートポイント </summary>
        /// <param name="args"> 第一引数に入力ファイルを指定 </param>
        static void Main(string[] args)
        {
            sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args)
        {
            Problem p = Problem.createProblem(args);
            if (p==null) {
                return;
            }

            // 試行回数を取得し、ループする。
            long repeat = p.getNextInt64s().ToArray()[0];
            for (int i = 0; i < repeat; i++)
            {
                // MainLoop
                var cnt = p.getNextInt64s().ToArray()[0];
                var pancakes = p.getNextInt32s();
                var diners = pancakes.OrderByDescending(x=>x).Select(x => new Diner { Pancakes = x }).ToArray();
                var max = diners.First().Pancakes;
                var answer = max;

                for (int cake = max - 2; cake >= Math.Sqrt(max); cake--)
                {
                    var sumShares = diners.Sum(x => x.getShares(cake));
                    answer = cake + sumShares < answer ? cake + sumShares : answer;
                }

                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer.ToString());

                if (i % 10 == 0) Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);
            }
        }

        private static Int64 gcd(Int64 a, Int64 b)
        {
            if (a > b)
            {
                var c = a;
                a = b;
                b = c;
            }
            if (b % a == 0)
            {
                return a;
            }
            else
            {
                return gcd(a, b % a);
            }
        }
    }

    class Diner
    {
        public int Pancakes;

        public int getShares(int maxPancake)
        {
            for (int i = 0; i < Math.Sqrt(Pancakes); i++)
            {
                if ((this.Pancakes + i) / (i+1) <= maxPancake)
                {
                    return i;
                }
            }
            return 0;
        }

        public IEnumerable<EatPattern> getEatPatterns()
        {
            for (int i = 0; i < Math.Sqrt(Pancakes); i++)
            {
                yield return new EatPattern { Shares = i, Pancakes = (this.Pancakes + (i-1)) / i };
            }
            yield break;
        }
    }

    struct EatPattern
    {
        public int Shares;
        public int Pancakes;
    }
}
