using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SavingTheUniverse
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputFile = args[0];
            string outputFile = args[1];

            (new SavingTheUniverse()).Solve(inputFile, outputFile);
        }
    }

    class SavingTheUniverse
    {
        private StreamWriter sw;
        private StreamReader sr;
        int currentTestCase;

        public void Solve
            (
            string inputFile,
            string outputFile
            )
        {
            using (sw = new StreamWriter(outputFile))
            {
                using (sr = new StreamReader(inputFile))
                {
                    int numberOfCases = int.Parse(sr.ReadLine());

                    for (currentTestCase = 1; currentTestCase <= numberOfCases; currentTestCase++)
                    {
                        SolveTestCase();
                    }
                }
            }
        }

        private void SolveTestCase()
        {
            int numberOfSearchEngines = int.Parse(sr.ReadLine());

            for (int i = 0 ; i < numberOfSearchEngines ; i++)
            {
                sr.ReadLine();
            }

            int numberOfQueries = int.Parse(sr.ReadLine());
            int numberOfSearchEngineSwitches = 0;
            Dictionary<string,bool> queries = new Dictionary<string,bool>();

            while (numberOfQueries > 0)
            {
                string query = sr.ReadLine();
                numberOfQueries--;

                queries[query] = true;

                if (queries.Count == numberOfSearchEngines)
                {
                    // Oops, we just used up our last search engine.  No good.
                    // We have to switch search engines now.
                    numberOfSearchEngineSwitches++;
                    queries.Clear();
                    queries[query] = true;
                }
            }            

            string answer = String.Format("Case #{0}: {1}", currentTestCase, numberOfSearchEngineSwitches);
            
            sw.WriteLine(answer);
            Console.WriteLine(answer);
        }
    }
}
