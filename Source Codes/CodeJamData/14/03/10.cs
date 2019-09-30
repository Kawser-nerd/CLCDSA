using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam
{

    class Solver
    {

        static string printArray(char[,] charArray, bool transpose)
        {
            StringBuilder sb = new StringBuilder();
            int iDimension = transpose ? 0 : 1;
            int jDimension = transpose ? 1 : 0;
            for (int i = 0; i < charArray.GetLength(iDimension); i++)
            {
                sb.AppendLine();
                for (int j = 0; j < charArray.GetLength(jDimension); j++)
                {
                    if (transpose)
                        sb.Append(charArray[i, j]);
                    else
                        sb.Append(charArray[j, i]);
                }
            }
            return sb.ToString();
        }

        static string getValidOutput(int R, int C, int M)
        {
            char[,] charArray;
            bool transpose = false;
            if (R == 1 || C == 1)
            {
                charArray = new char[R * C, 1];
                int i = 0;
                for (i = 0; i < M; i++)
                {
                    charArray[i, 0] = '*';
                }
                for (int j = i; j < R * C; j++)
                    charArray[j, 0] = '.';
                charArray[R * C - 1, 0] = 'c';
                transpose = C == 1;
            }
            else
            {
                charArray = new char[C, R];
                int j = 0;
                int i = 0;
                for (i = 0; i < R; i++)
                {
                    for (j = 0; j < C; j++)
                    {
                        charArray[j, i] = '*';
                    }
                }
                int emptyCells2add = R * C - M;
                j = R - 1;
                i = 0;

                for (i = 0; i < C; i++)
                {
                    charArray[i, j] = '.';
                    charArray[i, j - 1] = '.';
                    emptyCells2add -= 2;
                    if (emptyCells2add == 3 || emptyCells2add == 0)
                        break;
                }
                j -= 2;
                i = 0;
                while (emptyCells2add > 0)
                {
                    charArray[i, j] = '.';
                    emptyCells2add--;
                    if (i == C - 1 ||
                        i == C - 2 && emptyCells2add == 2)
                    {
                        i = 0;
                        j--;
                    }
                    else
                        i++;

                }
                charArray[0, R - 1] = 'c';
            }

            return printArray(charArray, transpose);

        }

        static void processCase(Case cas)
        {
            int R = cas.input[0];
            int C = cas.input[1];
            int M = cas.input[2];
            int cells = R * C;

            int emptyCells = cells - M;
            bool isValid = emptyCells == 1;
            if (M==0)
                isValid = true;
            else if (emptyCells == 1)
                isValid = true;
            else
            {
                if (R == 1 || C == 1)
                    isValid = emptyCells >= 2;
                else if (R == 2 || C == 2)
                    isValid = emptyCells % 2 == 0 && emptyCells>=4;
                else
                    isValid = emptyCells == 4 || emptyCells == 6 || emptyCells >= 8;
            }

            if (isValid)
                cas.output = getValidOutput(R, C, M);
            else
                cas.output = "\r\nImpossible";
        }


        public static string Solve(string input)
        {
            Case[] cases = Case.parseinput(input);
            for (int i = 0; i < cases.Length; i++)
            {
                Console.WriteLine("Case: " + i);
                processCase(cases[i]);
            }
            return writeOutput(cases);
        }

        static string writeOutput(Case[] cases)
        {
            var sb = new StringBuilder();
            for (var i = 0; i < cases.Length; i++)
            {
                sb.AppendLine("Case #" + (i + 1) + ": " + cases[i].output);

            }
            return sb.ToString(); ;
        }

        class Case
        {
            public int[] input;
            public string output;

            public static Case[] parseinput(string input)
            {
                string[] lines = input.Trim().Split('\n').Select(l => l.TrimEnd('\r')).ToArray();

                long nbCases = Convert.ToInt64(lines[0]);
                Case[] cases = new Case[nbCases];

                for (int i = 0; i < nbCases; i++)
                {
                    var caseLine = i + 1;
                    var lineParts = lines[caseLine].Split(' ');
                    Case newcase = new Case { input = lineParts.Select(n => Convert.ToInt32(n)).ToArray() };
                    cases[i] = newcase;
                }
                return cases;
            }
        }
    }

}

