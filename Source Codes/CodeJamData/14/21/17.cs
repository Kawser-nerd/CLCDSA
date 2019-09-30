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
        private const string FILE_NAME = "../../small.txt";
        //private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out1BA.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if((res = eval.eval(new[] { "2", "nfckzrylcxyxqwqnosqkvxurvlxglkbypflqyjc", "nfckzrylcxyxqwqnosqkvxurvlxglkbypflqyj", "", }, 0)) != "Fegla Won") throw new Exception(res);
            if((res = eval.eval(new[] { "2", "aaabbb", "ab", "", }, 0)) != "4") throw new Exception(res);
            if((res = eval.eval(new[] { "2", "ab", "aaabbb", "", }, 0)) != "4") throw new Exception(res);
            if((res = eval.eval(new[] { "2", "gcj", "cj", "", }, 0)) != "Fegla Won") throw new Exception(res);
            if((res = eval.eval(new[] { "2", "mmaw", "maw", "", }, 0)) != "1") throw new Exception(res);
            if((res = eval.eval(new[] { "2", "abc", "abc", "", }, 0)) != "0") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1; //行数

            for(int t = 0; t < T; t++)
            {
                res = eval.eval(lines, l);
                l += eval.N + 1; //1Caseあたりの行数

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + "." + DateTime.Now.Second + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int N; //
            private string[] s; //
            public const string WON = "Fegla Won";

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

                // check Fegla Won
                var orig0 = new List<char>(" ");
                var orig1 = new List<char>(" ");
                foreach(var ss in s[0])
                {
                    if(orig0.Last() != ss) orig0.Add(ss);
                }
                foreach(var ss in s[1])
                {
                    if(orig1.Last() != ss) orig1.Add(ss);
                }
                if(!orig0.SequenceEqual(orig1)) return WON;

                if(s[0] == s[1]) return "0";

                var res = 0;
                var ps0 = 0; var ps1 = 0;
                while(ps0 < s[0].Length && ps1 < s[1].Length)
                {
                    if(s[0][ps0] == s[1][ps1])
                    {
                        ps0++; ps1++; continue;
                    }
                    res++;

                    if(s[0][ps0 - 1] == s[0][ps0])
                    {
                        ps0++; continue;
                    }
                    ps1++;
                }

                return res.ToString();
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                N = int.Parse(lines[l]);
                s = new string[N];

                for(int i = 0; i < N; i++)
                {
                    s[i] = lines[l + 1 + i] + " ";
                }
            }
        }
    }
}
