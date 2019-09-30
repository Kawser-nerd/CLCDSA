using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ2013
{
    public class Program
    {
        //private const string FILE_NAME = "../../test.txt";
        //private const string FILE_NAME = "../../small.txt";
        private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out1BA.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if ((res = eval.eval(new[] { "2 2", "2 1", "", "", }, 0)) != "0") throw new Exception(res);
            if ((res = eval.eval(new[] { "2 4", "2 1 1 6", "", "", }, 0)) != "1") throw new Exception(res);
            if ((res = eval.eval(new[] { "10 4", "25 20 9 100", "", "", }, 0)) != "2") throw new Exception(res);
            if ((res = eval.eval(new[] { "1 4", "1 1 1 1", "", "", }, 0)) != "4") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1; //行数

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, l);
                l += 2;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + "." + DateTime.Now.Second + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int A; //初期値
            public int N; //塵の数

            private int[] motes;

            private string[] lines;
            private int l;

            public string eval(string[] lines, int l)
            {
                this.lines = lines;
                this.l = l;
                string sans = small();
                //string lans = large();
                //if (sans != lans) throw new Exception(sans + " != " + lans);
                return sans.ToString();
                //return lans.ToString();
            }

            /// <summary>工夫する</summary>
            private string large()
            {
                parse();
                var res = new StringBuilder();

                return res.ToString();
            }

            /// <summary>まともにやる</summary>
            private string small()
            {
                parse();
                if (A == 1) return N.ToString();

                var res = new StringBuilder();
                long a = A;

                return solve(A, 0, 0).ToString();
            }

            /// <summary>aとiを受け取ってresを返す</summary>
            private int solve(long a, int i, int res)
            {
                for (; i < N; i++)
                {
                    var m = motes[i];
                    // a未満なら回収
                    if (m < a)
                    {
                        a += m;
                        continue;
                    }

                    var resa = res;
                    var resr = res + (N - i);

                    // a以上なら塵を足す
                    while (a <= m)
                    {
                        a += a - 1;
                        resa++;
                    }
                    if (resa < resr) resa = solve(a, i, resa);
                    else return resr;

                    if (resa < resr) return resa;
                    else return resr;
                }
                return res;
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                A = int.Parse(lines[l].Split(' ')[0]);
                N = int.Parse(lines[l].Split(' ')[1]);
                motes = new int[N];

                var linemote = lines[l + 1].Split(' ');

                for (int i = 0; i < N; i++)
                {
                    motes[i] = int.Parse(linemote[i]);
                }
                Array.Sort<int>(motes);
            }
        }
    }
}
