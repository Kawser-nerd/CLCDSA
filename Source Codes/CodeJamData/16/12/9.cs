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
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string s)
        {
            if (s.Length < 2)
            {
                return s;
            }

            for (int i = 0; i < s.Length - 1; ++i)
            {
                if (s[i] > s[s.Length - 1])
                {
                    return Solve(s.Substring(0, s.Length - 1)) + s[s.Length - 1];
                }
            }

            return s[s.Length - 1] + Solve(s.Substring(0, s.Length - 1));
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
                int n = int.Parse(strAll[idx++]);
                string[] lines = new string [2 * n - 1];
                Array.Copy(strAll, idx, lines, 0, 2 * n - 1);
                idx += 2 * n - 1;
                sres += Solve(lines);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string[] lines)
        {
            Dictionary<int, int> count = new Dictionary<int, int>();
            foreach (string s in lines)
            {
                var nums = StringToIA(s);
                foreach(var n in nums)
                {
                    if (count.ContainsKey(n))
                    {
                        ++count[n];
                    }
                    else
                    {
                        count[n] = 1;
                    }
                }
            }

            int [] res = StringToIA(lines[0]);
            int idx = 0;
            foreach (var kvp in count)
            {
                if (kvp.Value % 2 == 1)
                {
                    res[idx++] = kvp.Key;
                }
            }

            Array.Sort(res);
            return string.Join(" ", res);
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
                int n = int.Parse(strAll[idx++]);
                sres += Solve(n, strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(int n, string nbr)
        {
            int[] bff = StringToIA(nbr);
            for (int i = 0; i < n; ++i)
            {
                --bff[i];
            }

            best = 0;
            Calc(bff, new int[n], 0, (1 << n) - 1, n);

            return best + "";
        }

        // slow
        int count = 0;
        private void Calc(int[] bff, int[] kid, int index, int mask, int n)
        {
            for (int i = 0; i < n; ++i)
            {
                if ((mask & (1 << i)) == 0)
                {
                    continue;
                }

                kid[index] = i;
                ++count;
                if (best < index + 1 && Good(bff, kid, index + 1))
                {
                    best = index + 1;
                }

                Calc(bff, kid, index + 1, mask - (1 << i), n);
            }
        }

        private bool Good(int[] bff, int[] kid, int n)
        {
            for (int i = 0; i < n; ++i)
            {
                int leftPos = (i + 1) % n;
                int rightPos = (i - 1 + n) % n;
                if (bff[kid[i]] != kid[leftPos] && bff[kid[i]] != kid[rightPos])
                {
                    return false;
                }
            }

            return true;
        }

        private int best = 0;
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
            new B().Wrapping(dir + "B-large.in", dir + "out.txt");

            //new C().Wrapping(dir + "CSample.txt", dir + "out.txt");
            //new C().Wrapping(dir + "C-small-attempt0.in", dir + "out.txt");
            //new C().Wrapping(dir + "C-small-attempt2.in", dir + "out.txt");
            //new C().Wrapping(dir + "C-large.in", dir + "out.txt");

            //new D().Wrapping(dir + "DSample.txt", dir + "out.txt");
            //new D().Wrapping(dir + "D-small-attempt0.in", dir + "out.txt");
            //new D().Wrapping(dir + "D-small-attempt1.in", dir + "out.txt");
            //new D().Wrapping(dir + "D-large.in", dir + "out.txt");
        }
    }
}
