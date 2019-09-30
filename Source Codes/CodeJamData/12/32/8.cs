using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _1C_B
{
    class Program
    {
        //private const string FILE_NAME = "../../test.txt";
        private const string FILE_NAME = "../../small.txt";
        //private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if ((res = eval.eval(new[] { "1000.000000 2 3", "0.000000 20.500000", "25.000000 1000.000000", "1.00 5.00 9.81", }, 0)) != "\n44.7213595499958\n25\n25") throw new Exception(res);
            if ((res = eval.eval(new[] { "50.000000 2 2", "0.000000 0.000000", "100000.000000 100.000000", "1.00 1.01", }, 0)) != "\n50000\n50000") throw new Exception(res);
            //if ((res = eval.eval(new[] { "10000.000000 3 1", "0.000000 0.000000", "10000.000000 0.100000", "10000.100000 100000.000000", "1.00", }, 0)) != "\n10140.974143") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var i = 1;

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, i);
                i += eval.N + 1 + 1;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}:{1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + string.Format(" Case #{0}:{1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            private double D; //distance in meters
            public int N;
            private int A; //accelerations in m/s2

            private List<TX> ni = new List<TX>();
            private List<double> ai = new List<double>();

            private string[] lines;
            private int t;

            public string eval(string[] lines, int t)
            {
                this.lines = lines;
                this.t = t;
                string s = small();
                //string l = large();
                //if (s != l) throw new Exception(s + " != " + l);
                return s.ToString();
            }

            /// <summary>工夫する</summary>
            private string large()
            {
                parse();
                return "";
            }

            /// <summary>まともにやる</summary>
            private string small()
            {
                parse();
                var res = new StringBuilder();

                if (N == 1) ni.Add(ni[0]);

                for (int i = 0; i < A; i++)
                {
                    //前の車の速さを求める
                    var ov = (ni[1].x - ni[0].x) / (ni[1].t - ni[0].t);

                    //追いつくかどうか調べる→何秒後にDにいるか調べる
                    var ot = (D - ni[0].x) / ov;

                    // ot秒後に自分がどこにいるか調べる
                    var mx = ai[i] * ot * ot / 2.0;

                    //追い越す場合
                    if (D < mx && 0 < ot)
                    {
                        res.Append('\n').Append(ot);
                        if (ot < 0)
                        {
                            Console.WriteLine();
                        }
                    }
                    //追い越さない場合
                    else
                    {
                        //何秒後にDにいるか調べる
                        var mt = Math.Sqrt(D * 2.0 / ai[i]);
                        res.Append('\n').Append(mt);
                        if (mt < 0)
                        {
                            Console.WriteLine();
                        }
                    }
                }

                return res.ToString();
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                this.ni.Clear();
                this.ai.Clear();

                var sa = lines[t].Split(' ');
                this.D = double.Parse(sa[0]);
                this.N = int.Parse(sa[1]);
                this.A = int.Parse(sa[2]);

                for (int i = 0; i < N; i++)
                {
                    sa = lines[t + i + 1].Split(' ');
                    ni.Add(new TX(double.Parse(sa[0]), double.Parse(sa[1])));
                }
                sa = lines[t + N + 1].Split(' ');
                for (int i = 0; i < A; i++)
                {
                    ai.Add(double.Parse(sa[i]));
                }
            }

            private class TX
            {
                /// <summary>時刻</summary>
                public double t { get; private set; }
                /// <summary>場所</summary>
                public double x { get; private set; }

                public TX(double t, double x)
                {
                    this.t = t;
                    this.x = x;
                }

                public override string ToString()
                {
                    return t + " " + x;
                }
            }
        }
    }
}
