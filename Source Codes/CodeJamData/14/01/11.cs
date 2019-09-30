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
        static void processCase(Case cas)
        {
            int[] firstSelectedRow = cas.input[cas.input[0][0]];
            int[] secondSelectedRow = cas.input[cas.input[5][0] + 5];

            int[] intersect = firstSelectedRow.Intersect(secondSelectedRow).ToArray();
            if (intersect.Length == 1)
                cas.output = intersect[0] + "";
            else if (intersect.Length == 0)
                cas.output = "Volunteer cheated!";
            else
                cas.output = "Bad magician!";
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
            public int[][] input;
            public string output;

            public static Case[] parseinput(string input)
            {
                string[] lines = input.Trim().Split('\n');

                int nbCases = Convert.ToInt32(lines[0]);
                Case[] cases = new Case[nbCases];

                int iLine = 1;
                for (int i = 0; i < nbCases; i++)
                {
                    string[] lineParts = lines[iLine].Split(' ');
                    int[] linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();

                    int caseLines = 9;
                    Case newcase = new Case { input = new int[caseLines + 1][] };
                    newcase.input[0] = linePartsint;

                    for (var caseLine = 0; caseLine < caseLines; caseLine++)
                    {
                        iLine++;
                        lineParts = lines[iLine].Split(' ');
                        linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();
                        newcase.input[caseLine + 1] = linePartsint;
                    }
                    cases[i] = newcase;
                    iLine++;
                }
                return cases;
            }
        }
    }

}

