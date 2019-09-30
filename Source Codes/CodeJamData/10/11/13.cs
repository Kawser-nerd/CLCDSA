using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication3
{
    class Program
    {

        [Flags]
        enum Fill { Neither = 0, Red = 1, Blue = 2, Both = 3 };

        static string[] _args;
        static void Main(string[] args)
        {

            _args = args;
            OpenFile();

            int testcases = ReadInt();

            for (int i = 0; i < testcases; i++)
            {
                Fill testResult = Fill.Neither;
                var tp = ReadInts();
                int n = tp[0];
                int k = tp[1];

                Fill[,] area = new Fill[n, n];

                for (int y = 0; y < n; y++)
                {
                    string s = ReadString();

                    for (int x = 0; x < n; x++)
                    {
                        area[x, y] = s[x] == '.' ? Fill.Neither : s[x] == 'R' ? Fill.Red : Fill.Blue;
                    }

                }

                for (int y = 0; y < n; y++)
                {
                    int xt = n - 1;
                    for (int x = n - 1; x >= 0; x--)
                    {
                        if (area[x, y] != Fill.Neither)
                            area[xt--, y] = area[x, y];

                    }

                    for (int x = xt; x >= 0; x--)
                        area[x, y] = Fill.Neither;

                }

                for (int y = 0; y < n; y++)
                {
                    Fill current = Fill.Both;
                    int c = 0;
                    for (int x = 0; x < n; x++)
                    {
                        if (current != area[x, y])
                        {
                            c = 1;
                            current = area[x, y];
                        }
                        else
                        {
                            if (++c == k)
                                testResult |= current;
                        }
                    }
                }

                for (int x = 0; x < n; x++)
                {
                    Fill current = Fill.Both;
                    int c = 0;
                    for (int y = 0; y < n; y++)
                    {

                        if (current != area[x, y])
                        {
                            c = 1;
                            current = area[x, y];
                        }
                        else
                        {
                            if (++c == k)
                                testResult |= current;
                        }
                    }
                }

                for (int x = 0; x < n - k + 1; x++)
                {
                    Fill current = Fill.Both;
                    int c = 0;
                    for (int j = 0; j < n - x; j++)
                    {
                        if (current != area[x + j, j])
                        {
                            c = 1;
                            current = area[x + j, j];
                        }
                        else
                        {
                            if (++c == k)
                                testResult |= current;
                        }
                    }
                }

                for (int y = 0; y < n - k + 1; y++)
                {
                    Fill current = Fill.Both;
                    int c = 0;
                    for (int j = 0; j < n - y; j++)
                    {
                        if (current != area[j, y + j])
                        {
                            c = 1;
                            current = area[j, y + j];
                        }
                        else
                        {
                            if (++c == k)
                                testResult |= current;
                        }
                    }
                }

                for (int x = k - 1; x < n; x++)
                {
                    Fill current = Fill.Both;
                    int c = 0;
                    for (int j = 0; j <= x; j++)
                    {
                        if (current != area[x - j, j])
                        {
                            c = 1;
                            current = area[x - j, j];
                        }
                        else
                        {
                            if (++c == k)
                                testResult |= current;
                        }
                    }
                }

                for (int x = 0; x < n - k + 1; x++)
                {
                    Fill current = Fill.Both;
                    int c = 0;
                    for (int j = 0; j < n - x; j++)
                    {
                        if (current != area[x + j, n - j - 1])
                        {
                            c = 1;
                            current = area[x + j, n - j - 1];
                        }
                        else
                        {
                            if (++c == k)
                                testResult |= current;
                        }
                    }
                }



                WriteCase(testResult.ToString());
            }


            WriteOutFile();
        }




        #region Common API for Codejam

        static string[] _readLines;
        static int _currentLine;
        private static void OpenFile()
        {
            _readLines = File.ReadAllLines(_args[0]);
        }

        private static string ReadString()
        {
            return _readLines[_currentLine++];
        }

        private static int[] ReadInts()
        {
            return ReadString().Split(' ').Select(i => int.Parse(i)).ToArray();
        }

        private static long[] ReadLongs()
        {
            return ReadString().Split(' ').Select(i => long.Parse(i)).ToArray();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadString());
        }

        private static string[] ReadStrings()
        {
            return ReadString().Split(' ').ToArray();
        }

        static StringBuilder _outLines = new StringBuilder();
        static int caseNumber;
        private static void WriteCase(string result)
        {
            WriteLine("Case #{0}: {1}", ++caseNumber, result);
        }

        private static void WriteLine(string str, params object[] ps)
        {
            _outLines.AppendFormat(str, ps);
            _outLines.AppendLine();
        }

        private static string StringOfInts(params int[][] ints)
        {
            StringBuilder result = new StringBuilder();
            var allInts =
                from i in ints
                from j in i
                select j.ToString() + " ";

            foreach (var i in allInts)
                result.Append(i);
            return result.ToString().TrimEnd();
        }

        private static void WriteOutFile()
        {
            File.WriteAllText(_args[1], _outLines.ToString());
        }

        #endregion
    }
}
