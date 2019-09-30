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
                var nmk = p.getNextInt32s().ToArray();
                var n = nmk[0];
                var m = nmk[1];
                var k = nmk[2];
                Int32 answer = k;

                if (3<=n && 3<=m) {
                    // 判定最優先
                    if (n*m-4<=k) {
                        answer=2*(n+m-2)-(n*m-k);
                    }
                    else if (k<=4) {
                        answer=k;
                    }
                    else if (k==5) {
                        answer=4;
                    }
                    else if (k==6) {
                        answer=5;
                    }
                    else if (4<=n||4<=m) {
                        if (k<=8) {
                            answer=6;
                        }
                        else if (4<=n&&4<=m) {
                            if (k<=10) {
                                answer=7;
                            }
                            else if (5<=n&&5<=m) {
                                if (k<=13) {
                                    answer=8;
                                }
                                else if (k<=16) {
                                    answer=9;
                                }
                                else if (k<=19) {
                                    answer=10;
                                }
                            }
                            else if (5<=n||5<=m) {
                                if (k<=13) {
                                    answer=8;
                                }
                                else if (k<=14) {
                                    answer=9;
                                }
                                else if (k<=16) {
                                    answer=10;
                                }
                                else if (k<=17) {
                                    answer=11;
                                }
                                else if (k<=20) {
                                    answer=12;
                                }
                            }
                            else {// 幅4の場合
                                if (k<=12) {
                                    answer=8;
                                }
                                else if (k<=13) {
                                    answer=9;
                                }
                                else if (k<=16) {
                                    answer=10;
                                }
                                else if (k<=17) {
                                    answer=11;
                                }
                                else if (k<=20) {
                                    answer=12;
                                }
                            }
                        }
                        else {// 幅3の場合
                            if (k==9) {
                                answer=7;
                            }
                            if (k<=11) {
                                answer=8;
                            }
                            else if (k<=12) {
                                answer=9;
                            }
                            else if (k<=14) {
                                answer=10;
                            }
                            else if (k<=15) {
                                answer=11;
                            }
                            else if (k<=17) {
                                answer=12;
                            }
                            else if (k<=18) {
                                answer=13;
                            }
                            else if (k<=20) {
                                answer=14;
                            }
                        }
                    }
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
