using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;

namespace CodeJam
{
    class Program
    {
        struct Model
        {
            public char C;
            public int Row;
            public int Col;
            public Model(char c, int row, int col)
            {
                C = c;
                Row = row;
                Col = col;
            }
        }

        static void Main(string[] args)
        {
            //string fileName = "in";
            string fileName = "D-small-attempt0.in";
            //string fileName = "D-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                var n = NextInt();
                var m = NextInt();
                var a = new char[n, n];
                var or = -1;
                var oc = -1;
                var resList = new List<Model>();
                for (int i = 0; i < m; i++)
                {
                    var sym = NextWord();
                    var ri = NextInt() - 1;
                    var ci = NextInt() - 1;
                    if (sym[0] == 'x')
                    {
                        a[ri, ci] = 'o';
                        resList.Add(new Model('o', ri, ci));
                    }
                    else
                    {
                        a[ri, ci] = sym[0];
                    }
                    
                    if (a[ri, ci] == 'o')
                    {
                        or = ri;
                        oc = ci;
                    }
                }

                if (or == -1)
                {
                    or = 0;
                    oc = 0;
                    a[or, oc] = 'o';
                    resList.Add(new Model('o', 0, 0));
                }
                
                for (int i = 0; i < n; i++)
                {
                    if (a[0, i] == default(char))
                    {
                        a[0, i] = '+';
                        resList.Add(new Model('+', 0, i));
                    }
                }

                for (int i = 1; i < n - 1; i++)
                {
                    a[n - 1, i] = '+';
                    resList.Add(new Model('+', n - 1, i));
                }

                for (int i = 1; i < n; i++)
                {
                    var cind = i == oc ? 0 : i;
                    a[i, cind] = 'x';
                    resList.Add(new Model('x', i, cind));
                }

                int res = n + (n > 1 ? (n - 2) : 0) + (n - 1) + 1;
                
                Console.WriteLine("Case #{0}: {1} {2}", testCase, res, resList.Count);
                foreach (var model in resList)
                {
                    Console.WriteLine("{0} {1} {2}", model.C, model.Row + 1, model.Col + 1);
                }
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
