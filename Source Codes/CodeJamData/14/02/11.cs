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
            string[] parts = cas.input.Split(' ');
            Decimal C = Decimal.Parse(parts[0]);
            Decimal F = Decimal.Parse(parts[1]);
            Decimal X = Decimal.Parse(parts[2]);

            bool createNewFarm = false;
            Decimal currentTakenSeconds = 0;
            Decimal rate = 2;
            do
            {
                createNewFarm = X / rate > C / rate + X / (rate + F);
                if (createNewFarm)
                {
                    currentTakenSeconds += C / rate;
                    rate += F;
                }
                else
                    currentTakenSeconds += X / rate;
            } while (createNewFarm);
            cas.output = Math.Round(currentTakenSeconds, 7) + "";
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
            public string input;
            public string output;

            public static Case[] parseinput(string input)
            {
                string[] lines = input.Trim().Split('\n').Select(l => l.TrimEnd('\r')).ToArray();

                long nbCases = Convert.ToInt64(lines[0]);
                long linesPerCase = (lines.Length - 1) / nbCases;

                Case[] cases = new Case[nbCases];

                for (int i = 0; i < nbCases; i++)
                {
                    var caseLine = i * linesPerCase + 1;
                    Case newcase = new Case { input = lines[caseLine] };
                    cases[i] = newcase;
                }
                return cases;
            }
        }
    }

}

