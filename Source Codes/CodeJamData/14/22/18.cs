using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ2014
{
    public class Program
    {
        //private const string FILE_NAME = "../../test.txt";
        //private const string FILE_NAME = "../../small.txt";
        private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out1BB.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if((res = eval.eval(new[] { "3 4 2", "", "", "", }, 0)) != "10") throw new Exception(res);
            if((res = eval.eval(new[] { "4 5 2", "", "", "", }, 0)) != "16") throw new Exception(res);
            if((res = eval.eval(new[] { "7 8 5", "", "", "", }, 0)) != "52") throw new Exception(res);
            if((res = eval.eval(new[] { "45 56 35", "", "", "", }, 0)) != "2411") throw new Exception(res);
            if((res = eval.eval(new[] { "103 143 88", "", "", "", }, 0)) != "14377") throw new Exception(res);
            //if((res = eval.eval(new[] { "1000000000 1000000000 0", "", "", "", }, 0)) != "") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1; //行数

            for(int t = 0; t < T; t++)
            {
                res = eval.eval(lines, l);
                l += 1; //1Caseあたりの行数

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + "." + DateTime.Now.Second + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int A; //
            public int B; //
            public int K; //

            private string[] lines;
            private int l;

            public string eval(string[] lines, int l)
            {
                this.lines = lines;
                this.l = l;
                //string sans = small();
                string lans = large();
                //if(sans != lans) throw new Exception(sans + " != " + lans);
                //return sans.ToString();
                return lans.ToString();
            }

            /// <summary>工夫する</summary>
            private string large()
            {
                parse();
                var k = long.Parse(Math.Min(Math.Min(A, K), Math.Min(B, K)).ToString());
                var res = 0L;
                res += A * k + B * k - k * k;

                for(long a = k; a < A; a++)
                {
                    for(long b = k; b < B; b++)
                    {
                        if((a & b) < k)
                        {
                            res++;
                        }
                    }
                }

                return res.ToString();
            }

            /// <summary>まともにやる</summary>
            private string small()
            {
                parse();
                var res = 0;

                for(int a = 0; a < A; a++)
                {
                    for(int b = 0; b < B; b++)
                    {
                        if((a & b) < K) res++;
                    }
                }

                return res.ToString();
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                A = int.Parse(lines[l].Split(' ')[0]);
                B = int.Parse(lines[l].Split(' ')[1]);
                K = int.Parse(lines[l].Split(' ')[2]);
            }
        }
    }
}
