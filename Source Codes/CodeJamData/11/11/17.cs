using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FreeCellStatistics
{
    class Program
    {
        static void Main(string[] args)
        {

            string inputFileName = args[0];
            string outputFileName = "res.txt";

            string[] inputsLine = File.ReadAllLines(inputFileName);



            int nbProblem = int.Parse(inputsLine[0]);

            string[] formatedRes = new string[nbProblem];

            for (int i = 0; i < nbProblem; i++)
            {
                long N;
                int pd;
                int pg;
                ParseProblem(inputsLine[i + 1], out N, out pd, out pg);
                bool res = Solve(N, pd, pg);
                formatedRes[i] = string.Format("Case #{0}: {1}", i + 1, res ? "Possible" : "Broken");

            }


            File.WriteAllLines(outputFileName, formatedRes);


        }


        static bool Solve(long N, int pd, int pg)
        {

            if (pg == 100)
            {
                return pd == 100;
            }
            if (pg == 0 && pd != 0)
            {
                return pd == 0;
            }

            long sum = pd;
            bool ok = false;
            long i = 0;
            while (!ok && i < N)
            {
                long reste;
                Math.DivRem(sum, 100, out reste);
                ok = reste == 0;
                i++;
                sum += pd;
            }

            return ok;

        }

        private static void ParseProblem(string inputLine, out long N, out int pd, out int pg)
        {
            string[] words = inputLine.Split(' ');

            N = long.Parse(words[0]);
            pd = int.Parse(words[1]);
            pg = int.Parse(words[2]);
        }
    }
}
