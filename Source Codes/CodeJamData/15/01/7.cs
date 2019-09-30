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
//            Console.WriteLine("Start");

            // 試行回数を取得し、ループする。
            long repeat = p.getNextInt64s().ToArray()[0];
            for (int i = 0; i < repeat; i++)
            {
//                Console.WriteLine("i:{0}", i);
                // MainLoop
                var line = p.getNexts().ToArray();
                var audiences = line[1].ToCharArray().Select(x => int.Parse(x.ToString())).ToArray();
                int friends = 0;
                int totalAudience = 0;
                for (int j = 0; j < audiences.Count(); j++)
                {
//                    Console.WriteLine("j:{0}", j);
                    if (totalAudience < j)
                    {
                        friends += j - totalAudience;
                        totalAudience = j;
                    }
                    totalAudience += audiences[j];
                }

                var answer = friends;
                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer.ToString());

                if (i % 10 == 0) Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);
            }
        }

        private static Int64 gcd(Int64 a,Int64 b){
            if (a>b) {
                var c = a;
                a=b;
                b=c;
            }
            if (b%a == 0) {
                return a;
            }
            else {
                return gcd(a, b%a);
            }
        }
    }
}
