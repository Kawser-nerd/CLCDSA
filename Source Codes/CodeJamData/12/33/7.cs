using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _1C_C
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
            if ((res = eval.eval(new[] { "1 1", "5000000 10", "5000000 100", "", }, 0)) != "0") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 3", "10 1 20 2 25 3", "10 2 30 3 20 1", "", }, 0)) != "35") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 5", "10 1 6 2 10 1", "5 1 3 2 10 1 3 2 5 1", "", }, 0)) != "20") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 5", "10 1 6 2 10 1", "5 1 6 2 10 1 6 2 5 1", "", }, 0)) != "21") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var i = 1;

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, i);
                i += 3;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            private int N;
            private int M;
            private List<Aa> Ni = new List<Aa>();
            private List<Aa> Mi = new List<Aa>();

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
                var res = sub(Ni, Mi);
                return res.ToString();
            }

            private static long sub(List<Aa> Ni, List<Aa> Mi)
            {
                var res = 0L;
                var Ni2 = new List<Aa>();
                var Mi2 = new List<Aa>();
                foreach (var n in Ni)
                {
                    Ni2.Add(new Aa(n.a, n.A));
                }
                foreach (var n in Mi)
                {
                    Mi2.Add(new Aa(n.a, n.A));
                }
                if (Ni2.Count == 0 || Mi2.Count == 0) return res;

                //同じIDなら出荷
                while (Ni2[0].A == Mi2[0].A)
                {
                    if (Ni2[0].a == Mi2[0].a)
                    {
                        res += Ni2[0].a;
                        Ni2.RemoveAt(0);
                        Mi2.RemoveAt(0);
                    }
                    else if (Ni2[0].a < Mi2[0].a)
                    {
                        res += Ni2[0].a;
                        Mi2[0].a -= Ni2[0].a;
                        Ni2.RemoveAt(0);
                    }
                    else
                    {
                        res += Mi2[0].a;
                        Ni2[0].a -= Mi2[0].a;
                        Mi2.RemoveAt(0);
                    }
                    if (Ni2.Count == 0 || Mi2.Count == 0) return res;
                }

                if (Ni2.Count == 0 || Mi2.Count == 0) return res;

                //Nを捨てる
                var add1 = sub(Ni2.GetRange(1, Ni2.Count - 1), Mi2);

                //Mを捨てる
                var add2 = sub(Ni2, Mi2.GetRange(1, Mi2.Count - 1));

                res += (add1 < add2) ? add2 : add1;
                return res;
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                this.Ni.Clear();
                this.Mi.Clear();
                var sa = lines[t].Split(' ');
                this.N = int.Parse(sa[0]);
                this.M = int.Parse(sa[1]);

                sa = lines[t + 1].Split(' ');
                for (int i = 0; i < N; i++)
                {
                    this.Ni.Add(new Aa(long.Parse(sa[i * 2]), long.Parse(sa[i * 2 + 1])));
                }
                sa = lines[t + 2].Split(' ');
                for (int i = 0; i < M; i++)
                {
                    this.Mi.Add(new Aa(long.Parse(sa[i * 2]), long.Parse(sa[i * 2 + 1])));
                }
            }

            private class Aa
            {
                public long a { get; set; }
                public long A { get; set; }

                public Aa(long a, long A)
                {
                    this.a = a;
                    this.A = A;
                }

                public override string ToString()
                {
                    return a + " " + A;
                }
            }
        }
    }
}
