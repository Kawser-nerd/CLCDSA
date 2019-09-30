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
            //string fileName = "B-small-attempt2.in";
            string fileName = "B-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                int n = NextInt();
                ulong m = (ulong)NextLong();
                bool res = false;

                var rm = new char[n][];
                for (int i = 0; i < n; i++)
                {
                    rm[i] = new char[n];
                    for (int j = 0; j < n; j++)
                    {
                        rm[i][j] = '0';
                    }
                }

                if (n == 2)
                {
                    if (m == 1)
                    {
                        res = true;
                        rm[0][1] = '1';
                    }
                }
                if (n == 3)
                {
                    if (m <= 2)
                    {
                        res = true;
                        rm[0][1] = '1';
                        rm[1][2] = '1';
                        if (m > 1) rm[0][2] = '1';
                    }
                }
                if (n > 3)
                {
                    ulong cnt = 1;
                    int need = 2;
                    while (cnt < m)
                    {
                        need++;
                        cnt *= 2;
                    }
                    if (need <= n)
                    {
                        res = true;
                        var start = n - need;
                        for (int i = start; i < n - 1; i++)
                        {
                            for (int j = i + 1; j < n; j++)
                            {
                                rm[i][j] = '1';
                            }
                        }
                        if (start != 0)
                        {
                            rm[0][start] = '1';
                        }

                        if (cnt > m)
                        {
                            var k = 1;
                            rm[start][n - k] = '0';
                            while (m > 0)
                            {
                                k++;
                                if ((m & 1) == 0)
                                {
                                    rm[start][n - k] = '0';
                                }
                                m /= 2;
                            }
                        }
                    }
                    else
                    {
                        res = false;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", testCase, res ? "POSSIBLE" : "IMPOSSIBLE");
                if (res)
                {
                    for (int i = 0; i < n; i++)
                    {
                        Console.WriteLine(new string(rm[i]));
                    }
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
