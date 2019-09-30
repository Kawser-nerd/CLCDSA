using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Program2
{
    class Program
    {
        public static void DecideWinner(string input, string RedWinString, string BlueWinString, ref bool redWin, ref bool blueWin)
        {

            if (!redWin)
            {
                if (input.IndexOf(RedWinString) >= 0)
                    redWin = true;
            }

            if (!blueWin)
            {
                if (input.IndexOf(BlueWinString) >= 0)
                    blueWin = true;
            }
        }

        public static void FindWiner(string[] matrix, int n, int winStrike, ref bool redWin, ref bool blueWin)
        {
            string RedWinString = string.Empty;
            string BlueWinString = string.Empty;

            for (int i = 0; i < winStrike; ++i)
            {
                RedWinString += "R";
                BlueWinString += "B";
            }

            for (int i = 0; i < n; ++i)
            {
                DecideWinner(matrix[i], RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }

            for (int i = 0; i < n; ++i)
            {
                string tmp = string.Empty;

                for (int k = 0; k < n; ++k)
                    tmp += matrix[k][i];

                DecideWinner(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }

            for (int i = 0; i < n; ++i)
            {
                int j = 0;
                int k = n - i - 1;
                string tmp = matrix[j][k].ToString();

                ++j;
                ++k;

                while ((j < n) && (k < n))
                {
                    tmp += matrix[j][k];
                    ++j;
                    ++k;
                }

                DecideWinner(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }

            for (int i = 1; i < n; ++i)
            {
                int j = i;
                int k = 0;
                string tmp = matrix[j][k].ToString();

                ++j;
                ++k;

                while ((j < n) && (k < n))
                {
                    tmp += matrix[j][k];
                    ++j;
                    ++k;
                }

                DecideWinner(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }


            for (int i = 0; i < n; ++i)
            {
                int j = 0;
                int k = i;
                string tmp = matrix[j][k].ToString();

                ++j;
                --k;

                while ((k >= 0) && (j < n))
                {
                    tmp += matrix[j][k];
                    ++j;
                    --k;
                }

                DecideWinner(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }


            for (int i = 1; i < n; ++i)
            {
                int j = i;
                int k = n - 1;
                string tmp = matrix[j][k].ToString();

                ++j;
                --k;

                while ((k >= 0) && (j < n))
                {
                    tmp += matrix[j][k];
                    ++j;
                    --k;
                }

                DecideWinner(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }


        }

        static void Main(string[] args)
        {
            int t = 0;
            int n = 0;
            int winStrike = 0;
            int caseCount = 0;

            StreamReader sr = new StreamReader(@"A-large.in");
            StreamWriter sw = new StreamWriter(@"Out_large.txt");

            string line = sr.ReadLine();

            t = Int32.Parse(line);

            for (int i = 0; i < t; ++i)
            {
                line = sr.ReadLine();

                string[] values = line.Split();

                n = Int32.Parse(values[0]);
                winStrike = Int32.Parse(values[1]);

                string[] matrix = new string[n];

                for (int j = 0; j < n; ++j)
                {
                    matrix[j] = (sr.ReadLine()).Replace(".", "");

                    int len = matrix[j].Length;

                    for (int k = 0; k < n - len; ++k)
                        matrix[j] = "." + matrix[j];

                }

                bool redWin = false;
                bool blueWin = false;

                FindWiner(matrix, n, winStrike, ref redWin, ref blueWin);

                caseCount++;
                string winner = "Neither";

                if (redWin & blueWin)
                    winner = "Both";
                else if (redWin)
                    winner = "Red";
                else if (blueWin)
                    winner = "Blue";

                sw.WriteLine("Case #" + caseCount + ": " + winner);


            }
            sw.Close();
        }

    }

}
