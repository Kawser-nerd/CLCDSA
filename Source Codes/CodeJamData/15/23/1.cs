using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace CodeJam
{
    using System.Numerics;

    public class SolverBase
    {
        #region Helper
        public static int[] SAToIA(string[] strSplit)
        {
            int[] nums = new int[strSplit.Length];
            for (int iTemp = 0; iTemp < strSplit.Length; ++iTemp)
            {
                nums[iTemp] = int.Parse(strSplit[iTemp]);
            }

            return nums;
        }

        public static long[] SAToLongA(string[] strSplit)
        {
            long[] nums = new long[strSplit.Length];
            for (int iTemp = 0; iTemp < strSplit.Length; ++iTemp)
            {
                nums[iTemp] = long.Parse(strSplit[iTemp]);
            }

            return nums;
        }

        public static int[] StringToIA(string s, char[] delim)
        {
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return SAToIA(strSplit);
        }

        public static int[] StringToIA(string s, char c)
        {
            return StringToIA(s, new char[] { c });
        }

        public static int[] StringToIA(string s)
        {
            return StringToIA(s, new char[] { ' ' });
        }

        public static long[] StringToLongA(string s, char[] delim)
        {
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return SAToLongA(strSplit);
        }

        public static long[] StringToLongA(string s, char c)
        {
            return StringToLongA(s, new char[] { c });
        }

        public static long[] StringToLongA(string s)
        {
            return StringToLongA(s, new char[] { ' ' });
        }

        public static string[] StringToSA(string s, char[] delim)
        {
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return strSplit;
        }

        public static string[] StringToSA(string s, char c)
        {
            return StringToSA(s, new char[] { c });
        }

        public static string[] StringToSA(string s)
        {
            return StringToSA(s, new char[] { ' ' });
        }
        #endregion Helper

        public const int INF = 1000 * 1000 * 1000;
        public const int OFFSET = 1000;

        protected System.IO.StreamWriter writer;

        public void Wrapping(string input, string output)
        {
            string filename = input;
            writer = new System.IO.StreamWriter(output);
            string[] strAll = System.IO.File.ReadAllText(filename).Split(
                new char[] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries);

            ParseAndSolve(strAll);
            writer.Flush();
        }

        virtual public void ParseAndSolve(string[] strAll)
        {
            throw new NotImplementedException();
        }
    }

    public class Z : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string p)
        {
            throw new NotImplementedException();
        }
    }

    public class A : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            Pre();

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";

                var s = StringToIA(strAll[idx++], ' ');
                sres += Solve(s[0]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        Dictionary<int, int> lookup = new Dictionary<int, int>();
        const int UP = 1001 * 1000 * 10;
        bool[] seen = new bool[1001 * 1000 * 10];
        void Pre()
        {
            lookup[0] = 0;
            lookup[1] = 1;
            seen[0] = true;
            seen[1] = true;

            List<int> curr = new List<int>();
            curr.Add(1);
            int step = 1;
            List<int> next = new List<int>();

            while (true)
            {
                ++step;
                foreach (var a in curr)
                {
                    int nn = a + 1;
                    if (nn < UP && !seen[nn])
                    {
                        seen[nn] = true;
                        next.Add(nn);
                        lookup[nn] = step;
                    }

                    nn = Rev(a);
                    if (nn < UP && !seen[nn])
                    {
                        seen[nn] = true;
                        next.Add(nn);
                        lookup[nn] = step;
                    }
                }

                if (lookup.Count >= UP)
                {
                    break;
                }

                curr = next;
                next = new List<int>();
            }

            Console.WriteLine(step);
        }

        private static int Rev(int a)
        {
            int rr = 0;
            int tp = a;
            while (tp > 0)
            {
                rr *= 10;
                int dig = tp % 10;
                rr += dig;
                tp /= 10;
            }

            return rr;
        }

        private string Solve(int a)
        {
            return lookup[a] + "";
        }
    }

    public class B : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";

                var s = StringToIA(strAll[idx++], ' ');
                sres += Solve(s);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(int[] s)
        {
            int R = s[0];
            int C = s[1];
            int N = s[2];

            return Slow(R, C, N);
        }

        private string Slow(int R, int C, int N)
        {
            int total = R * C;
            int best = INF;
            for (int i = 0; i < (1 << total); ++i)
            {
                if (Ones(i) == N)
                {
                    int[,] board = new int[R + 1, C + 1];
                    for (int j = 0; j < total; ++j)
                    {
                        if (((1 << j) & i) != 0)
                        {
                            int x = j % R;
                            int y = j / R;
                            board[x, y] = 1;
                        }
                    }

                    int curr = 0;
                    for (int ix = 0; ix < R; ++ix)
                    {
                        for (int iy = 0; iy < C; ++iy)
                        {
                            if (board[ix, iy] == 0)
                            {
                                continue;
                            }

                            if (board[ix + 1, iy] == 1)
                            {
                                ++curr;
                            }

                            if (board[ix, iy + 1] == 1)
                            {
                                ++curr;
                            }
                        }
                    }

                    if (curr < best)
                    {
                        best = curr;
                    }
                }
            }

            return best + "";
        }

        private int Ones(int a)
        {
            return a == 0 ? 0 : (1 + Ones(a & (a - 1)));
        }
    }

    public class C : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                int group = int.Parse(strAll[idx++]);
                sres += Solve2(strAll.Skip(idx).Take(group).ToArray());
                idx += group;
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        // <= 2
        private string Solve1(string[] groups)
        {
            List<PPL> ppl = new List<PPL>();
            foreach (var g in groups)
            {
                var sp = StringToIA(g);
                var degree = sp[0];
                var num = sp[1];
                var min = sp[2];
                for (int i = 0; i < num; ++i)
                {
                    ppl.Add(new PPL
                    {
                        degree = degree,
                        minutes = min + i
                    });
                }
            }

            if (ppl.Count > 2)
            {
                return "";
            }

            var pa = ppl[0];
            var pb = ppl[1];
            if ((360 - pa.degree) * pa.minutes < (360 - pb.degree) * pb.minutes)
            {
                return Calc1(pb, pa);
            }

            return Calc1(pa, pb);
        }

        // pa is slower
        private string Calc1(PPL pa, PPL pb)
        {
            if ((360 - pa.degree) * pa.minutes >= (720 - pb.degree) * pb.minutes)
            {
                return 1 + "";
            }

            return 0 + "";
        }

        // <= 2
        private string Solve2(string[] groups)
        {
            List<PPL> ppl = new List<PPL>();
            foreach (var g in groups)
            {
                var sp = StringToIA(g);
                var degree = sp[0];
                var num = sp[1];
                var min = sp[2];
                for (int i = 0; i < num; ++i)
                {
                    ppl.Add(new PPL
                    {
                        degree = degree,
                        minutes = min + i
                    });
                }
            }

            if (ppl.Count > 10)
            {
                return "";
            }

            int best = INF;
            foreach (var p in ppl)
            {
                best = Math.Min(best, Calc1(p, ppl));
            }

            return best + "";
        }

        private int Calc1(PPL a, List<PPL> ppl)
        {
            long time = (360 - a.degree) * a.minutes;
            int count = 0;
            foreach (var p in ppl)
            {
                int loop = 1;
                while ((360 * loop - p.degree) * p.minutes <= time)
                {
                    ++loop;

                    if (loop > ppl.Count + 10)
                    {
                        break;
                    }
                }

                if (loop == 1)
                {
                    ++count;
                }
                else if (loop > 2)
                {
                    count += loop - 2;
                }
            }

            return count;
        }

        private class PPL
        {
            public int degree;
            public long minutes;
        }
    }

    public class D : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                //sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

    }

    public class RunMain
    {
        static void Main(string[] args)
        {
            string dir = "..\\..\\";

            //new A().Wrapping(dir + "ASample.txt", dir + "out.txt");
            //new A().Wrapping(dir + "A-small-attempt0.in", dir + "out.txt");
            //new A().Wrapping(dir + "A-large.in", dir + "out.txt");

            //new B().Wrapping(dir + "BSample.txt", dir + "out.txt");
            //new B().Wrapping(dir + "B-small-attempt0.in", dir + "out.txt");
            //new B().Wrapping(dir + "B-large.in", dir + "out.txt");

            //new C().Wrapping(dir + "CSample.txt", dir + "out.txt");
            new C().Wrapping(dir + "C-small-2-attempt0.in", dir + "out.txt");
            //new C().Wrapping(dir + "C-large.in", dir + "out.txt");

            //new D().Wrapping(dir + "DSample.txt", dir + "out.txt");
            //new D().Wrapping(dir + "D-small-attempt0.in", dir + "out.txt");
            //new D().Wrapping(dir + "D-large.in", dir + "out.txt");
        }
    }
}
