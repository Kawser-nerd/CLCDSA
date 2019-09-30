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
        static void Main(string[] args)
        {
            //string fileName = "in";
            string fileName = "C-small-1-attempt1.in";
            //string fileName = "C-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                var n = NextInt();
                var k = NextInt();
                var u = decimal.Parse(Console.ReadLine(), NumberFormatInfo.InvariantInfo);
                var p = ReadWords().Select(x => decimal.Parse(x, NumberFormatInfo.InvariantInfo)).ToArray();
                
                if (n == k)
                {
                    if (n == 1)
                    {
                        p[0] += u;
                    }
                    else
                    {
                        while (u > 0)
                        {
                            Array.Sort(p);
                            var min = p[0];
                            var ind = 0;
                            while (ind < n && !(p[ind] > min))
                            {
                                ind++;
                            }

                            if (ind < n)
                            {
                                var nextval = p[ind];
                                var cnt = ind;
                                var incTotal = Math.Min(u, (nextval - min) * ind);
                                var inc = incTotal / cnt;
                                for (int i = 0; i < cnt; i++)
                                {
                                    p[i] += inc;
                                }
                                u -= incTotal;
                            }
                            else
                            {
                                var inc = u / n;
                                for (int i = 0; i < n; i++)
                                {
                                    p[i] += inc;
                                }
                                u = 0;
                            }
                        }
                    }

                    decimal res = p[0];
                    for (int i = 1; i < n; i++)
                    {
                        res *= p[i];
                    }

                    Console.WriteLine(string.Format(NumberFormatInfo.InvariantInfo, "Case #{0}: {1}", testCase, res));
                }
                else
                {
                    int res = -1;

                    Console.WriteLine("Case #{0}: {1}", testCase, res);
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
