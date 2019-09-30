using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace CodeJam2013R1C
{
    using System.IO;
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
            string[] strSplit = s.Split(delim, StringSplitOptions.RemoveEmptyEntries);
            return SAToIA(strSplit);
        }

        public static int[] StringToIA(string s, char c)
        {
            return StringToIA(
                s,
                new char[]
                {
                    c
                });
        }

        public static int[] StringToIA(string s)
        {
            return StringToIA(
                s,
                new char[]
                {
                    ' '
                });
        }

        public static long[] StringToLongA(string s, char[] delim)
        {
            string[] strSplit = s.Split(delim, StringSplitOptions.RemoveEmptyEntries);
            return SAToLongA(strSplit);
        }

        public static long[] StringToLongA(string s, char c)
        {
            return StringToLongA(
                s,
                new char[]
                {
                    c
                });
        }

        public static long[] StringToLongA(string s)
        {
            return StringToLongA(
                s,
                new char[]
                {
                    ' '
                });
        }

        public static string[] StringToSA(string s, char[] delim)
        {
            string[] strSplit = s.Split(delim, StringSplitOptions.RemoveEmptyEntries);
            return strSplit;
        }

        public static string[] StringToSA(string s, char c)
        {
            return StringToSA(
                s,
                new char[]
                {
                    c
                });
        }

        public static string[] StringToSA(string s)
        {
            return StringToSA(
                s,
                new char[]
                {
                    ' '
                });
        }

        #endregion Helper

        public const int INF = 1000 * 1000 * 1000;

        public const int OFFSET = 1000;

        protected System.IO.StreamWriter writer;

        public void Solve(string input, string output)
        {
            string filename = input;
            writer = new System.IO.StreamWriter(output);
            string[] strAll = System.IO.File.ReadAllText(filename).Split(
                new char[]
                {
                    '\r', '\n'
                },
                StringSplitOptions.RemoveEmptyEntries);

            ParseAndSolve(strAll);
            writer.Flush();
        }

        public virtual void ParseAndSolve(string[] strAll)
        {
            throw new NotImplementedException();
        }
    }

    public class A : SolverBase
    {
        public override void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            isV = new bool[256];
            isV['a'] = true;
            isV['e'] = true;
            isV['i'] = true;
            isV['o'] = true;
            isV['u'] = true;

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        bool[] isV;
        private string Solve(string input)
        {
            var split = StringToSA(input, ' ');
            var text = split[0];
            var len = int.Parse(split[1]);

            int n = text.Length;
            long left = (long)(n - len + 1) * (n - len + 2) / 2;
            int sofar = 0;
            int lastGoodEnd = 0;
            bool inSeq = false;
            for (int i = 0; i < text.Length; ++i)
            {
                if (isV[text[i]])
                {
                    if (inSeq)
                    {
                        lastGoodEnd = i - len + 1;
                    }

                    sofar = 0;
                    inSeq = false;
                }
                else
                {
                    ++sofar;
                    if (sofar == len)
                    {
                        inSeq = true;
                        int badSeqLen = i - lastGoodEnd;
                        if (badSeqLen >= len)
                        {
                            left -= (long)(badSeqLen - len + 1) * (badSeqLen - len + 2) / 2;
                        }
                    }
                }
            }

            if (!inSeq)
            {
                int badSeqLen = text.Length - lastGoodEnd;
                if (badSeqLen >= len)
                {
                    left -= (long)(badSeqLen - len + 1) * (badSeqLen - len + 2) / 2;
                }
            }

            return left + string.Empty;
        }

        ////private string Solve(string s)
        ////{
        ////    var split = StringToSA(s, ' ');
        ////    var text = split[0];
        ////    var len = int.Parse(split[1]);

        ////    int n = text.Length;
        ////    int count = 0;
        ////    for (int i = 0; i < n; ++i)
        ////    {
        ////        for (int j = i + 1; j <= n; ++j)
        ////        {
        ////            if (Good(text.Substring(i, j - i), len))
        ////            {
        ////                ++count;
        ////            }
        ////        }
        ////    }

        ////    return count + string.Empty;
        ////}

        ////private bool Good(string s, int len)
        ////{
        ////    int sofar = 0;
        ////    for (int i = 0; i < s.Length; ++i)
        ////    {
        ////        if (isV[s[i]])
        ////        {
        ////            sofar = 0;
        ////        }
        ////        else
        ////        {
        ////            ++sofar;
        ////            if (sofar >= len)
        ////            {
        ////                return true;
        ////            }
        ////        }
        ////    }

        ////    return false;
        ////}
    }

    public class B : SolverBase
    {
        public override void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                int[] nm = StringToIA(strAll[idx++]);
                int X = nm[0];
                int Y = nm[1];
                string sres = "Case #" + i + ": ";
                sres += Solve(X, Y);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(int X, int Y)
        {
            var build = new StringBuilder();
            for (int i = 0; i < Math.Abs(X); ++i)
            {
                build.Append(X > 0 ? "WE" : "EW");
            }

            for (int i = 0; i < Math.Abs(Y); ++i)
            {
                build.Append(Y > 0 ? "SN" : "NS");
            }

            return build.ToString();
        }
    }

    public class C : SolverBase
    {
        public override void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            GenerateDictionary();
            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve0(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private void GenerateDictionary()
        {
            dict = new HashSet<string>();
            var file = @"D:\MyProj\CodeJam\garbled_email_dictionary.txt";
            var lines = File.ReadAllLines(file);
            int maxL = 0;
            foreach (var line in lines)
            {
                AddLine(line, dict);
                maxL = Math.Max(maxL, line.Length);
            }

            Console.WriteLine("maxL = " + maxL);
            Console.WriteLine("words = " + dict.Count);
        }

        private void AddLine(string line, HashSet<string> dict)
        {
            if (line.IndexOf(' ') >= 0)
            {
                throw new Exception();
            }

            dict.Add(line);
            var cc = line.ToCharArray();
            for (int i = 0; i < line.Length; ++i)
            {
                cc[i] = '*';
                dict.Add(new string(cc));
                cc[i] = line[i];
            }

            for (int i = 0; i < line.Length; ++i)
            {
                for (int j = i + 5; j < line.Length; ++j)
                {
                    cc[i] = '*';
                    cc[j] = '*';
                    dict.Add(new string(cc));
                    cc[i] = line[i];
                    cc[j] = line[j];
                }
            }
        }

        private HashSet<string> dict = new HashSet<string>();

        private int best = int.MaxValue;

        private int count = 0;

        private int totalLen = int.MaxValue;
        private string Solve0(string s)
        {
            best = int.MaxValue;
            count = 0;
            totalLen = s.Length;

            var cc = s.ToCharArray();
            if (Good(cc))
            {
                return "0";
            }

            for (int i = 0; i < s.Length; ++i)
            {
                cc[i] = '*';
                Calc(1, i, s, cc);
                cc[i] = s[i];
            }

            Console.WriteLine(count);
            return best + string.Empty;
        }

        private int[,,,] dp;

        //////private string Solve(string s)
        //////{
        //////    totalLen = s.Length;
        //////    dp = new int[totalLen,totalLen + 1,totalLen + 1,totalLen + 1];
        //////    for (int i = 0; i < totalLen; ++i)
        //////    {
        //////        for (int j = 0; j <= totalLen; ++j)
        //////        {
        //////            for (int k = 0; k <= totalLen + 1; ++k)
        //////            {
        //////                for (int l = 0; l <= totalLen + 1; ++l)
        //////                {
        //////                    dp[i, j, k, l] = INF;
        //////                }
        //////            }
        //////        }
        //////    }

        //////    for (int i = 0; i < totalLen; ++i)
        //////    {
        //////        dp[i, 0, 0, 0] = 0;
        //////    }

        //////    for (int len = 1; len <= totalLen; ++len)
        //////    {
        //////        for (int i = 0; i < totalLen; ++i)
        //////        {
        //////            for (int firstError = 0; firstError <= len; ++firstError)
        //////            {
        //////                for (int lastError = firstError; lastError <= len; ++lastError)
        //////                {
        //////                    if (firstError == 0 && lastError > 0)
        //////                    {
        //////                        continue;
        //////                    }

        //////                    if (lastError != firstError && lastError < firstError + 5)
        //////                    {
        //////                        continue;
        //////                    }

        //////                    int lb = GetBest(s, i, len, firstError, lastError);
        //////                    for (int j = 1; j < len && i + j < totalLen; ++j)
        //////                    {
        //////                        if (lastError == 0)
        //////                        {
        //////                            lb = Math.Min(lb, dp[i, j, 0] + dp[i + j, len - j, 0]);
        //////                        }
        //////                        else if (lastError <= j)
        //////                        {

        //////                        }
        //////                    }

        //////                    dp[i, len, lastError] = lb;
        //////                }
        //////            }
        //////        }
        //////    }

        //////    int gb = INF;
        //////    for (int i = 0; i <= totalLen; ++i)
        //////    {
        //////        gb = Math.Min(gb, dp[0, totalLen, i]);
        //////    }

        //////    return gb + string.Empty;
        //////}

        private int GetBest(string s, int start, int len, int firstError, int lastError)
        {
            if (len > 10 || start + len > s.Length)
            {
                return INF;
            }

            if (firstError == 0)
            {
                if (lastError > 0)
                {
                    return INF;
                }
            }

            if (firstError > 0)
            {
                if (lastError != firstError && lastError < firstError + 5)
                {
                    return INF;
                }
            }

            var line = s.Substring(start, len);
            if (firstError == 0 && lastError == 0 && dict.Contains(line))
            {
                return 0;
            }

            var cc = line.ToCharArray();
            if (firstError > 0 && lastError == firstError)
            {
                cc[firstError - 1] = '*';
                if (dict.Contains(new string(cc)))
                {
                    return 1;
                }
            }

            if (firstError > 0 && lastError != firstError)
            {
                cc[firstError - 1] = '*';
                cc[lastError - 1] = '*';
                if (dict.Contains(new string(cc)))
                {
                    return 2;
                }
            }

            return INF;
        }

        private void Calc(int errors, int lastErrorPos, string s, char[] cc)
        {
            ++count;
            if (errors >= best)
            {
                return;
            }

            if (Good(cc))
            {
                best = Math.Min(best, errors);
                return;
            }

            for (int i = lastErrorPos + 5; i < s.Length; ++i)
            {
                cc[i] = '*';
                Calc(errors + 1, i, s, cc);
                cc[i] = s[i];
            }
        }

        private bool Good(char[] cc)
        {
            return GoodCalc(cc, 0);
        }

        private bool GoodCalc(char[] cc, int sofar)
        {
            if (sofar >= totalLen)
            {
                return true;
            }

            if (totalLen - sofar <= 10 && dict.Contains(new string(cc, sofar, totalLen - sofar)))
            {
                return true;
            }

            bool good = false;
            for (int i = 1; i <= 10 && i <= totalLen - sofar; ++i)
            {
                if (dict.Contains(new string(cc, sofar, i)))
                {
                    if (GoodCalc(cc, sofar + i))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    }

    public class D : SolverBase
    {
        public override void ParseAndSolve(string[] strAll)
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
        private static void Main(string[] args)
        {
            string dir = "D:\\MyProj\\CodeJam\\";

            //new A( ).Solve( dir + "ASample.txt", dir + "out.txt" );
            //new A( ).Solve( dir + "A-small-attempt0.in", dir + "out.txt" );
            new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            //new C().Solve(dir + "C-small-attempt1.in", dir + "out.txt");
            //new C().Solve(dir + "C-large.in", dir + "out.txt");
            //new C().Solve(dir + "C-small-practice.in", dir + "out.txt");

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            //new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
