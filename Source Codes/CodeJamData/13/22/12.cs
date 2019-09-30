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
        private const string FILE_NAME = "../../small.txt";
        //private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out1BB.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if ((res = eval.eval(new[] { "1 0 0", "", "", "", }, 0)) != "1") throw new Exception(res);
            if ((res = eval.eval(new[] { "1 0 2", "", "", "", }, 0)) != "0") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 0 0", "", "", "", }, 0)) != "1") throw new Exception(res);
            if ((res = eval.eval(new[] { "4 0 2", "", "", "", }, 0)) != "0") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 2 0", "", "", "", }, 0)) != "0.75") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 1 1", "", "", "", }, 0)) != "0.25") throw new Exception(res);
            if ((res = eval.eval(new[] { "4 1 1", "", "", "", }, 0)) != "0.5") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1; //行数

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, l);
                l += 1;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + "." + DateTime.Now.Second + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int N; //
            public int X; //
            public int Y; //

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
                var res = 0.0;
                X = Math.Abs(X);
                if (1 <= N && (X + Y) <= 0) return "1";
                if (6 <= N && (X + Y) <= 2) return "1";
                if (15 <= N && (X + Y) <= 4) return "1";

                switch (N)
                {
                    case 2:
                        if (X == 2 && Y == 0) res = 1.0 / 2;
                        break;
                    case 3:
                        if (X == 2 && Y == 0) res = 3.0 / 4;
                        else if (X == 1 && Y == 1) res = 1.0 / 4;
                        break;
                    case 4:
                        if (X == 2 && Y == 0) res = 1;
                        else if (X == 1 && Y == 1) res = 1.0 / 2;
                        break;
                    case 5:
                        if (X == 2 && Y == 0) res = 1;
                        else if (X == 1 && Y == 1) res = 1;
                        break;
                    case 7:
                        if (X == 4 && Y == 0) res = 1.0 / 2;
                        break;
                    case 8:
                        if (X == 4 && Y == 0) res = 3.0 / 4;
                        else if (X == 3 && Y == 1) res = 1.0 / 4;
                        break;
                    case 9:
                        if (X == 4 && Y == 0) res = 7.0 / 8;
                        else if (X == 3 && Y == 1) res = 4.0 / 8;
                        else if (X == 2 && Y == 2) res = 1.0 / 8;
                        break;
                    case 10:
                        if (X == 4 && Y == 0) res = 15.0 / 16;
                        else if (X == 3 && Y == 1) res = 11.0 / 16;
                        else if (X == 2 && Y == 2) res = 5.0 / 16;
                        else if (X == 1 && Y == 3) res = 1.0 / 16;
                        break;
                    case 11:
                        if (X == 4 && Y == 0) res = 1;
                        else if (X == 3 && Y == 1) res = 7.0 / 8;
                        else if (X == 2 && Y == 2) res = 4.0 / 8;
                        else if (X == 1 && Y == 3) res = 1.0 / 8;
                        break;
                    case 12:
                        if (X == 4 && Y == 0) res = 1;
                        else if (X == 3 && Y == 1) res = 1;
                        else if (X == 2 && Y == 2) res = 3.0 / 4;
                        else if (X == 1 && Y == 3) res = 1.0 / 4;
                        break;
                    case 13:
                        if (X == 4 && Y == 0) res = 1;
                        else if (X == 3 && Y == 1) res = 1;
                        else if (X == 2 && Y == 2) res = 1;
                        else if (X == 1 && Y == 3) res = 1.0 / 2;
                        break;
                    case 14:
                        if (X == 4 && Y == 0) res = 1;
                        else if (X == 3 && Y == 1) res = 1;
                        else if (X == 2 && Y == 2) res = 1;
                        else if (X == 1 && Y == 3) res = 1;
                        break;
                    case 16:
                        if (X == 6 && Y == 0) res = 1.0 / 2;
                        else if (X == 5 && Y == 1) res = 0;
                        else if (X == 4 && Y == 2) res = 0;
                        else if (X == 3 && Y == 3) res = 0;
                        else if (X == 2 && Y == 4) res = 0;
                        break;
                    case 17:
                        if (X == 6 && Y == 0) res = 3.0 / 4;
                        else if (X == 5 && Y == 1) res = 1.0 / 4;
                        else if (X == 4 && Y == 2) res = 0;
                        else if (X == 3 && Y == 3) res = 0;
                        else if (X == 2 && Y == 4) res = 0;
                        break;
                    case 18:
                        if (X == 6 && Y == 0) res = 7.0 / 8;
                        else if (X == 5 && Y == 1) res = 4.0 / 8;
                        else if (X == 4 && Y == 2) res = 1.0 / 8;
                        else if (X == 3 && Y == 3) res = 0;
                        else if (X == 2 && Y == 4) res = 0;
                        break;
                    case 19:
                        if (X == 6 && Y == 0) res = 15.0 / 16;
                        else if (X == 5 && Y == 1) res = 11.0 / 16;
                        else if (X == 4 && Y == 2) res = 5.0 / 16;
                        else if (X == 3 && Y == 3) res = 1.0 / 16;
                        else if (X == 2 && Y == 4) res = 0;
                        break;
                    case 20:
                        if (X == 6 && Y == 0) res = 31.0 / 32;
                        else if (X == 5 && Y == 1) res = 26.0 / 32;
                        else if (X == 4 && Y == 2) res = 16.0 / 32;
                        else if (X == 3 && Y == 3) res = 6.0 / 32;
                        else if (X == 2 && Y == 4) res = 1.0 / 32;
                        break;
                    default:
                        break;
                }

                return res.ToString();
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                N = int.Parse(lines[l].Split(' ')[0]);
                X = int.Parse(lines[l].Split(' ')[1]);
                Y = int.Parse(lines[l].Split(' ')[2]);
            }
        }
    }
}
