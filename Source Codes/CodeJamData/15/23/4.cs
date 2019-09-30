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
                var n = p.getNextInt32s().ToArray()[0];

                List<Hiker> list = new List<Hiker>();

                for (int j = 0; j < n; j++)
                {
                    var dhm = p.getNextInt32s().ToArray();
                    for (int k = 0; k < dhm[1]; k++)
                    {
                        list.Add(new Hiker() { Degree = dhm[0], Slowness = dhm[2] + k });
                    }
                }

                int result = 0;

                list = list.OrderBy(x => x.Slowness).ToList();

                if (list.Count()==2)
                {
                    var time1 = list[0].GetTime(1);
                    var time2 = list[1].GetTime(0);
                    if (time1<=time2)
                    {
                        result++;
                    }
                }

                var answer = result.ToString();
                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer);

                if (i % 10 == 0) Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);
            }
        }

        class Hiker
        {
            public int Degree { get; set; }
            public int Slowness { get; set; }
            public long GetTime(int cycle = 0)
            {
                return (long)(360 * (cycle + 1) - Degree) * Slowness;
            }
        }

        private static long count(long prm)
        {
            long result;
            if (prm < 21)
            {
                result = prm;
            }
            else
            {
                result = 0;
                long rev;
                var amari = (prm - 1) % 10;
                result += amari;
                prm -= amari;
                rev = long.Parse(new string((prm).ToString().Reverse().ToArray()));
                while (prm <= rev)
                {
                    amari = (prm - 1) % 10;
                    amari = amari == 0 ? 10 : amari;
                    result += amari;
                    prm -= amari;
                    rev = long.Parse(new string((prm).ToString().Reverse().ToArray()));
                } 
                result += 1;
                result += count(rev);
            }
            return result;
        }

        private static long count_bk(long prm)
        {
            long result;
            if (prm < 21)
            {
                result = prm;
            }
            else
            {
                int d;
                long nDash = prm - 1;
                for (d = 1; d < 14; d++)
                {
                    nDash = nDash / 10;
                    if (nDash < 21) break;
                }

                long target = nDash > 9 ? 9 : nDash;
                for (int j = 0; j < d; j++)
                {
                    target *= 10;
                }
                Console.WriteLine(target);
                result = prm - target;
                Console.WriteLine("{0}\t{1}", d, nDash);
                result += count_bk(long.Parse(new string((target+1).ToString().Reverse().ToArray())));
            }
            return result;
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

}
