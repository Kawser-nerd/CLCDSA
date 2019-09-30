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

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                var rc = StringToIA(strAll[idx++]);
                var R = rc[0];
                var C = rc[1];
                sres += Solve(R, C, strAll.Skip(idx).Take(R).ToArray());
                idx += R;
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(int R, int C, string[] rows)
        {
            char[,] board = new char[R, C];
            for (int ix = 0; ix < R; ++ix)
            {
                for (int iy = 0; iy < C; ++iy)
                {
                    board[ix, iy] = rows[ix][iy];
                }
            }

            int change = 0;
            for (int ix = 0; ix < R; ++ix)
            {
                for (int iy = 0; iy < C; ++iy)
                {
                    if (!Can(board, ix, iy, R, C))
                    {
                        return "IMPOSSIBLE";
                    }

                    if (!Good(board, ix, iy, R, C))
                    {
                        ++change;
                    }
                }
            }

            return change + "";
        }

        string toIndex = "^>v<";
        int[] dx = new int[] { -1, 0, 1, 0 };
        int[] dy = new int[] { 0, 1, 0, -1 };

        private bool Good(char[,] board, int ix, int iy, int R, int C)
        {
            if (board[ix, iy] == '.')
            {
                return true;
            }

            int idx = toIndex.IndexOf(board[ix, iy]);
            int cx = ix;
            int cy = iy;
            while (true)
            {
                cx += dx[idx];
                cy += dy[idx];
                if (cx < 0 || cx >= R || cy < 0 || cy >= C)
                {
                    return false;
                }

                if (board[cx, cy] != '.')
                {
                    return true;
                }
            }

            return true;
        }

        private bool Can(char[,] board, int ix, int iy, int R, int C)
        {
            if (board[ix, iy] == '.')
            {
                return true;
            }

            int count = 0;
            for (int i = 0; i < R; ++i)
            {
                if (board[i, iy] != '.')
                {
                    ++count;
                }
            }

            for (int i = 0; i < C; ++i)
            {
                if (board[ix, i] != '.')
                {
                    ++count;
                }
            }

            return count > 2;
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
                var split = StringToSA(strAll[idx++]);
                var N = int.Parse(split[0]);
                var V = double.Parse(split[1]);
                var X = double.Parse(split[2]);
                sres += Solve(strAll.Skip(idx).Take(N).ToArray(), V, X);
                idx += N;
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        // easy
        private string Solve(string[] water, double V, double X)
        {
            var uts = new UT[water.Length];
            for (int i = 0; i < water.Length; ++i)
            {
                var split = StringToSA(water[i]);
                uts[i] = new UT
                {
                    vol = double.Parse(split[0]),
                    temp = double.Parse(split[1])
                };
            }

            if (uts.Length == 1)
            {
                if (Math.Abs(uts[0].temp - X) > EPS)
                {
                    return imposs;
                }

                return V / uts[0].vol + "";
            }

            if (uts.Length == 2)
            {
                bool aSame = false;
                bool bSame = false;
                if (Math.Abs(uts[0].temp - X) < EPS)
                {
                    aSame = true;
                }

                if (Math.Abs(uts[1].temp - X) < EPS)
                {
                    bSame = true;
                }

                if (aSame & bSame)
                {
                    return V / (uts[0].vol + uts[1].vol) + "";
                }

                if (aSame)
                {
                    return V / (uts[0].vol) + "";
                }

                if (bSame)
                {
                    return V / (uts[1].vol) + "";
                }

                var v0 = V * (X - uts[1].temp) / (uts[0].temp - uts[1].temp);
                var v1 = V * (X - uts[0].temp) / (uts[1].temp - uts[0].temp);
                if (v0 < 0 || v1 < 0)
                {
                    return imposs;
                }

                return Math.Max(v0 / uts[0].vol, v1 / uts[1].vol) + "";
            }

            throw new Exception();
        }

        double EPS = 1e-12;
        string imposs = "IMPOSSIBLE";
        private class UT
        {
            public double vol;
            public double temp;
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
                int N = int.Parse(strAll[idx++]);
                sres += Solve(strAll.Skip(idx).Take(N).ToArray());
                idx += N;
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string[] sts)
        {
            HashSet<string>[] words = new HashSet<string>[sts.Length];
            for (int i = 0; i < sts.Length; ++i)
            {
                words[i] = new HashSet<string>(StringToSA(sts[i]));
            }

            HashSet<int>[] toInt = new HashSet<int>[sts.Length];
            Dictionary<string, int> lookup = new Dictionary<string,int>();
            for (int i = 2; i < sts.Length; ++i)
            {
                toInt[i] = GetIndex(lookup, words[i]); 
            }

            for (int i = 0; i < 2; ++i)
            {
                toInt[i] = GetIndex(lookup, words[i], false);
            }

            int largest = lookup.Count();
            int best = INF;
            for (int mask = 0; mask < (1 << (sts.Length - 2)); ++mask)
            {
                int current = Calc(toInt, mask, largest);
                best = Math.Min(best, current);
            }

            int mustHave = GetAB(words[0], words[1], lookup);
            return mustHave + best + "";
        }

        private int GetAB(HashSet<string> eng, HashSet<string> fre, Dictionary<string, int> lookup)
        {
            int count = 0;
            foreach (var a in eng)
            {
                if (!lookup.ContainsKey(a) && fre.Contains(a))
                {
                    ++count;
                }
            }

            return count;
        }

        private HashSet<int> GetIndex(Dictionary<string, int> lookup, HashSet<string> hashSet, bool addNew = true)
        {
            var ret = new HashSet<int>();
            foreach (var a in hashSet)
            {
                if (!lookup.ContainsKey(a))
                {
                    if (addNew)
                    {
                        lookup[a] = lookup.Count();
                        ret.Add(lookup[a]);
                    }
                }
                else
                {
                    ret.Add(lookup[a]);
                }
            }

            return ret;
        }

        //private int Calc(HashSet<int>[] words, int mask, int largest)
        //{
        //    int[] cnt = new int[largest];
        //    Add(eng, words[0]);
        //    Add(fre, words[1]);
        //    for (int i = 0; i < words.Length - 2; ++i)
        //    {
        //        if ((mask & (1 << i)) != 0)
        //        {
        //            Add(eng, words[i + 2]);
        //        }
        //        else
        //        {
        //            Add(fre, words[i + 2]);
        //        }
        //    }

        //    return eng.Intersect(fre).Count();
        //}

        private int Calc(HashSet<int>[] words, int mask, int largest)
        {
            int[] cnt = new int[largest];
            HashSet<int> eng = new HashSet<int>();
            HashSet<int> fre = new HashSet<int>();
            Add(eng, words[0]);
            Add(fre, words[1]);
            for (int i = 0; i < words.Length - 2; ++i)
            {
                if ((mask & (1 << i)) != 0)
                {
                    Add(eng, words[i + 2]);
                }
                else
                {
                    Add(fre, words[i + 2]);
                }
            }

            return eng.Intersect(fre).Count();
        }

        private void Add(HashSet<int> par, HashSet<int> child)
        {
            foreach (var a in child)
            {
                par.Add(a);
            }
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
            //new C().Wrapping(dir + "C-small-attempt0.in", dir + "out.txt");
            new C().Wrapping(dir + "C-small-attempt2.in", dir + "out.txt");
            //new C().Wrapping(dir + "C-large.in", dir + "out.txt");
            
            //new D().Wrapping(dir + "DSample.txt", dir + "out.txt");
            //new D().Wrapping(dir + "D-small-attempt0.in", dir + "out.txt");
            //new D().Wrapping(dir + "D-large.in", dir + "out.txt");
        }
    }
}
