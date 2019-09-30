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
            if (p == null)
            {
                return;
            }

            // 試行回数を取得し、ループする。
            long repeat = p.getNextInt64s().ToArray()[0];
            for (int i = 0; i < repeat; i++)
            {
                // MainLoop
                var rc = p.getNextInt32s().ToArray();
                int row = rc[0];
                int col = rc[1];

                long result = 0;

                if (row == 2)
                {
                    // 3 3 3 3 3
                    // 3 3 3 3 3
                    result = 1;

                    // 2 2 1
                    // 2 2 1
                    if (col % 3 == 0)
                    {
                        result += 1;
                    }

                    // 2 1 1 2 2 2
                    // 2 2 2 2 1 1
                    if (col % 6 == 0)
                    {
                        result += 1;
                    }
                }
                else if (row == 3)
                {
                    // 2 2 2 2 2
                    // 3 3 3 3 3
                    // 3 3 3 3 3
                    result = 2;

                    // 2 1 2 2
                    // 2 1 2 1
                    // 2 2 2 1
                    if (col % 4 == 0)
                    {
                        result += 1;
                    }
                }
                else if (row == 4)
                {
                    // 2 2 2 2 2
                    // 3 3 3 3 3
                    // 3 3 3 3 3
                    // 2 2 2 2 2
                    result = 1;

                    // 2 2 1
                    // 2 2 1
                    // 3 3 3
                    // 3 3 3
                    if (col % 3 == 0)
                    {
                        result += 2;
                    }
                    // 2 1 1 2 2 2
                    // 2 2 2 2 1 1
                    // 3 3 3 3 3 3
                    // 3 3 3 3 3 3
                    if (col % 6 == 0)
                    {
                        result += 2;
                    }
                }
                else if (row == 5)
                {
                    // 3 3 3 3 3
                    // 3 3 3 3 3
                    // 2 2 2 2 2
                    // 3 3 3 3 3
                    // 3 3 3 3 3
                    result = 1;

                    // 3 3 3 3
                    // 3 3 3 3
                    // 2 1 2 2
                    // 2 1 2 1
                    // 2 2 2 1
                    if (col % 4 == 0)
                    {
                        result += 2;
                    }

                    // 2 2 1
                    // 2 2 1
                    // 3 3 3
                    // 3 3 3
                    // 2 2 2
                    if (col % 3 == 0)
                    {
                        result += 2;
                    }

                    // 2 1 1 2 2 2
                    // 2 2 2 2 1 1
                    // 3 3 3 3 3 3
                    // 3 3 3 3 3 3
                    // 2 2 2 2 2 2
                    if (col % 6 == 0)
                    {
                        result += 2;
                    }
                }
                else if (row == 6)
                {
                    // 3 3 3 3 3
                    // 3 3 3 3 3
                    // 2 2 2 2 2
                    // 3 3 3 3 3
                    // 3 3 3 3 3
                    // 2 2 2 2 2
                    result = 2;

                    // 2 1 2 2
                    // 2 1 2 1
                    // 2 2 2 1
                    // 3 3 3 3
                    // 3 3 3 3
                    // 2 2 2 2
                    if (col % 4 == 0)
                    {
                        result += 2;
                    }

                    // 2 2 1
                    // 2 2 1
                    // 3 3 3
                    // 3 3 3
                    // 2 2 1
                    // 2 2 1
                    // rot x3

                    // 3 3 3
                    // 3 3 3
                    // 2 2 1
                    // 2 2 1
                    // 3 3 3
                    // 3 3 3
                    if (col % 3 == 0)
                    {
                        result += 4;
                    }

                    // 2 2 1 2 2 1
                    // 2 2 1 2 2 1
                    // 3 3 3 3 3 3
                    // 3 3 3 3 3 3
                    // 2 1 1 2 2 2
                    // 2 2 2 2 1 1
                    // rot x3
                    // topbottom x2

                    // 2 1 1 2 2 2
                    // 2 2 2 2 1 1
                    // 3 3 3 3 3 3
                    // 3 3 3 3 3 3
                    // 2 1 1 2 2 2
                    // 2 2 2 2 1 1
                    // rot x6

                    // 3 3 3 3 3 3
                    // 3 3 3 3 3 3
                    // 2 1 1 2 2 2
                    // 2 2 2 2 1 1
                    // 3 3 3 3 3 3
                    // 3 3 3 3 3 3
                    if (col % 6 == 0)
                    {
                        result += 13;
                    }
                }

                var answer = (result % 1000000007).ToString();
                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer);

                if (i % 10 == 0) Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);
            }
        }

        private static void LogicB(string[] args)
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
                var nvx = p.getNexts().ToArray();
                var n = int.Parse(nvx[0]);
                var vol = double.Parse(nvx[1]) * 10000;//volume
                var tem = double.Parse(nvx[2]) * 10000;//temperature

                var sources = new List<double[]>();

                for (int j = 0; j < n; j++)
                {
                    sources.Add(p.getNextDoubles().Select(x=>x*10000).ToArray());
                }

                double result = 0.0;

                if (sources.Where(x => x[1] <= tem).Count() == 0 || sources.Where(x => x[1] >= tem).Count() == 0)
                {
                    p.WriteAnswerFullLine("IMPOSSIBLE");
                    continue;
                }
                else
                {
                    if (n==1)
                    {
                        result = vol / sources[0][0];
                    }
                    else if (n==2)
                    {
                        if (sources[0][1] == tem && sources[1][1] == tem)
	                    {
                            result = vol / (sources[0][0] + sources[1][0]);
	                    }
                        else if (sources[0][1] != tem && sources[1][1] == tem)
                        {
                            result = vol / sources[1][0];
                        }
                        else if (sources[0][1] == tem && sources[1][1] != tem)
                        {
                            result = vol / sources[0][0];
                        }
                        else
                        {
                            result = Math.Max(
                                vol * ((sources[0][1] - tem) / (sources[0][1] - sources[1][1])) / sources[1][0],
                                vol * ((sources[1][1] - tem) / (sources[1][1] - sources[0][1])) / sources[0][0]
                                );
                        }
                    }
                }
                


                var answer = result.ToString("0.00000000");
                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer);

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

}
