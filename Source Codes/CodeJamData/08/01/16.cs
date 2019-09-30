using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace CodeJam2008
{
    class Program
    {
        static int findQuery(string[] queries, int startIndex, string name)
        {
            int i = startIndex;
            while (i < queries.Length && queries[i] != name) ++i;
            return i;
        }

        static int Solve(string[] engines, string[] queries)
        {
            int switchCount = 0;
            int batchStart = 0;
            while (batchStart < queries.Length)
            {
                int bestEngine = 0;
                int bestBatchEnd = findQuery(queries, batchStart, engines[0]);
                for (int i = 1; i < engines.Length; ++i)
                {
                    int batchEnd = findQuery(queries, batchStart, engines[i]);
                    if (batchEnd > bestBatchEnd)
                    {
                        bestBatchEnd = batchEnd;
                        bestEngine = i;
                    }
                }
                batchStart = bestBatchEnd;
                if (batchStart < queries.Length)
                    switchCount++;
            }
            return switchCount;
        }

        static void Main(string[] args)
        {
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\CodeJam2008\Data\";
            StreamReader sr = File.OpenText(DataFolder + "A-large.in");
            using (StreamWriter sw = File.CreateText(DataFolder + "A-large.out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int i = 0; i < caseCount; ++i)
                {
                    int sCount = int.Parse(sr.ReadLine());
                    string[] engines = new string[sCount];
                    for (int j = 0; j < sCount; ++j)
                        engines[j] = sr.ReadLine();
                    int qCount = int.Parse(sr.ReadLine());
                    string[] queries = new string[qCount];
                    for (int j = 0; j < qCount; ++j)
                        queries[j] = sr.ReadLine();

                    sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solve(engines, queries));
                }
            }
        }
    }
}
