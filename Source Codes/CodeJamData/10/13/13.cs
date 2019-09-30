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

            for (int test = 0; test < testcases; test++)
            {
                var ns = ReadInts();
                int c = 0;
                for (int i = ns[0]; i <= ns[1]; i++)
                    for (int j = ns[2]; j <= ns[3]; j++)
                    {
                        if (isWinner(i, j))
                            c++;

                    }
                WriteCase(c.ToString());

            }


            WriteOutFile();
        }

        private static bool isWinner(int i, int j)
        {
            if (j == i)
                return false;
            if (i > j)
            {
                int a = j;
                j = i;
                i = a;
            }

            int d = (j - 1) / i;
            j = j % i;
            if (j == 0)
                return true;

            if ((i - 1) / j > 1 && d == 1)
                return false;
            return isWinner(i-j, j) || (d > 1 && isWinner(i, j));
        }

        //private static int cSteps(int i, int j)
        //{
        //    int result = 0;

        //    if (i > j)
        //    {
        //        int a = j;
        //        j = i;
        //        i = a;
        //    }

        //    while (i != j)
        //    {
        //        result++;
        //        int m = j % i;
        //        j = i;
        //        i = m;
        //        if (m == 0)
        //        if (j / i > 1)
        //    }
        //}




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
