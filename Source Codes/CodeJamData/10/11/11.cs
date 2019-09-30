using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam1A
{
    class codejam1a
    {
        static void Main(string[] args)
        {
            string fileName = "A-large.in";
            int numberOfCases = 0;
            int numberOfSide = 0;
            int winStrike = 0;
            int caseCount = 0;

            using (StreamReader input = new StreamReader(fileName))
            {
                string line = input.ReadLine();

                numberOfCases = Int32.Parse(line);

                for (int i = 0; i < numberOfCases; ++i)
                {
                    line = input.ReadLine();

                    string[] values = line.Split();

                    numberOfSide = Int32.Parse(values[0]);
                    winStrike = Int32.Parse(values[1]);

                    string[] matrix = new string[numberOfSide];

                    for (int j = 0; j < numberOfSide; ++j)
                    {
                        matrix[j] = (input.ReadLine()).Replace(".", "");

                        int len = matrix[j].Length;

                        for (int k = 0; k < numberOfSide - len; ++k)
                            matrix[j] = "." + matrix[j];

                   }

                    bool redWin = false;
                    bool blueWin = false;

                    FindWiner(matrix, numberOfSide, winStrike, ref redWin, ref blueWin);

                    caseCount++;

                    Console.WriteLine("Case #" + caseCount + ": " + getWinner(redWin, blueWin));

                }
            }
        }

        public static string getWinner(bool redWin, bool blueWin)
        {
            if (redWin & blueWin)
                return "Both";
            else if (redWin)
                return "Red";
            else if (blueWin)
                return "Blue";

            return "Neither";
        }

        public static void FindWiner(string[] matrix, int numberOfSide, int winStrike, ref bool redWin, ref bool blueWin)
        {
            //string[] searchString = BuildString(matrix, numberOfSide);

            string RedWinString = string.Empty;
            string BlueWinString = string.Empty;

            for (int i=0; i<winStrike; ++i)
            {
                RedWinString += "R"; 
                BlueWinString += "B"; 
            }

            for (int i= 0; i< numberOfSide ; ++i)
            {
                WhoWin(matrix[i], RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin&&blueWin)
                    return;
            }

            for (int i= 0; i< numberOfSide ; ++i)
            {
                string tmp = string.Empty;

                for(int k=0; k< numberOfSide; ++k)
                    tmp += matrix[k][i];

                WhoWin(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin&&blueWin)
                    return;
            }

            for (int i=0; i<numberOfSide; ++i)
            {
                int j = 0;
                int k = numberOfSide - i - 1;
                string tmp = matrix[j][k].ToString();

                ++j;
                ++k;

                while ((j < numberOfSide) && (k < numberOfSide))
                {
                    tmp += matrix[j][k];
                    ++j;
                    ++k;
                }

                WhoWin(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }

            for (int i = 1; i < numberOfSide; ++i)
            {
                int j = i;
                int k = 0;
                string tmp = matrix[j][k].ToString();

                ++j;
                ++k;

                while ((j < numberOfSide) && (k < numberOfSide))
                {
                    tmp += matrix[j][k];
                    ++j;
                    ++k;
                }

                WhoWin(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }


            for (int i = 0; i < numberOfSide; ++i)
            {
                int j = 0;
                int k = i;
                string tmp = matrix[j][k].ToString();

                ++j;
                --k;

                while ((k >= 0) && (j < numberOfSide))
                {
                    tmp += matrix[j][k];
                    ++j;
                    --k;
                }

                WhoWin(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }


            for (int i = 1; i < numberOfSide; ++i)
            {
                int j = i;
                int k = numberOfSide -1 ;
                string tmp = matrix[j][k].ToString();

                ++j;
                --k;

                while ((k >= 0) && (j < numberOfSide))
                {
                    tmp += matrix[j][k];
                    ++j;
                    --k;
                }

                WhoWin(tmp, RedWinString, BlueWinString, ref redWin, ref blueWin);

                if (redWin && blueWin)
                    return;
            }


        }

        public static void WhoWin(string input, string RedWinString, string BlueWinString, ref bool redWin, ref bool blueWin)
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

        public static string[] BuildString(string[] matrix, int numberOfSide)
        {
            string[] searchString = new string[numberOfSide * 6 - 2];

            return searchString;
        }
    }

}
