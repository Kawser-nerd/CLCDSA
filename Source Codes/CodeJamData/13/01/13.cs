using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using Helpers;

namespace _2013Q1
{
    class Program
    {
        static void Main()
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            System.Threading.Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-US");
            double lastMs = 0;
            Stopwatch sw = new Stopwatch();
            sw.Start();

            var inFileName = "A.in";
            var outFileName = inFileName.Replace(".in", "_out.out");
            using (var reader = new StreamReader(inFileName))
            using (var writer = new StreamWriter(outFileName))
            {
                int numTests = reader.ReadLineAsInt();

                for (int testcase = 1; testcase <= numTests; testcase++)
                {
                    char[,] map = new char[4,4];

                    for (int j = 0; j < 4; j++)
                    {
                        char[] line = reader.ReadLine().ToCharArray();

                        for (int k = 0; k < 4; k++)
                        {
                            map[j, k] = line[k];
                        }
                    }

                    reader.ReadLine();

                    var result = String.Format("Case #{0}: {1}", testcase, Solve(map));
                    writer.WriteLine(result);
                    Console.WriteLine(String.Format("{0} (ms: {1: 0.})", result, sw.Elapsed.TotalMilliseconds - lastMs));
                    lastMs = sw.Elapsed.TotalMilliseconds;
                }
            }
            Console.WriteLine(String.Format("Done. (ms: {0: 0.})", sw.Elapsed.TotalMilliseconds));
            Console.ReadKey();
        }

        private static string Solve(char[,] map)
        {
            int result;

            // check first row
            for (int i = 0; i < 4; i++ )
            {
                result = (CheckPosition(0, i, map));
                if (result == 0) return "X won";
                if (result == 1) return "O won";
            }

            // check first column
            for (int i = 0; i < 4; i++)
            {
                result = (CheckPosition(i, 0, map));
                if (result == 0) return "X won";
                if (result == 1) return "O won";
            }

            // check whether map contains '.'
            bool containsDot = false;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    containsDot = containsDot || map[i, j] == '.';

            return containsDot ? "Game has not completed" : "Draw";
        }

        // 0: x won
        // 1: O won
        // 2: Not won
        private static int CheckPosition(int x, int y, char[,] map)
        {
            // check row
            bool allX = true;
            bool allY = true;
            for (int i = 0; i < 4; i++)
            {
                allX = allX && (map[i, y] == 'X' || map[i, y] == 'T');
                allY = allY && (map[i, y] == 'O' || map[i, y] == 'T');
            }

            if (allX) return 0;
            if (allY) return 1;

            // check column
            allX = true;
            allY = true;
            for (int i = 0; i < 4; i++)
            {
                allX = allX && (map[y, i] == 'X' || map[y, i] == 'T');
                allY = allY && (map[y, i] == 'O' || map[y, i] == 'T');
            }

            if (allX) return 0;
            if (allY) return 1;

            // check diagonal1
            if ((x == 0 || x == 4) && (y == 0 || y == 4))
            {
                allX = true;
                allY = true;
                for (int i = 0; i < 4; i++)
                {
                    allX = allX && (map[i, i] == 'X' || map[i, i] == 'T');
                    allY = allY && (map[i, i] == 'O' || map[i, i] == 'T');
                }

                if (allX) return 0;
                if (allY) return 1;
            }

            // check rev. diagonal
            if ((x == 0 || x == 4) && (y == 0 || y == 4))
            {
                allX = true;
                allY = true;
                for (int i = 0; i < 4; i++)
                {
                    allX = allX && (map[i, 3-i] == 'X' || map[i, 3-i] == 'T');
                    allY = allY && (map[i, 3-i] == 'O' || map[i, 3-i] == 'T');
                }

                if (allX) return 0;
                if (allY) return 1;
            }

            return 2;
        }
    }
}
