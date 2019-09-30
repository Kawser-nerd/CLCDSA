using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace SavingUniverse
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\Patrick\Desktop\a-large.in"))
//            using (StreamReader sr = new StreamReader(@"C:\Users\Patrick\Desktop\A-small-attempt0.in"))
//            using (StreamReader sr = new StreamReader(@"C:\Users\Patrick\Desktop\A-small-attempt1.in"))
            using (StreamWriter sw = new StreamWriter(@"C:\Users\Patrick\Desktop\output.txt"))
            {
                int cases = int.Parse(sr.ReadLine());
                for (int i = 0; i < cases; i++)
                    sw.WriteLine("Case #{0}: {1}", i + 1, SolveCase(sr));
            }
        }

        private static int SolveCase(StreamReader sr)
        {
            string[] engines = new string[int.Parse(sr.ReadLine())];
            for (int i = 0; i < engines.Length; i++)
                engines[i] = sr.ReadLine();

            string[] queries = new string[int.Parse(sr.ReadLine())];
            for (int i = 0; i < queries.Length; i++)
                queries[i] = sr.ReadLine();


            List<string> enginesList = new List<string>(engines);
            bool[] engineFound = new bool[engines.Length];
            int totalEnginesFound = 0;
            int enginesUsed = 0;

            for (int i = 0; i < queries.Length; i++)
            {
                var query = queries[i];

                if (enginesList.Contains(query))
                {
                    if (totalEnginesFound == engines.Length - 1 && ! engineFound[enginesList.IndexOf(query)])
                    {
                        engineFound = new bool[engines.Length];
                        totalEnginesFound = 0;
                        enginesUsed += 1;
                    }
                    
                    if (!engineFound[enginesList.IndexOf(query)])
                        totalEnginesFound += 1;
                    
                    engineFound[enginesList.IndexOf(query)] = true;
                }

            }

            return enginesUsed;
        }
    }
}
