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
                var t_a = p.getNextInt32s().ToArray();
                var t = t_a[0];
                var a_i = p.getNextInt32s().ToList();
                int answer = 0;
                var a_s = a_i.ToList().OrderBy(x => x).ToList();
                foreach (var item in a_s) {
                    var x = a_i.IndexOf(item);
                    answer+=Math.Min(x, a_i.Count-x-1);
                    a_i.RemoveAt(x);
                }

                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer.ToString());

//                // ＼(・ω・＼)　　(／・ω・)／
//                p.WriteAnswerFullLine(answer);

                if (i%10==0) Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);
            }
        }
        private class Train
        {
            public char Head { get; set; }
            public char Tail { get; set; }
            public HashSet<char> cart;
            public bool isSingle = false;
            public Train(string s)
            {
                cart=new HashSet<char>();
                Head=s[0];
                Tail=s[s.Length-1];
                foreach (var c in s) {
                    if (! cart.Contains(c))cart.Add(c);
                }
                if (cart.Count == 1) {
                    isSingle=true;
                }
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
