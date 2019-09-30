using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace km.gcj.gcj2014
{
    class Program
    {
        static System.Diagnostics.Stopwatch sw;

        /// <summary> プログラムのスタートポイント </summary>
        /// <param name="args"> 第一引数に入力ファイルを指定 </param>
        static void Main(string[] args)
        {
            sw=new System.Diagnostics.Stopwatch();
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args)
        {
            Problem2 p = Problem2.createProblem(args);
            if (p==null) {
                return;
            }

            // 試行回数を取得し、ループする。
            long repeat = p.getNextInt64s().ToArray()[0];
            for (int i = 0; i<repeat; i++) {
                // MainLoop
                var pq = p.getNext().Split('/').Select(s=>Int64.Parse(s)).ToArray();
                var a = pq[0];
                var b = pq[1];

                //G.C.D.
                var g = gcd(a, b);
                a=a/g;
                b=b/g;

                Int64 b_buf = 1;
                bool flg = false;
                int j = 0;
                int k = 0;
                for (j = 0; !flg&j<40; j++) {
                    if (b == b_buf) {
                        flg=true;
                    }
                    if (a>=b_buf) {
                        k=j;
                    }
                    b_buf*=2;
                }
                j--;
                j-=k;

                var answer = j;
                // ＼(・ω・＼)　　(／・ω・)／
                if (flg) {
                    p.WriteAnswerFullLine(answer.ToString());
                }
                else {
                    p.WriteAnswerFullLine("impossible");
                }

//                // ＼(・ω・＼)　　(／・ω・)／
//                p.WriteAnswerFullLine(answer);

                if (i%10==0) Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);
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
