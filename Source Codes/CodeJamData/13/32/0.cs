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
                sres += SolveLarge(X, Y);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        int[] dx = new[] { 1, 0, -1, 0 };
        int[] dy = new[] { 0, 1, 0, -1 };
        string dirs = "WSEN";
        private string SolveLarge(int X, int Y)
        {
            int need = Math.Abs(X) + Math.Abs(Y);
            int n = 1;
            int sum = 1;
            while (sum < need || (sum - need) % 2 != 0)
            {
                ++n;
                sum += n;
            }

            string res = string.Empty;
            int cx = X;
            int cy = Y;
            for (int i = n; i > 0; --i)
            {
                int best = int.MaxValue;
                int bestDir = -1;
                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = cx + i * dx[dir];
                    int ny = cy + i * dy[dir];
                    int curr = Math.Abs(nx) + Math.Abs(ny);
                    if (curr < best)
                    {
                        best = curr;
                        bestDir = dir;
                    }
                }

                if (bestDir >= 0)
                {
                    cx += i * dx[bestDir];
                    cy += i * dy[bestDir];
                    res = dirs[bestDir] + res;
                }
                else
                {
                    throw new Exception("No valid move!");
                }
            }

            if (cx != 0 || cy != 0)
            {
                throw new Exception("Not reaching target!");
            }

            return res;
        }

        private string SolveSmall(int X, int Y)
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

            for (int i = 1; i <= T; ++i)
            {
                int n = int.Parse(strAll[idx++]);
                var ss = new string[n];
                for (int j = 0; j < n; ++j)
                {
                    ss[j] = strAll[idx++];
                }

                string sres = "Case #" + i + ": ";
                sres += Solve(ss);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string[] ts)
        {
            int n = ts.Length;
            var tribes = ts.Select(s => new Tribe(s)).ToArray();
            var allAttacks = new List<Attack>();
            foreach (var t in tribes)
            {
                allAttacks.AddRange(t.GetAttacks());
            }

            var days = allAttacks.Select(a => a.day).Distinct().ToArray();
            Array.Sort(days);
            int damage = 0;
            var wall = new Dictionary<int, int>();
            foreach (var day in days)
            {
                var repair = new Dictionary<int, int>();
                foreach (var a in allAttacks.Where(a => a.day == day))
                {
                    bool pass = false;
                    for (int i = a.west; i < a.east; ++i)
                    {
                        if (!wall.ContainsKey(i) || wall[i] < a.strength)
                        {
                            pass = true;
                            if (!repair.ContainsKey(i))
                            {
                                repair[i] = a.strength;
                            }
                            else
                            {
                                repair[i] = Math.Max(repair[i], a.strength);
                            }
                        }
                    }

                    if (pass)
                    {
                        ++damage;
                    }
                }

                foreach (var kvp in repair)
                {
                    wall[kvp.Key] = kvp.Value;
                }
            }

            return damage + string.Empty;
        }

        private class Attack
        {
            public int day;
            public int west;
            public int east;
            public int strength;
        }

        private class Tribe
        {
            int firstW;
            int firstE;
            int firstS;
            int firstDay;
            int distDelta;
            int strDelta;
            int dayDelta;
            int times;

            //The ith line contains eight integers di, ni, wi, ei, si, delta_di, delta_pi and delta_si separated by spaces, describing a single nomadic tribe:

            //di – the day of the tribe's first attack (where 1st January, 250BC, is considered day 0)
            //ni – the number of attacks from this tribe
            //wi, ei – the westmost and eastmost points respectively of the Wall attacked on the first attack
            //si – the strength of the first attack
            //delta_di – the number of days between subsequent attacks by this tribe
            //delta_pi – the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
            //delta_si – the change in strength between subsequent attacks

            public Tribe(string s)
            {
                var a = StringToIA(s);
                firstDay = a[0];
                times = a[1];
                firstW = a[2];
                firstE = a[3];
                firstS = a[4];
                dayDelta = a[5];
                distDelta = a[6];
                strDelta = a[7];
            }

            public List<Attack> GetAttacks()
            {
                var res = new List<Attack>();
                for(int i = 0; i < times; ++i)
                {
                    var a = new Attack
                    {
                        day = firstDay + i * dayDelta,
                        west = firstW + i * distDelta,
                        east = firstE + i * distDelta,
                        strength = firstS + i * strDelta
                    };
                    res.Add(a);
                }

                return res;
            }
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
            //new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            new B( ).Solve( dir + "B-large.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            //new C().Solve(dir + "C-small-attempt0.in", dir + "out.txt");
            //new C().Solve(dir + "C-large.in", dir + "out.txt");
            //new C().Solve(dir + "C-small-practice.in", dir + "out.txt");

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            //new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
