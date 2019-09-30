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
        static int getDeceitfulWarPoints(List<decimal> naomis, List<decimal> kens)
        {
            int wons = 0;
            while (naomis.Count > 0)
            {
                if (naomis[naomis.Count - 1] > kens[naomis.Count - 1])
                {
                    var kensSmallest = kens[0];
                    kens.RemoveAt(0);
                    var smallWinNaomis = naomis.FindIndex(0, n => n > kensSmallest);
                    naomis.RemoveAt(smallWinNaomis);
                    wons++;
                }
                else
                {
                    kens.RemoveAt(naomis.Count - 1);
                    naomis.RemoveAt(0);
                }
               
            }
            return wons;
        }

        static int getWarPoints(List<decimal> naomis, List<decimal> kens)
        {
            int wons = 0;
            while (naomis.Count > 0)
            {
                if (naomis[naomis.Count - 1] > kens[naomis.Count - 1])
                {
                    kens.RemoveAt(0);
                    wons++;
                }
                else
                {
                    kens.RemoveAt(naomis.Count - 1);
                }
                naomis.RemoveAt(naomis.Count - 1);
            }
            return wons;
        }

        static void processCase(Case cas)
        {
            List<decimal> naomis = new List<decimal>(cas.input[0]);
            List<decimal> kens = new List<decimal>(cas.input[1]);
            naomis.Sort();
            kens.Sort();
            int warPoints = getWarPoints(new List<decimal>(naomis.ToArray()), new List<decimal>(kens.ToArray()));
            int deceitfulWarPoints = getDeceitfulWarPoints(naomis, kens);
            cas.output = deceitfulWarPoints + " " + warPoints;
            //cas.output = "\r\n" + string.Join(", ", naomis) + "\r\n" + string.Join(", ", kens);
                
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
            public decimal[][] input;
            public string output;

            public static Case[] parseinput(string input)
            {
                string[] lines = input.Trim().Split('\n');

                int nbCases = Convert.ToInt32(lines[0]);
                Case[] cases = new Case[nbCases];

                int iLine = 1;
                for (int i = 0; i < nbCases; i++)
                {
                    Case newcase = new Case { input = new decimal[2][] };

                    for (var caseLine = 0; caseLine < 2; caseLine++)
                    {
                        iLine++;
                        var lineParts = lines[iLine].Split(' ');
                        var linePartsDec = lineParts.Select(p => Decimal.Parse(p)).ToArray();
                        newcase.input[caseLine] = linePartsDec;
                    }
                    cases[i] = newcase;
                    iLine++;
                }
                return cases;
            }
        }
    }

}

