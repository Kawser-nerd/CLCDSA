using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;

namespace CodeJam
{
    class Attack
    {
        public int S { get; set; }
        public int L { get; set; }
        public int R { get; set; }
        public Attack(int s, int l, int r)
        {
            S = s;
            L = l;
            R = r;
        }
    }

    class Program
    {
        public static SortedList<int, List<Attack>> left;

        public static bool check (int l, int r, int s, int startP)
        {
            int k;
            for (int i = startP; i < left.Keys.Count; i++)
            {
                k = left.Keys[i];
                if (k > l)
                {
                    return true;
                }
                bool res = true;
                for (int j = 0; j < left[k].Count; j++)
                {
                    if (left[k][j].R > l)
                    {
                        if (left[k][j].R >= r && left[k][j].S >= s)
                        {
                            return false;
                        }
                        if (left[k][j].R < r && left[k][j].S >= s)
                        {
                            res = check(left[k][j].R, r, s, i + 1);
                            if (!res)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }

        static void Main(string[] args)
        {
            //string fileName = "in";
            string fileName = "C-small-attempt0.in";
            //string fileName = "C-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                SortedDictionary<int, List<Attack>> d = new SortedDictionary<int, List<Attack>>();
                var n = ReadInt();
                var c = 10000;
                for (int k = 0; k < n; k++)
                {
                    var di = NextInt();
                    var ni = NextInt();
                    var wi = NextInt();
                    var ei = NextInt();
                    var si = NextInt();
                    var ddi = NextInt();
                    var dpi = NextInt();
                    var dsi = NextInt();
                    for (int i = 0; i < ni; i++)
                    {
                        if (!d.ContainsKey(di))
                        {
                            d.Add(di, new List<Attack>());
                        }
                        d[di].Add(new Attack(si, wi, ei));
                        di += ddi;
                        wi += dpi;
                        ei += dpi;
                        si += dsi;
                    } 
                }
                int res = 0;
                left = new SortedList<int, List<Attack>>();
                
                foreach (var k in d.Keys)
                {
                    List<Attack> needRaise = new List<Attack>();
                    foreach (var a in d[k])
                    {
                        if (check(a.L, a.R, a.S, 0))
                        {
                            needRaise.Add(a);
                        }
                    }
                    foreach (var a in needRaise)
                    {
                        if (!left.ContainsKey(a.L))
                        {
                            left.Add(a.L, new List<Attack>());
                        }
                        left[a.L].Add(a);
                    }
                    res += needRaise.Count;
                }

                Console.WriteLine("Case #{0}: {1}", testCase, res);
            }

            //Console.WriteLine(string.Format(NumberFormatInfo.InvariantInfo, "{0:F4}", res));

            Console.In.Close();
            Console.Out.Close();
        }

        private static char[] _defaultSplitter = new char[] { ' ', '\t' };

        private static void SetCulture()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        }

        private static char[] ReadChars(int n)
        {
            char[] buffer = new char[n];
            Console.In.ReadBlock(buffer, 0, n);
            return buffer;
        }

        private static string[] ReadAll()
        {
            return Console.In.ReadToEnd().Split(new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords()
        {
            return ReadWords(_defaultSplitter);
        }

        private static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        private static int[] ReadInts(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToArray();
        }

        private static int[] ReadInts()
        {
            return ReadInts(_defaultSplitter);
        }

        private static long ReadLong()
        {
            return long.Parse(Console.ReadLine());
        }

        private static double ReadDouble()
        {
            return double.Parse(Console.ReadLine(), NumberFormatInfo.InvariantInfo);
        }

        private static int _pos = 0;
        private static string[] _inputLine = new string[0];

        private static void CheckInputLine()
        {
            if (_pos >= _inputLine.Length)
            {
                _inputLine = ReadWords();
                _pos = 0;
            }
        }

        private static string NextWord()
        {
            CheckInputLine();
            return _inputLine[_pos++];
        }

        private static int NextInt()
        {
            CheckInputLine();
            return int.Parse(_inputLine[_pos++]);
        }

        private static long NextLong()
        {
            CheckInputLine();
            return long.Parse(_inputLine[_pos++]);
        }
    }
}
