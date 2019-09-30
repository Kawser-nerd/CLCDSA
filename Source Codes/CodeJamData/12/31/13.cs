using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _1C_A
{
    class Program
    {
        //private const string FILE_NAME = "../../test.txt";
        //private const string FILE_NAME = "../../small.txt";
        private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if ((res = eval.eval(new[] { "3", "1 2", "1 3", "0", }, 0)) != "No") throw new Exception(res);
            if ((res = eval.eval(new[] { "5", "2 2 3", "1 4", "1 5", "1 5", "0", }, 0)) != "Yes") throw new Exception(res);
            if ((res = eval.eval(new[] { "3", "2 2 3", "1 3", "0", }, 0)) != "Yes") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var i = 1;

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, i);
                i += eval.N + 1;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int N;
            private List<HashSet<int>> Mi = new List<HashSet<int>>();

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
                if (N < 3) return "No";

                for (int i = 0; i < N; i++)
                {
                    var all = Mi.FindAll(l => l.Contains(i + 1));
                    foreach (var a in all)
                    {
                        foreach (var n in Mi[i])
                        {
                            if (a.Contains(n))
                                return "Yes";
                            a.Add(n);
                        }
                    }
                }

                return "No";
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                this.Mi.Clear();
                var sa = lines[t].Split(' ');
                this.N = int.Parse(sa[0]);
                for (int i = 0; i < N; i++)
                {
                    sa = lines[t + i + 1].Split(' ');
                    var list = new HashSet<int>();
                    for (int j = 1; j < sa.Length; j++)
                    {
                        list.Add(int.Parse(sa[j]));
                    }
                    Mi.Add(list);
                }
            }
        }
    }
}
