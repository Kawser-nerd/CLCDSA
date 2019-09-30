using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Globalization;

namespace Round1BProblemA
{
    class R1B_ProblemA
    {
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2012\Round1BProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split();
                    int N = int.Parse(s[0]);
                    Debug.Assert(N + 1 == s.Length);
                    int[] J = new int[N];
                    int[] stat = new int[101];
                    int sum = 0;
                    for (int i = 0; i < N; ++i)
                    {
                        J[i] = int.Parse(s[i + 1]);
                        stat[J[i]]++;
                        sum += J[i];
                    }
                    int nCount = 0;
                    int delta = 0;
                    int val = 0;
                    while (delta < sum && val <= 100)
                    {
                        nCount += stat[val];
                        delta += nCount;
                        val++;
                    }
                    double level = val + ((sum - delta) / (double)nCount);
                    sw.Write("Case #" + caseNumber.ToString() + ":");
                    for (int i = 0; i < N; ++i)
                    {
                        double p = (J[i] >= level) ? 0 : ((double)(level - J[i]) * 100) / sum;
                        sw.Write(" " + p.ToString("F8", CultureInfo.InvariantCulture));
                    }
                    sw.WriteLine();
                }
            }
        }
    }
}
